#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "Mover_rectangle.h"
#include "Attractor.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

Mover m[5];

Attractor a(vec(0, 100, 0), 3);
Attractor b(vec(100, -100, 0), 3);
Attractor c(vec(-100, -100, 0), 3);

vec gravity(0, -0.1, 0);
vec wind(0.05, 0, 0);

ostream & operator<<(ostream & os, vec & v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

void applyGravity(Mover& _m) {
	_m.applyForce(gravity);
}

void applyWind(Mover& _m) {
	_m.applyForce(wind);
}

void applyAttraction(Mover& _m) {
	vec force = a.attract(_m);
	force += b.attract(_m);
	force += c.attract(_m);
	_m.applyForce(force);
}

void applyForces(Mover& _m) {
	//applyGravity(_m);
	//applyWind(_m);
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
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	for (Mover n : m) {
		n.display();
	}

	a.display();
	b.display();
	c.display();

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
