/**
  * @file Point.h
  *
  * @author azeemmirza
  * @version 1.0.1
  * @date 21/11/17
  */

#pragma once
#include "../GLUT/glut.h"

/**
  * @class Point3
  * @description Creates 3d Point instance
*/
class Point3 {
public:
	Point3();
	Point3(float x, float y, float z);

	void set(float x, float y, float z);
	void setX(float x);
	void setY(float y);
	void setZ(float z);

	float getX();
	float getY();
	float getZ();

	void draw(void);
	void setSize(float i);
private:
	float x, y, z;
};

/**
  * @constructor
  */
Point3::Point3() {
	x = y = z = 0.0f;
}

/**
  * @constructor 
  * @param {float} x, {float} y, {float} z,
*/

Point3::Point3(float x, float y, float z) {
	this->set(x, y, z);
}

void Point3::set(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

void Point3::setX(float x) {
	this->x = x;
}

void Point3::setY(float y) {
	this->y = y;
}

void Point3::setZ(float z) {
	this->z = z;
}

float Point3::getX() {
	return this->x;
}

float Point3::getY() {
	return this->y;
}

float Point3::getZ() {
	return this->z;
}

void Point3::setSize(float i) {
	glPointSize((GLfloat)i);
}

void Point3::draw() {
	GLfloat xx = this->x;
	GLfloat yy = this->y;
	GLfloat zz = this->z;
	glBegin(GL_POINTS);
	glVertex3f(xx, yy, zz);
	glEnd();
}