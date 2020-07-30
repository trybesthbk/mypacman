#include "gamestart.h"
#include "monster.h"
#include "createpacman.h"
#include "laberynth.h"
#include "main.h"
#include "gameover.h"
#include "food.h"
#include "gameresult.h"
#include "control.h"

//欢迎界面
void welcomeScreen(){
	glClearColor(0, 0.2, 0.4, 1.0);  //RGBA背景配色
	string message = "*************************************";
	string::iterator it = message.begin();
	glRasterPos2f(150, 200);        //设置显示位置
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
		//显示字符
	message = "Pacman - by shiyanlou";
	glColor3f(1, 1, 1);
	glRasterPos2f(225, 250);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "*************************************";
	glRasterPos2f(150, 300);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *it++);
	message = "To control Pacman use A to go right, D to go left, W to go up and S to go down.";
	glRasterPos2f(50, 400);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
	message = "To start or restart the game, press the space key.";
	glRasterPos2f(170, 450);
	it = message.begin();
	while (it!=message.end())
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *it++);
}

//显示屏幕和元素
void display(){
	if (points == 1){
		over = false;  
	}
	keyOperations();
	glClear(GL_COLOR_BUFFER_BIT);//清除颜色缓冲区(当前被激活为写操作的颜色缓存)
	gameOver();  //判断游戏是否结束
	if (replay){   //如果游戏启动了
		if (!over){      //还未结束
			drawLaberynth();     //画出障碍物
			drawFood((1.5 + xIncrement) * squareSize, (1.5 + yIncrement) * squareSize);
			//画出食物
			drawPacman(1.5 + xIncrement, 1.5 + yIncrement, rotation);
			//画出人物
			if(!monsterdie[0]){
				updateMonster(monster1, 0);	//更新怪物位置
				drawMonster(monster1[0], monster1[1], 0.0, 1.0, 1.0); //cyan //画出怪物
			}
			if(!monsterdie[1]){
				updateMonster(monster2, 1);
				drawMonster(monster2[0], monster2[1], 1.0, 0.0, 0.0); //red
			}
			if(!monsterdie[2]){
				updateMonster(monster3, 2);
				drawMonster(monster3[0], monster3[1], 1.0, 0.0, 0.6); //magenta
			}
			if(!monsterdie[3]){
				updateMonster(monster4, 3);
				drawMonster(monster4[0], monster4[1], 0 , 1, 0); //orange
			}
			showpoints();
		}
		else {
			resultsDisplay();    //结束
		}
	}
	else {
		welcomeScreen();     //开始
	}
	glutSwapBuffers();    //实现双缓冲，使图案同步出现
}

//重置窗口
void reshape(int w, int h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glOrtho(0, 750, 750, 0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
