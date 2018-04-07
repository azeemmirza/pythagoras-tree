/**
* @file IntRect.h
*
* @author azeemmirza
* @version 1.0
* @date 23/11/17
*/
#pragma once
#include "Point.h"

class RealRect
{
public:
	RealRect() { l = 0; r = 100; b = 0; t = 100; }
	RealRect(float left, float right, float bottom, float top)
	{
		l = left; r = right; b = bottom; t = top;
	} // constructors
	void set(float left, float right, float bottom, float top)
	{
		l = left; r = right; b = bottom; t = top;
	}
	float getl() { return l; }
	float getr() { return r; }
	float getb() { return b; }
	float gett() { return t; }
	void draw(void);
private:
	float l, r, b, t;
};

RealRect::RealRect() { l = 0; r = 100; b = 0; t = 100; }

RealRect::RealRect(float left, float right, float bottom, float top)
{
	l = left; r = right; b = bottom; t = top;
} 

void RealRect::set(float left, float right, float bottom, float top)
{
	l = left; r = right; b = bottom; t = top;
}

float RealRect::getl() { return l; }

float RealRect::getr() { return r; }

float RealRect::getb() { return b; }

float RealRect::gett() { return t; }

void RealRect::draw(void)
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(l, b);
	glVertex2f(r, b);
	glVertex2f(r, t);
	glVertex2f(l, t);
	glEnd();
	glFlush();
}