#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "Mover_bug.h"
#include "Attractor_bug.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

Mover_bug m[5];

float attractor_size = 10;

Attractor_bug a(vec(0, 0, 0), attractor_size);

vec gravity(0, -0.01, 0);
vec wind(0.005, 0, 0);

ostream & operator<<(ostream & os, vec & v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

void applyGravity(Mover_bug& _m) {
	_m.applyForce(gravity);
}

void applyWind(Mover_bug& _m) {
	_m.applyForce(wind);
}

void applyAttraction(Mover_bug& _m) {
	vec force = a.attract(_m);
	_m.applyForce(force);
}

void applyForces(Mover_bug& _m) {
	applyGravity(_m);
	applyWind(_m);
	applyAttraction(_m);
}

void setup()
{

}

void update(int value)
{
	for (int i = 0; i < 5; i++) {
		applyForces(m[i]);
		m[i].update();
	}

	// m.edges();
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{

	for (Mover_bug n : m) {
		n.display();
	}

	a.display();

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
