#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

class harmonic_pendulum
{
public:
	harmonic_pendulum();

	void update();
	void draw();

	int x;
	float angle;

private:	
	float y;
	float amplitude;
};

harmonic_pendulum::harmonic_pendulum()
{
	amplitude = 100;
}

void harmonic_pendulum::update()
{
	y = sin(angle) * amplitude;
	angle += 0.01;
}

void harmonic_pendulum::draw()
{
	glColor3d(0, 0, 0);
	glLineWidth(3);
	drawCircle(vec(x, y, 0), 10, 100);
}

harmonic_pendulum hp[20];

void setup()
{
	for (int i = -10; i < 10; i++)
	{
		hp[i + 10].x = i * 10;
		hp[i + 10].angle = (i + 10) * 0.15;
	}
}

void update(int value)
{
	for (int i = 0; i < 20; i++)
	{
		hp[i].update();
	}
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (int i = 0; i < 20; i++)
	{
		hp[i].draw();
	}

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
