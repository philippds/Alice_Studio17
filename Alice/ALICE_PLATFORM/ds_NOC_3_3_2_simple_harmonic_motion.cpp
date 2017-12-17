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

private:
	vec angle;
	vec velocity;
	vec amplitude;

	float x;
	float y;
};

harmonic_pendulum::harmonic_pendulum()
{
	angle = vec(0, 0, 0);
	velocity = vec(ofRandom(-0.05, 0.05), ofRandom(-0.05, 0.05), 0);
	amplitude = vec(ofRandom(20, 100 / 2), ofRandom(20, 100 / 2), 0);
}

void harmonic_pendulum::update()
{
	x = sin(angle.x) * amplitude.x;
	y = sin(angle.y) * amplitude.y;
	angle += velocity;
}

void harmonic_pendulum::draw()
{
	glColor3d(0, 0, 0);
	glLineWidth(3);
	drawLine(vec(0, 0, 0), vec(x, y, 0));
	drawCircle(vec(x, y, 0), 10, 100);
}

harmonic_pendulum hp[5];

void setup()
{
}

void update(int value)
{
	for (int i = 0; i < 5; i++)
	{
		hp[i].update();
	}
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (int i = 0; i < 5; i++)
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
