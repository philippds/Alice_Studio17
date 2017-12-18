#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

#define max_waves 20

float theta = 0.0;
float amplitude[max_waves];
float dx[max_waves];
float yvalues[max_waves];

void setup()
{
	for (int i = 0; i < max_waves; i++)
	{
		amplitude[i] = ofRandom(1, 10);
		float period = ofRandom(100, 300);
		dx[i] = (TWO_PI / period) * 10;
	}
}

void update(int value)
{
	theta += 0.02;

	for (int i = 0; i < max_waves; i++)
	{
		yvalues[i] = 0.0;
	}

	for (int i = 0; i < max_waves; i++)
	{
		float x = theta;
		for (int j = 0; j < max_waves; j++)
		{
			if (i % 2 == 0)
			{
				yvalues[j] += sin(x) * amplitude[i];
			}
			else
			{
				yvalues[j] += cos(x) * amplitude[i];
			}
			x += dx[i];
		}
	}
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (int i = 0; i < max_waves; i++)
	{
		glColor3d(0, 0, 0);
		glLineWidth(3);
		drawCircle(vec(i * 5, yvalues[i], 0), 10, 100);
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
