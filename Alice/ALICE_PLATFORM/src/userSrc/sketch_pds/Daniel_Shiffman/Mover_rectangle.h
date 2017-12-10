#pragma once
#pragma once
#ifndef MOVER
#define MOVER

#include "main.h"



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
		:a(a), b(b), c(c), d(d)
	{

	}
	my_Polygon()
		:a(vec(-10, -10, 0)), b(10,-10,0), c(10,10,0), d(-10,10,0), e(0,0,0)
	{

	}

	vec center() { return e; }
	void draw();
	void rotate(vec c, double angle);
	void move(vec destination);

private:
	vec a, b, c, d, e;
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
	rotate_vec(origin, e, angle);
}

void my_Polygon::move(vec destination)
{
	a += destination;
	b += destination;
	c += destination;
	d += destination;
	e += destination;
}


//// CLASS MOVER

class Mover
{
public:
	vec location;
	vec velocity;
	vec acceleration;

	my_Polygon poly;
	float mass;
	float size;

	double a_;
	double aVelocity;
	double aAcceleration;

	Mover() {
		location = vec(ofRandom(-10.00, 10.00), ofRandom(-10.00, 10.00), 0);
		poly.move(location);

		velocity = vec(0, 0, 0);
		acceleration = vec(0, 0, 0);

		//mass = ofRandom(1, 10);
		mass = 1;
		size = mass;

		a_ = 0.0;
		aVelocity = 0.0;
		aAcceleration = 0.00001;
	}

	void applyForce(vec& _force) {
		vec f = _force / mass;
		acceleration += f;
	}

	void update() {		
						
		velocity += acceleration;
		location += velocity;
		poly.move(velocity);
		acceleration *= 0;

		vec vel_copy = velocity;

		aVelocity += aAcceleration;
		a_ += (aVelocity + (velocity.mag() * vel_copy.normalise().x)) * 0.0001;
		poly.rotate(poly.center(), a_);

		aAcceleration *= 0;
	}

	void edges() {
		if (location.x > 20) {
			location.x = 20;
			velocity.x *= -1;
		}
		else if (location.x < -20) {
			location.x = -20;
			velocity.x *= -1;
		}

		if (location.y > 20) {
			location.y = 20;
			velocity.y *= -1;
		}
		if (location.y < -20) {
			location.y = -20;
			velocity.y *= -1;
		}
	}

	void display() {
		glPointSize(size);
		glColor3f(1, 0, 0);
		poly.draw();

		drawPoint(location);
	}
	//destructor
	~Mover() {};
};
#endif

