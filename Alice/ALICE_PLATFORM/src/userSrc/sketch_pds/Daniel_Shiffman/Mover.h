#pragma once
#ifndef MOVER
#define MOVER

#include "main.h"

//// CLASS MOVER

class Mover
{
public:
	vec location;
	vec velocity;
	vec acceleration;
	float mass;
	float size;

	Mover() {
		location = vec(ofRandom(-100.0,100.0), ofRandom(-100.0, 100.0), 0);
		velocity = vec(0, 0, 0);
		acceleration = vec(0, 0, 0);
		mass = ofRandom(2, 10);
		size = mass;
	}

	void applyForce(vec _force) {
		vec f = _force / mass;
		acceleration += f;
	}

	void update() {
		velocity += acceleration;
		location += velocity;
		acceleration *= 0;
	}

	void edges() {
		if (location.x > 100) {
			location.x = 100;
			velocity.x *= -1;
		}
		else if(location.x < -100){
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
	}
	//destructor
	~Mover() {};
};
#endif

