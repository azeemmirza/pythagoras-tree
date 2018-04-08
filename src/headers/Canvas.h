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