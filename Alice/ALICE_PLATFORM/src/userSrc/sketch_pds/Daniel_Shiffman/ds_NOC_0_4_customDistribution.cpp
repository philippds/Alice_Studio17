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

const int valsSize = 200;
const int width = 20;
float vals[valsSize];

float montecarlo() {
	bool foundone = false;
	int hack = 0;
	while (!foundone && hack < 10000) {
		float r1 = ofRandom(0, 1);
		float r2 = ofRandom(0, 1);
		float y = r1 * r1;
		if (r2 < y) {
			foundone = true;
			return r1;
		}
	}
	hack++;
}

void setup()
{
	for (float i = 0; i < valsSize; i++) {
		float n = montecarlo();
		int index = int(n * width);
		vals[index]++;
	}
}

void update(int value)
{

}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (float i = 0; i < valsSize; i++) {
		drawLine(vec(i, 0, 0), vec(i, vals[int(i)], 0));
	}
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
