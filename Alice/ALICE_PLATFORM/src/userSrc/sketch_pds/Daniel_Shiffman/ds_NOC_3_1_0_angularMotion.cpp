#define _MAIN_
#ifdef _MAIN_

#include "main.h"

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////

void rotate_vec(vec& origin, vec& vector, double angle)
{
	vec resulting_vec = vector - origin;
	double x = cos(angle) * resulting_vec.x - sin(angle) * resulting_vec.y;
	double y = sin(angle) * resulting_vec.x + cos(angle) * resulting_vec.y;
	vec new_vec(x, y, 0);
	
	vector = new_vec + origin; 
}

class my_Polygon
{
public:
	my_Polygon(vec& a, vec& b, vec& c, vec& d)
		:a(a), b(b), c(c), d(d) {}

	void draw();
	void rotate(vec c, double angle);

private:
	vec a, b, c, d;
};

void my_Polygon::draw()
{
	glColor3f(1, 0, 0);
	glLineWidth(3);
	drawLine(a, b);
	drawLine(b, c);
	drawLine(c, d);
	drawLine(d, a);
}

void my_Polygon::rotate(vec origin, double angle)
{
	rotate_vec(origin, a, angle);
	rotate_vec(origin, b, angle);
	rotate_vec(origin, c, angle);
	rotate_vec(origin, d, angle);
}

vec a(0, 0, 0);
vec b(20, 0, 0);
vec c(20, 10, 0);
vec d(0, 10, 0);

my_Polygon pg(a, b, c, d);

double a_ = 0.0;
double aVelocity = 0.0;
double aAcceleration = 0.00001;

void setup()
{
	
}

void update(int value)
{
	a_ += aVelocity;
	aVelocity += aAcceleration;

	pg.rotate(vec(10, 5, 0), a_);
}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{	
	pg.draw();

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
