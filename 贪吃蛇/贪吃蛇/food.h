#pragma once
#include<iostream>
#include"wall.h"
using namespace std;


class Food
{
	int foodX;
	int foodY;
	Wall & wall;
public:

	Food(Wall & tempWall);

	//…Ë÷√ ≥ŒÔ
	void setFood();
	
};
