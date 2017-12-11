#define _MAIN_
#ifdef _MAIN_

#include "main.h"
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
	y = int(ofRandom(-10, 10));
	// ofMap(y, -1, 1, -100, 100);
	x += y;
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	glPointSize(10);
	glColor3f(0, 0, 1);
	drawPoint(vec(x, 0, 0));

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
