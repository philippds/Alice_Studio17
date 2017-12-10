#define _MAIN_
#ifdef _MAIN_

#include "main.h"
//#include <random>

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

} 

void update(int value)
{
	myBall.move();
	myBall.bounce();
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
