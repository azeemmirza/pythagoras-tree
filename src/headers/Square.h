/**
* @file Square.h
*
* @author azeemmirza
* @version 1.0
* @date 20/06/18
*/
#pragma once
#include "Point.h"

#ifndef SQUARE_H

/**
 * @class Square
 * @description Sqaure class to draw square with w.r.t center point.
*/

class Square {
public:
	Square(Point3 i, float s);
};

Square::Square(Point3 i, float s) {
	float x = i.getX(), 
		y = i.getY(), 
		z = i.getZ();
	float ss = s / 2,
		xx = x - ss, 
		yy = y - ss, 
		zz = z - ss;
	float xxx = x + ss, 
		yyy = y + ss, 
		zzz = z + ss;

	glBegin(GL_POLYGON);

	glVertex3f(xx, yy, zz);
	glVertex3f(xxx, yy, zz);
	glVertex3f(xxx, yyy, zz);

	glVertex3f(xx, yy, zz);
	glVertex3f(xxx, yyy, zz);
	glVertex3f(xx, yyy, zz);

	glVertex3f(xx, yy, zz); 
	glVertex3f(xx, yyy, zz);
	glVertex3f(xx, yyy, zzz);

	glVertex3f(xx, yy, zz);
	glVertex3f(xx, yy, zzz);
	glVertex3f(xx, yyy, zzz);

	glVertex3f(xx, yy, zzz);
	glVertex3f(xxx, yyy, zzz);
	glVertex3f(xx, yyy, zzz);

	glVertex3f(xx, yy, zzz);
	glVertex3f(xxx, yyy, zzz);
	glVertex3f(xxx, yy, zzz);
							 							 
	glVertex3f(xxx, yy, zzz);
	glVertex3f(xxx, yyy, zz); 
	glVertex3f(xxx, yyy, zzz);
							 
	glVertex3f(xxx, yy, zzz);
	glVertex3f(xxx, yyy, zz);
	glVertex3f(xxx, yy, zz);

	glVertex3f(xx, yyy, zz);
	glVertex3f(xx, yyy, zzz);
	glVertex3f(xxx, yyy, zz);
							  
	glVertex3f(xxx, yyy, zzz);
	glVertex3f(xx, yyy, zzz);
	glVertex3f(xxx, yyy, zz);

	glVertex3f(xx, yy, zz);
	glVertex3f(xx, yy, zzz);
	glVertex3f(xxx, yy, zz);
							 
	glVertex3f(xxx, yy, zzz);
	glVertex3f(xx, yy, zzz);
	glVertex3f(xxx, yy, zz); 


	glEnd();
}


#endif //SQUARE_H