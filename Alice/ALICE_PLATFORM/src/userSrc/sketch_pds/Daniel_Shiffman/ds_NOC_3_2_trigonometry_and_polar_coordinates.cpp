#define _MAIN_
#ifdef _MAIN_

#include "main.h"

// globals
float r = 50;
float a = 0.0;

float x;
float y;

float aVel = 0.0;
float aAcc = 0.001;

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

void setup()
{

}

void update(int value)
{
	x = r * cos(a);
	y = r * sin(a);

	a += aVel;
	if (aVel < 0.1) { aVel += aAcc; }
	cout << aVel << endl;
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	glColor3d(0, 0, 0);
	glLineWidth(3);
	drawLine(vec(0, 0, 0), vec(x, y, 0));
	drawCircle(vec(x, y, 0),10,100);
	
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
