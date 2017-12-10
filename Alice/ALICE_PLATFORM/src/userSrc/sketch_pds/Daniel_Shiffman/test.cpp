#define _MAIN_
#ifdef _MAIN_

#include "main.h"
#include "MODEL.h"
#include <array>
#include <memory>
#include <time.h>
#include <experimental/generator>
///
#include <iostream>
#include <random>

///////// ----------------------------------------- model - view - controller (MVC) paradigm / pattern / template  ----------------- ////////////////////////////// 
/////////////////////////// model  ///////////////////////////////////////////


Mesh myMesh;
Vertex v[3];   

void setup()
{

	myMesh.createVertex(vec(0, 0, 0));
	myMesh.createVertex(vec(0, 0, 10));
	myMesh.createVertex(vec(0, 10, 0));
	

	myMesh.createEdge(myMesh.vertices[0], myMesh.vertices[1]);
	myMesh.createEdge(myMesh.vertices[1], myMesh.vertices[2]);
	myMesh.createEdge(myMesh.vertices[2], myMesh.vertices[0]);

	//myMesh.createFace(, 0);

	//myMesh.createNGon()


}

void update(int value)
{

}

/////////////////////////// view  ///////////////////////////////////////////

void draw()
{
	backGround(0.75);
	drawGrid(20);
	glColor3f(1.0, 0.5, 0.3);
	myMesh.draw();
	myMesh.draw(true);
	


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
