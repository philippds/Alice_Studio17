#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "Mover.h"
//#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

Mover m[10];
vec gravity(0, -0.01, 0);
vec wind(0.001, 0, 0);
vec friction;

void setup()
{


}

void update(int value)
{
	for (int i = 0; i < 10; i++) {
		gravity = gravity * m[i].mass;
		m[i].applyForce(gravity);
		gravity = vec(0, -0.01, 0);
		m[i].applyForce(wind);
		m[i].applyForce(friction);

		m[i].edges();
		m[i].update();
	}
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (Mover n : m) {
		n.display();
	}

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
