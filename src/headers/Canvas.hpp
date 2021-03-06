/**
* @file Point.h
*
* @author azeemmirza
* @version 1.0.1
* @date 08/04/18
*/
#pragma once
#include "CONFIG.hpp"
#include "Point.hpp"
#include "IntRect.hpp"
#include "RealRect.hpp"


/**
* @class Canvas
* @description Creates Canvas for drawing
*/
class Canvas {
public:
	Canvas(int width, int height, int positionX, int positionY, std::string windowTitle);

	void setWindow(float l, float r, float b, float t);
	void setViewport(int l, int r, int b, int t);
	
	IntRect getViewport(void); 
	RealRect getWindow(void);
	
	float getWindowAspectRatio(void);
	float getCD(void);
	void clearScreen();
	
	void setBackgroundColor(float r, float g, float b);
	void setColor(float r, float g, float b);
	void lineTo(float x, float y, float z);
	void lineTo(Point3 p);
	void moveTo(float x, float y, float z);
	void moveTo(Point3 p);
	
	Point3 getCP();

private:
	Point3 CP;
	IntRect viewport; 
	RealRect window; 

};

/**
* @constructor
*/
Canvas::Canvas(int width, int height, int positionX, int positionY, std::string windowTitle)// constructor
{

	char* argv[1]; // dmmy argument list for glutInit()
	char dummyString[8];
	argv[0] = dummyString; // hook up the pointer
	int argc = 1; // to satisfy glutInit()

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(positionX, positionY);
	/**
	* Open the screen window
	*/
	const char* windowTitleChar = windowTitle.c_str();
	glutCreateWindow(windowTitleChar); 
	/**
	* Default world window
	*/
	setWindow(0, (float)width, 0, (float)height); //
	/**
	* Default viewport
	*/
	setViewport(0, width, 0, height); 
	/**
	* Initialize the CP to (0,0)
	*/
	CP.set(0.0f, 0.0f, 0.0f);
}

/**
* Set the world window
*/
void Canvas::setWindow(float l, float r, float b, float t)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	gluOrtho2D(l, r, b, t);
}
/**
* Set the Viewport Map
*/
void Canvas::setViewport(int l, int r, int b, int t)
{
	glViewport(l, b, r - l, t - b);
}
void Canvas::clearScreen()
{
	glClear(GL_COLOR_BUFFER_BIT);
}
/**
* Set the canvas background
*/
void Canvas::setBackgroundColor(float r, float g, float b)
{
	glClearColor(r, g, b, 1.0);
}
/**
* Sets color of next object
*/
void Canvas::setColor(float r, float g, float b)
{
	glColor3f(r, g, b);
}
/**
* Draw line to given points from CP(Current Point)
*/
void Canvas::lineTo(float x, float y, float z)
{
	glBegin(GL_LINES);
	glVertex2f(CP.getX(), CP.getY());
	glVertex2f(x, y);
	glEnd();

	CP.set(x, y, z);
}
/**
* Draw line to given points from CP(Current Point)
*/
void Canvas::lineTo(Point3 p)
{
	glBegin(GL_LINES);
	glVertex2f(CP.getX(), CP.getY());
	glVertex2f(p.getX(), p.getY());
	glEnd();

	CP.set(p.getX(), p.getY(), p.getZ());
}
/**
* Change CP(Current Point)
*/
void Canvas::moveTo(float x, float y, float z)
{
	CP.set(x, y, z);
}
/**
* Change CP(Current Point)
*/
void Canvas::moveTo(Point3 p)
{
	CP.set(p.getX(), p.getY(), p.getZ());
}
/**
* returns CP(Current Point) on canvas
*/
Point3 Canvas::getCP() {
	return CP;
}