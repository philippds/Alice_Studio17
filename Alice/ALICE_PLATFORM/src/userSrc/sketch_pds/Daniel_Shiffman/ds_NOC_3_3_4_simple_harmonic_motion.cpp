#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

#define x_spacing 8
#define max_waves 5

#define w 200
#define y_values_size (w / x_spacing)

float y_values[y_values_size];
float theta;
float amplitude[max_waves];
float dx[max_waves];

void setup()
{
	theta = 0.0;

	for (int i = 0; i < max_waves; i++)
	{
		amplitude[i] = ofRandom(-50, 50);
		float period = ofRandom(0,300);
		dx[i] = (TWO_PI / period) * x_spacing;
	}
}

void update(int value)
{
	theta += 0.02;

	for (int i = 0; i < y_values_size; i++)
	{
		y_values[i] = 0.0;
	}

	for (int j = 0; j < max_waves; j++)
	{
		float x = theta;
		for (int i = 0; i < y_values_size; i++)
		{
			if (j % 2 == 0)
			{
				y_values[i] += sin(x) * amplitude[j];
			}
			else
			{
				y_values[i] += cos(x) * amplitude[j];
			}
			x += dx[j];
		}
	}
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (int i = 0; i < y_values_size; i++)
	{
		glColor3d(0, 0, 0);
		glLineWidth(3);
		drawCircle(vec(i * x_spacing - 100, y_values[i], 0), 10, 100);
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
