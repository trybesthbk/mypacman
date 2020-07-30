#include "food.h"
#include "main.h"

//检查食物是否被吃
bool foodEaten(int x, int y, float pacmanX, float pacmanY){
	if (x >= pacmanX - 16.0  && x <= pacmanX + 16.0){               //16为吃豆人半径
		if (y >= pacmanY - 16.0&& y <= pacmanY + 16.0){             //检测是否碰到
			return true;
		}
	}
	return false;
}

//画上食物
void drawFood(float pacmanX, float pacmanY){
	deque<float> temp;
	//检查食物是否没有被吃掉
	for (deque<float>::size_type i = 0; i < food.size(); i = i + 2){
		if (!foodEaten(food.at(i)*squareSize, food.at(i + 1)*squareSize, pacmanX, pacmanY)){
			//没吃掉的话列入
			temp.push_back(food.at(i));
			temp.push_back(food.at(i + 1));
		}
		else {
			points++;
			myradius+=0.5;
		}
	}
	food.swap(temp);
	glPointSize(5.0);
	glBegin(GL_POINTS);   //创建点
	glColor3f(1.0, 1.0, 1.0);
	//画上食物
	for (deque<float>::size_type j = 0; j < food.size(); j = j + 2){
		glVertex2f(food.at(j)*squareSize, food.at(j + 1)*squareSize);//画点
	}
	glEnd();
}

void showpoints()
{
	string message = "Point:";
	message+=to_string(points);
	message+="/";
	message+=to_string(maxpoint);
	if(myradius>40)message+="        You can eat monsters now!!";
	string::iterator it = message.begin();
	glColor3f(0, 0, 0);
	glRasterPos2f(50, 30);        //设置显示位置
	while (it!=message.end())
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	//显示字符
}