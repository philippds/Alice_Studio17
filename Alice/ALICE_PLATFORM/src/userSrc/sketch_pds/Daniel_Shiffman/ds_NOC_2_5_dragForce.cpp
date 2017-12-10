#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "Mover.h"
//#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////


Mover m;
vec gravity(0, -0.01, 0);
vec wind(0.001, 0, 0);

ostream & operator<<(ostream & os, vec & v) {
	os << "(" << v.x << ", " << v.y << ", " << v.z << ")";
	return os;
}

void applyGravity(Mover & _m) {
	gravity *= _m.mass;
	_m.applyForce(gravity * _m.mass);
	gravity = vec(0, -0.01, 0);
}

void applyWind(Mover & _m) {
	_m.applyForce(wind);
}

void applyFriction(Mover & _m) {
	float c = -0.001;
	vec friction = _m.velocity;
	//friction.normalise();
	friction *= c;
	//friction *= friction.mag();
	_m.applyForce(friction);
}

void applyDrag(Mover & _m) {
	float c = 0.1;
	float speed = m.velocity.mag();
	float dragMagnitude = c * pow(speed, 2);
	vec drag = _m.velocity;
	drag *= -1;
	//drag.normalise();
	drag *= dragMagnitude;
	_m.applyForce(drag);
}

void applyForces(Mover & _m) {
	applyGravity(_m);
	applyWind(_m);
	applyFriction(_m);
	applyDrag(_m);
}

void setup()
{

}

void update(int value)
{
	applyForces(m);

	m.update();
	m.edges();

}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	/*
	for (Mover n : m) {
		n.display();
	}
	*/
	m.display();

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
