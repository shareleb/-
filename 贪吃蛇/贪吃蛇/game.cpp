#include<iostream>
#include<vector>
#include"wall.h"
#include"snake.h"
#include"food.h"
#include<ctime>
#include<conio.h>
#include<Windows.h>
using  namespace std;

//在#include<Windows.h> 里  只要会用就行了，不用记  ，直接用  控制光标定位
void gotoxy(HANDLE hOut, int x, int y)
{
	COORD pos;
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOut, pos);

}

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);//定义显示器句柄变量。



int main()
{
	//添加随机种子。
	srand((unsigned)time(NULL));
	
	//是否死亡标识。
	bool isDead = false;
	char preKey = NULL;

	Wall wall;
	wall.initWall();
	wall.drawWall();

	Food food(wall);
	food.setFood();
	Snake snake(wall,food);
	snake.initSnake();
	/*snake.move('w');
	snake.move('w');
	snake.move('a');*/

	gotoxy(hOut, 0, Wall::ROW);
	cout << "得分：" << snake.getScore() << "分" << endl;
	

	//gotoxy(hOut,10, 5);


	//接收用户的输入
	while (true)
	{
		char key = _getch();
		//判断如果是第一次按了左键， 不能激活游戏
		//判断上一次移动方向，
		if (preKey==NULL&&key == snake.LEFT)
		{
			continue;
		}
		do
		{
			if (key == snake.UP || key == snake.DOWN || key == snake.LEFT || key == snake.RIGHT)
			{
				//判断本次按键是否与上次冲突
				if (key == snake.LEFT&&preKey == snake.RIGHT ||
					key == snake.RIGHT&&preKey == snake.LEFT ||
					key == snake.UP&&preKey == snake.DOWN ||
					key == snake.DOWN&&preKey == snake.UP)
				{
					key = preKey;   // 
				}
				else
				{
					preKey = key;   //不冲突可以更新按键
				}
				
				if (snake.move(key) == true)
				{
					//移动成功 代码
				//	system("cls");
					//wall.drawWall();
					gotoxy(hOut, 0, Wall::ROW);

					cout << "得分：" << snake.getScore() << "分" << endl;
					Sleep(snake.getSleepTime());     //毫秒
					
				}
				else
				{
					isDead = true;
					break;
				}

			}
			else
			{
				key = preKey;    //强制将错误按键变成了 上一次移动的方向。
			}

		} while (!_kbhit());   //当没有键盘输入的时候，返回0
		if (isDead == true)
		{
			break;
		}
	}
	

	////测试。
	//wall.setWall(5, 4, '=');
	//wall.setWall(5, 5, '=');
	//wall.setWall(5, 6, '@');

	system("pause");
	return EXIT_SUCCESS;
}