#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

vec location = vec(100, 100, 0);

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
		if (location.x > 100 || location.x < -100) {
			velocity.x *= -1;
		}
		if (location.y > 100 || location.y < -100) {
			velocity.y *= -1;
		}
	}

	void display(float size) {
		glPointSize(size);
		glColor3f(0, 0, 1);
		drawPoint(location);
	}
};

Ball myBall;

void setup()
{

} 

void update(int value)
{
	myBall.move();
	myBall.bounce();
}


/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	myBall.display(10);

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
