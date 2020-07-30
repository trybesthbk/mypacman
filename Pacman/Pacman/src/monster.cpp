#include "monster.h"
#include "main.h"
//绘画怪物
void drawMonster(float positionX, float positionY, float r, float g, float b){
	int x, y;
	glBegin(GL_LINES);
	glColor3f(r, g, b);
	//头
	for (int k = 0; k < 32; k++){
		x = (float)k / 2.0 * cos(360 * M_PI / 180.0) + (positionX*squareSize);
		y = (float)k / 2.0* sin(360 * M_PI / 180.0) + (positionY*squareSize);
		for (int i = 180; i <= 360; i++){
			glVertex2f(x, y);
			x = (float)k / 2.0 * cos(i * M_PI / 180.0) + (positionX*squareSize);
			y = (float)k / 2.0* sin(i * M_PI / 180.0) + (positionY*squareSize);
			glVertex2f(x, y);
		}
	}
	glEnd();	
	//身体
	glRectf((positionX*squareSize) - 16, positionY*squareSize, (positionX*squareSize) + 15, (positionY*squareSize) + 16);
	glBegin(GL_POINTS);
	glColor3f(0, 0.2, 0.4);
	//眼睛和退
	glVertex2f((positionX*squareSize) - 11, (positionY*squareSize) + 14); //legs
	glVertex2f((positionX*squareSize) - 1, (positionY*squareSize) + 14); //legs
	glVertex2f((positionX*squareSize) + 8, (positionY*squareSize) + 14); //legs
	glVertex2f((positionX*squareSize) + 4, (positionY*squareSize) - 3); //eyes
	glVertex2f((positionX*squareSize) - 7, (positionY*squareSize) - 3); //eyes 
	glEnd();
}

//怪物移动
void updateMonster(float* monster, int id){
		//找到当前位置
		int x1Quadrant = (int)((monster[0] - (2/squareSize)) - 16.0  / squareSize);
		int x2Quadrant = (int)((monster[0] + (2/squareSize)) + 16.0  / squareSize);
		int y1Quadrant = (int)((monster[1] - (2/squareSize)) - 16.0  / squareSize);
		int y2Quadrant = (int)((monster[1] + (2/squareSize)) + 16.0  / squareSize);
		//怪物移动和撞墙检测
		switch ((int)monster[2]){
		case 1:
			if (!bitmap.at(x1Quadrant).at((int)(monster[1]-12/squareSize))&&\
				!bitmap.at(x1Quadrant).at((int)(monster[1]+12/squareSize))){   //如果没撞到墙就继续走
				monster[0] -=  monspeed[id] / squareSize;
			}else {
				int current = monster[2];
				do{
					monster[2] =  (rand() % 4) + 1;
				} while (current == (int) monster[2]);
			}
			break;
		case 2:
			if (!bitmap.at(x2Quadrant).at((int)(monster[1]-12/squareSize))&&\
				!bitmap.at(x2Quadrant).at((int)(monster[1]+12/squareSize))){
				monster[0] += monspeed[id] / squareSize;
			}
			else {
				int current = monster[2];
				do{
					monster[2] = (rand() % 4) + 1;
				} while (current == (int)monster[2]);
			}
			break;
		case 3:
			if (!bitmap.at((int)(monster[0]-12/squareSize)).at(y1Quadrant)&&\
				!bitmap.at((int)(monster[0]+12/squareSize)).at(y1Quadrant)){
				monster[1] -= monspeed[id] / squareSize;
			}
			else {
				int current = monster[2];
				do{
					monster[2] = (rand() % 4) + 1;
				} while (current == (int)monster[2]);
			}
			break;
		case 4:
			if (!bitmap.at((int)(monster[0]-12/squareSize)).at(y2Quadrant)&&\
				!bitmap.at((int)(monster[0]+12/squareSize)).at(y2Quadrant)){
				monster[1] += monspeed[id] / squareSize;
			}
			else {
				int current = monster[2];
				do{
					monster[2] = (rand() % 4) + 1;
				} while (current == (int)monster[2]);
			}
			break;
		default:
			break;
		}
		if(!(rand()%200)){
				monster[2] =  (rand() % 4) + 1;
				monspeed[id-1]=rand()%10*0.1;
			}
}