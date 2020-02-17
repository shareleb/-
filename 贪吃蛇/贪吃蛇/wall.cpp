#include"wall.h"

void Wall::initWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			//放墙壁
			if (i == 0 || j == 0 || i == ROW - 1 || j == COL - 1)
			{
				gameArray[i][j] = '*';
			}
			else
			{
				gameArray[i][j] = ' ';
			}
		}
	}
}

void  Wall::drawWall()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameArray[i][j]<<' ';
		}
		if (i == 4)
		{
			cout << "老年机贪吃蛇大作战";
		}
		if (i == 5)
		{
			cout << "create by 刘恩博献给刘贝贝的";
		}
		if (i == 6)
		{
			cout << "a :左";
		}
		if (i == 7)
		{
			cout << "d :右";
		}
		if (i == 8)
		{
			cout << "w :上";
		}
		if (i == 9)
		{
			cout << "s :下";
		}
		if (i == 10)
		{
			cout << "版本号 ： leb_1.0";
		}
		cout << endl;
	}
}

void Wall::setWall(int x, int y, char c)
{
	gameArray[x][y] = c;
}

char Wall::getWall(int x, int y)
{
	return gameArray[x][y];
}

