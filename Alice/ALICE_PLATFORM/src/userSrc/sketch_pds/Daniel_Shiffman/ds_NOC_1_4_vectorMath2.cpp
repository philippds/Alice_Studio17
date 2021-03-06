#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

vec location1;

class Ball {
public:
	vec location;
	vec velocity;
	float size;

	Ball() {
		location = vec(0, 0, 0);
		velocity = vec(2.5, -2, 0);
		size = 3;
	}

	void move() {
		location += velocity;
	}

	void bounce() {
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

Ball myBall;

void setup()
{
	myBall.velocity *= 0.1;
}

void update(int value)
{
	myBall.move();
	myBall.bounce();
	location1 = myBall.location;
	location1.normalise();
	location1 *= 5;
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	myBall.display(5);

	drawLine(location1, vec(0, 0, 0));
	glColor3f(0, 1, 1);
	drawRectangle(vec(0, 0, 0), myBall.location * 0.5);

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
