#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

vec pos;
double number;
vector<double> genNum;

default_random_engine generator;
normal_distribution<double> distribution(0, 50);

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
	glColor3f(0, 0, 1);
	drawPoint(pos);

	// background + grid
	glLineWidth(1);
	backGround(1);
	glColor3d(0.75, 0.75, 0.75);
	drawGrid(100);
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
