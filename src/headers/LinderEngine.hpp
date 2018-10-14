/**
* @file LinderEngine.h
*
* @author azeemmirza
* @version 1.0.0
* @date 21/06/18
*/
#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <math.h>

#include "Square.hpp"
#include "State.hpp"
#include "Turn.hpp"
#include "CONFIG.hpp"

/**
* @class LinderEngine
* @description LinderEngine that takes, string, size and angle to generate tree. Singleton Pattern Followed to ensure one L-System on program
*/

class LinderEngine {

private:

	State cState;
	std::vector <State> Memory;
	std::string str;
	float alpha, beta;
	int branchCount;

	//Traingles sizes;
	float t1, t2, t3;
	float ratio, ratio2;

	/* Here will be the instance stored. */
	static LinderEngine* instance;

	/* Private constructor to prevent instancing. */
	LinderEngine(std::string str, float size, float angle);
	
	void moveForward ();
	void drawForward ();
	void turnRight ();
	void turnLeft ();
	void startBranch();
	void endBranch();

	float deg2Rad (float d);
	float calX ();
	float calY ();

public:

	/* Static access method. */
	static LinderEngine* getInstance (std::string str, float size, float angle);
	void run();

};

/* Null, because instance will be initialized on demand. */
LinderEngine* LinderEngine::instance = 0;

LinderEngine::LinderEngine (std::string str, float size, float angle) {

	this->str = str;
	this->alpha = angle;
	this->beta = alpha - 90;
	this->cState.setSize(size);
	this->ratio = alpha / 90;
	this->ratio2 = 1 - ratio;
	this->branchCount = 0;

}

LinderEngine* LinderEngine::getInstance (std::string str, float size, float angle) {
	
	if (instance == 0)
	{
		instance = new LinderEngine(str, size, angle);
	}

	return instance;

}

float LinderEngine::deg2Rad (float d) {
	float r = (d * M_PI) / 180;
	return r;
}


void LinderEngine::moveForward() {
	
	Point3 
		tmp = this->cState.CP;

	float 
		angle = -(this->cState.CD),
		r = (t2 / 2) + (t3 / 2),
		additiveX = (sin(deg2Rad(angle))*(r)),
		additiveY = (cos(deg2Rad(angle))*(r));

	this->cState.CP.
		setX(tmp.getX() + additiveX);
	this->cState.CP.
		setY(tmp.getY() + additiveY);

}

void LinderEngine::drawForward() {
	
	Point3 
		tmp = this->cState.CP;
	
	float 
		s = this->cState.size,
		angle = this->cState.CD;

	glColorMaterial(GL_FRONT, GL_3D);
	glEnable(GL_COLOR_MATERIAL);
	
	//printf("draw: %f",angle);
	
	if (this->branchCount < 5) {

		glColor3f(0.39, 0.72, 0.52);
		//glColor3f(0.54509,0.2705,0.7450);
	
	}
	
	else {
	
		glColor3f(0, 0.501960784, 0);

	}

	glPushMatrix();
	glTranslatef(tmp.getX(), tmp.getY(), tmp.getZ());
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-tmp.getX(), -tmp.getY(), -tmp.getZ());
	
	Square 
		sqrq(tmp, s);
	
	glPopMatrix();
	
	angle = -angle;

	float 
		additiveX = sin(deg2Rad(angle))*(s / 2),
		additiveY = cos(deg2Rad(angle))*(s / 2);

	this->cState.CP.
		setX(tmp.getX() + additiveX);
	this->cState.CP.
		setY(tmp.getY() + additiveY);
}

void LinderEngine::turnRight () {

	this->cState.CD += beta;
	this->cState.turn = RIGHT;
	this->cState.size *= sin(deg2Rad(alpha));
	
}

void LinderEngine::turnLeft() {

	this->cState.CD += alpha;
	this->cState.turn = LEFT;
	this->cState.size *= cos(deg2Rad(alpha));

}

void LinderEngine::startBranch() {
	
	this->t1 = this->cState.size;
	this->t2 = t1*cos(deg2Rad(alpha));
	this->t3 = t1*sin(deg2Rad(alpha));
	this->branchCount += 1;
	Memory.push_back(cState);

}

void LinderEngine::endBranch() {

	this->cState = Memory.back();
	this->branchCount -= 1;
	Memory.pop_back();

}

void LinderEngine::run() {
	printf("a1: %f \ta2: %f \n ", alpha, beta);
	printf("r1: %f \tr2: %f \n\n", ratio, ratio2);
	std::string strr = this->str;
	int lngth = strr.length();
	for (int i = 0; i < lngth; i++) {
		char c = strr[i];
		switch (c) {
		case 'S':
		case 'X':
			printf("\n %d :\t", i); this->cState.printState();
			this->drawForward();
			printf("\t"); this->cState.printState();
			break;
		case 'M':
			printf("\n %d :\t", i); this->cState.printState();
			this->moveForward();
			printf("\t"); this->cState.printState();
			break;
		case '+':
			printf("\n %d :\t", i); this->cState.printState();
			this->turnRight();
			printf("\t"); this->cState.printState();
			break;
		case '-':
			printf("\n %d :\t", i); this->cState.printState();
			this->turnLeft();
			printf("\t"); this->cState.printState();
			break;
		case '[':
			printf("\n %d :\t", i); this->cState.printState();
			this->startBranch();
			printf("\t"); this->cState.printState();
			break;
		case ']':
			printf("\n %d :\t", i); this->cState.printState();
			this->endBranch();
			printf("\t"); this->cState.printState();
			break;
		case ' ':
			printf("\n %d :s\t", i);  this->cState.printState();
			break;
		}
	}
}
