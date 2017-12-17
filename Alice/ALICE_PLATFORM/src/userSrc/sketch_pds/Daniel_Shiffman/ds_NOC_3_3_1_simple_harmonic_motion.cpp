#define _MAIN_
#ifdef _MAIN_

#include "main.h"

// globals
float amplitude = 100;
float angle = 0.0;

float x;

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

void setup()
{

}

void update(int value)
{
	x = amplitude * sin(angle);
	angle += 0.05;
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	glColor3d(0, 0, 0);
	glLineWidth(3);
	drawLine(vec(0, 0, 0), vec(x, 0, 0));
	drawCircle(vec(x, 0, 0), 10, 100);

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
