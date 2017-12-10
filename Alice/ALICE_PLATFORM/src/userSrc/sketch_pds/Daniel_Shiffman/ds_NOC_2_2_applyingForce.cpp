#define _MAIN_
#ifdef _MAIN_

#include "main.h"
//#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

class Mover {
public:
	vec location;
	vec velocity;
	vec acceleration;
	float size;

	Mover() {
		location = vec(0, 0, 0);
		velocity = vec(0, 0, 0);
		acceleration = vec(0, 0, 0);
		size = 3;
	}

	void applyForce(vec _force) {
		acceleration += _force;
	}

	void update() {
		acceleration;
		velocity += acceleration;
		location += velocity;
		acceleration = vec(0, 0, 0);
	}

	void edges() {
		if (location.x > 20 || location.x < -20) {
			velocity.x *= -1;
		}
		if (location.y > 20 || location.y < -20) {
			velocity.y *= -1;
		}
	}

	void display(float size) {
		glPointSize(size);
		glColor3f(1, 0, 0);
		drawPoint(location);
	}
};

Mover m;
vec gravity(0, -0.01, 0);
vec wind(0.001, 0, 0);

void setup()
{

}

void update(int value)
{
	m.applyForce(gravity);
	m.applyForce(wind);
	m.edges();
	m.update();
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	m.display(5);

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
