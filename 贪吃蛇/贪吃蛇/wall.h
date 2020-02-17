#pragma once

//墙里我们需要维护一个二维数组，对整个游戏中的元素进行设置，所以我们声明一个二维数组，   char GameArray【】【】
//具体行数和列数可以定义出一个枚举，可以设置25,25   enum{ ROW=25,COL=25}
//墙主要的接口。

#include<iostream>
#include<vector>
using  namespace std;

class Wall
{
public:
	//枚举行数，列数。
	enum {
		ROW = 45,
		COL=45
	};
	//初始化墙壁。
	void initWall();
	//画墙壁
	void drawWall();
	//根据索引设置 二维数组的内容。
	void setWall(int x, int y, char c);
	//根据索引来获取当前位置的符号。
	char getWall(int x, int y);


private:

	char gameArray[ROW][COL];


};
