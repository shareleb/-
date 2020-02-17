#include"food.h"
#include<Windows.h>
//在#include<Windows.h> 里  只要会用就行了，不用记  ，直接用  控制光标定位
void gotoxy2(HANDLE hOut2, int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut2, pos);

}
HANDLE hOut2 = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量。
void Food::setFood()
{
	while (true)
	{
		//产生随机数
		foodX = rand() % (Wall::ROW - 2) + 1;
		foodY = rand() % (Wall::COL - 2) + 1;

		//如果随机数的位置是蛇头或者蛇身，就重新生成随机数

		if (wall.getWall(foodX, foodY) == ' ')
		{
			wall.setWall(foodX, foodY, '#');
			gotoxy2(hOut2, foodY * 2, foodX);
			cout << '#';
			break;
		}

	}
	
	
	
	
}

 Food::Food(Wall & tempWall):wall(tempWall)
{
	 
}