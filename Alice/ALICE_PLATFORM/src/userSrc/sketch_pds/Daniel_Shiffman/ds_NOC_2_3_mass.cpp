#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "Mover.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////


const int numMover = 5;
Mover m[numMover];
vec gravity(0, -0.01, 0);
vec wind(0.001, 0, 0);

void setup()
{

}

void update(int value)
{
	for (int i = 0; i < numMover; i++) {
		gravity = gravity * m[i].mass;
		m[i].applyForce(gravity);
		gravity = vec(0, -0.01, 0);
		m[i].applyForce(wind);
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
