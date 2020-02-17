#pragma once
#include"wall.h"
#include"food.h"
#include<iostream>
using namespace std;

class Snake
{


	struct Point
	{
		//数据域；
		int x;
		int y;
		//指针域
		Point * next;
	};
	Point * pHead;
	Wall & wall;
	Food & food;
	bool isRool;  //判断循环的标志
public:

	enum
	{
		UP = 'w', DOWN = 's', LEFT = 'a', RIGHT = 'd'
	};
	//构造函数
	Snake(Wall &tempWall,Food & tempFood);

	//初始化。
	void initSnake();

	//销毁节点
	void  destroyPoint();

	//添加节点
	void addPoint(int x, int y);

	//删除节点
	void delPoint();


	//移动蛇操作
	//返回值代表移动是否成功。
	bool move(char key);



	//设定难度

	//获取刷屏时间
	int getSleepTime();
	//获取蛇身段
	int countList();

	//获取分数
	int getScore();

};
