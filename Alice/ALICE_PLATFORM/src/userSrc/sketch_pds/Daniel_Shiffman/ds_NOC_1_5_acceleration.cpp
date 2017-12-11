#define _MAIN_
#ifdef _MAIN_

#include "main.h"

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

	void update() {
		acceleration = vec(ofRandom(-0.5 , 0.5), ofRandom(-0.5, 0.5), 0);

		//limit velocity
		velocity += acceleration;
		if (velocity.mag() > 5) {
			velocity.normalise() *= 5;
		}

		location += velocity;

	}

	void edges() {
		if (location.x > 20) {
			location.x = -20;
		}
		if (location.x < -20) {
			location.x = 20;
		}
		if (location.y > 20) {
			location.y = -20;
		}
		if (location.y < -20) {
			location.y = 20;
		}
	}

	void display(float size) {
		glPointSize(size);
		glColor3f(1, 0, 0);
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
