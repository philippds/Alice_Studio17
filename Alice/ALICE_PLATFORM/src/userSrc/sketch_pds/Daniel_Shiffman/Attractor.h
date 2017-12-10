#pragma once
#ifndef ATTRACTOR
#define ATTRACTOR

#include "main.h"
#include "Mover.h"

//// CLASS ATTRACTOR

class Attractor
{
public:
	vec location;
	float mass;
	float G;
	vec dragOffset;
	float size;

	Attractor(vec location)
		:location(location)
	{
		mass = 20;
		G = 1;
		dragOffset = vec(0, 0, 0);
		size = 10;
	}
	Attractor()	{
		location = vec(0, 0, 0);
		mass = 20;
		G = 1;
		dragOffset = vec(0, 0, 0);
		size = 10;
	}

	vec attract(Mover _m) {
		//direction of the force
		vec force = location - _m.location;
		float d = force.mag();
		d = (d / 25) + 5;

		force.normalise();

		//magnitude of the force
		float strength = (G * mass * _m.mass) / (pow(d,2));

		// putting magnitude and direction together
		force *= strength;
		force /= 5;
		return force;
	}

	void display() {
		glPointSize(size);
		glColor3f(0, 0, 1);
		drawPoint(location);
	}
	//destructor
	~Attractor() {};
};
#endif

