#pragma once
#ifndef MOVER_BUG
#define MOVER_BUG

#include "main.h"

//// CLASS MOVER

class Mover_bug
{
public:
	vec location;
	vec velocity;
	vec acceleration;
	float mass;
	float size;

	float amplitude = 100;
	float angle = 0.0;

	float x;

	Mover_bug() {
		location = vec(ofRandom(-100.0, 100.0), ofRandom(-100.0, 100.0), 0);
		velocity = vec(0, 0, 0);
		acceleration = vec(0, 0, 0);
		mass = ofRandom(2, 10);
		size = mass;
	}

	void applyForce(vec _force) {
		vec f = _force / mass;
		acceleration += f * 0.01;
	}

	void update() {
		velocity += acceleration;
		location += velocity;
		harmonic_coil(velocity);
		acceleration *= 0;
	}

	void harmonic_coil(vec vel) {
		x = amplitude * sin(angle);
		angle += vel.mag() / 100;
	}

	void edges() {
		if (location.x > 100) {
			location.x = 100;
			velocity.x *= -1;
		}
		else if (location.x < -100) {
			location.x = -100;
			velocity.x *= -1;
		}

		if (location.y > 100) {
			location.y = 100;
			velocity.y *= -1;
		}
		if (location.y < -100) {
			location.y = -100;
			velocity.y *= -1;
		}
	}

	void display() {
		glPointSize(size);
		glColor3f(1, 0, 0);
		drawPoint(location);
		drawCircle(location, 10, 100);

		drawLine(location, vec(x, 0, 0));
		drawCircle(vec(x, 0, 0), 10, 100);
	}
	//destructor
	~Mover_bug() {};
};
#endif

