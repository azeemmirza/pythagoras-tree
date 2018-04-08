/**
* @file Point.h
*
* @author azeemmirza
* @version 1.0.1
* @date 08/04/18
*/
#pragma once
#include "Point.h"
#include "IntRect.h"
#include "RealRect.h"


/**
* @class Canvas
* @description Creates Canvas for drawing
*/
class Canvas {
	Canvas(int width, int height, char* windowTitle);

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
Canvas::Canvas(int width, int height, char* windowTitle)// constructor
{
	/**
	* Dummy argument list for glutInit()
	*/
	char* argv[1]; 
	char dummyString[8];

	/**
	* Hook up the pointer
	*/
	argv[0] = dummyString; // 

	/**
	* To satisfy glutInit()
	*/
	int argc = 1; 

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(width, height);
	glutInitWindowPosition(1000, 20);
	/**
	* Open the screen window
	*/
	glutCreateWindow(windowTitle); 
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