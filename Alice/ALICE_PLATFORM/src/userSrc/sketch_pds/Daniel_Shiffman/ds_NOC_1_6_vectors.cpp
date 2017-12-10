#define _MAIN_
#ifdef _MAIN_

#include "main.h"
//#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

class Mover {
public:
	vec mouse;
	vec location;
	vec velocity;
	vec velocityLoc;
	vec acceleration;
	vec accelerationLoc;
	float size;

	Mover() {
		mouse = vec(0, 0, 0);
		velocity = vec(0, 0, 0);
		acceleration = vec(0, 0, 0);

		location = vec(0, 0, 0);
		velocityLoc = vec(0, 0, 0);
		accelerationLoc = vec(0, 0, 0);

		size = 3;
	}

	void update() {
		acceleration = vec(ofRandom(-0.1, 0.1), ofRandom(-0.1, 0.1), 0);
		//limit velocity
		velocity += acceleration;
		if (velocity.mag() > 5) {
			velocity.normalise() *= 5;
		}
		mouse += velocity;

		accelerationLoc = mouse - location;
		velocityLoc += accelerationLoc;
		velocityLoc.normalise();
		velocityLoc *= 0.2;
		location += velocityLoc;
	}

	void edges() {
		if (mouse.x > 20) {
			mouse.x = -20;
		}
		if (mouse.x < -20) {
			mouse.x = 20;
		}
		if (mouse.y > 20) {
			mouse.y = -20;
		}
		if (mouse.y < -20) {
			mouse.y = 20;
		}
	}

	void display(float size) {
		glPointSize(size);
		glColor3f(1, 0, 0);
		drawPoint(mouse);
		drawPoint(location);
	}
};

Mover myBall;

void setup()
{

}

void update(int value)
{
	myBall.update();
	myBall.edges();
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	myBall.display(5);

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
