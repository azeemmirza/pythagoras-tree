/**
* @file IntRect.h
*
* @author azeemmirza
* @version 1.0
* @date 23/11/17
*/

#pragma once
#include "Point.h"
class IntRect
{
public:
	IntRect();
	IntRect(int left, int right, int bottom, int top);

	void set(int left, int right, int bottom, int top);

	int getl();
	int getr();
	int getb();
	int gett();
	
	void draw(void); 
private:
	int l, r, b, t;
};


/** @constructor */

IntRect::IntRect() {
	this->l = 0; 
	this->r = 100; 
	this->b = 0; 
	this->t = 100;
}

IntRect::IntRect() {
	this->l = 0; 
	this->r = 100;
	this->b = 0;
	this->t = 100;
}

IntRect::IntRect(int left, int right, int bottom, int top)
{
	l = left; r = right; b = bottom; t = top;
}

void IntRect::set(int left, int right, int bottom, int top)
{
	l = left; r = right; b = bottom; t = top;
}

int IntRect::getl() { return l; }

int IntRect::getr() { return r; }

int IntRect::getb() { return b; }

int IntRect::gett() { return t; }

void IntRect::draw(void)
{
	glBegin(GL_LINE_LOOP);
	glVertex2i(l, b);
	glVertex2i(r, b);
	glVertex2i(r, t);
	glVertex2i(l, t);
	glEnd();
}