#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "MODEL.h"
#include <array>
#include <memory>
#include <time.h>
#include <experimental/generator>
///
#include <iostream>
#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

vec pos;
double number;
vector<double> genNum;

default_random_engine generator;
//normal_distribution<> distr(mean, stdev); 
normal_distribution<double> distribution(0, 10);

void setup()
{

}

void update(int value)
{
	number = distribution(generator);
	cout << number << "\n";
	pos.x = number;
	genNum.push_back(number);
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	glPointSize(10);
	glColor3f(1, 0, 0);


	drawPoint(pos);

	/*
	for (int i = 0; i < genNum.size(); i++) {
		pos.x = genNum[i];
		drawPoint(pos);
	}
	*/

	glColor3f(1, 1, 1);
	backGround(0.75);
	drawGrid(20);
}

/////////////////////////// control  ///////////////////////////////////////////

void mousePress(int b, int state, int x, int y)
{
}

void mouseMotion(int x, int y)
{
}

void keyPress(unsigned char k, int xm, int ym)
{
}

#endif // _MAIN_
