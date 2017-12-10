#define _MAIN_
#ifdef _MAIN_

#include "main.h"
//#include "MODEL.h"
//#include <array>
//#include <memory>
//#include <time.h>
//#include <experimental/generator>
///
//#include <iostream>
#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

float x = 0;
float y = 0;

void setup()
{

}

void update(int value)
{
	y = int(ofRandom(-20, 20));
	x += ofMap(y, -20, 20, -1, 1);
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	glPointSize(10);
	glColor3f(1, 0, 0);
	drawPoint(vec(x, 0, 0));

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
