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
#include "Square.h"
#include "State.h"
#include "Turn.h"

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

	float deg2Rad ();
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

void LinderEngine::moveForward() {
	Point3 tmp = this->cState.CP;
	//tmp.setSize(10.0);
	//tmp.draw();
	/*
	printf("x: %f , y: %f \n", tmp.getX(), tmp.getY());
	float size = this->cState.size;
	float angle = -(this->cState.CD);
	printf("move: %f", angle);
	float turn = this->cState.turn;


	float additiveX = (sin(degreeToRad(angle))*(size));

	float additiveY = (cos(degreeToRad(angle))*(size));

	this->cState.CP.setX(tmp.getX() + additiveX);
	this->cState.CP.setY(tmp.getY() + additiveY);*/
	//float turn = this->cState.turn;
	float r, angle;
	angle = -(this->cState.CD);
	r = (t2 / 2) + (t3 / 2);


	float additiveX = (sin(degreeToRad(angle))*(r));

	float additiveY = (cos(degreeToRad(angle))*(r));

	this->cState.CP.setX(tmp.getX() + additiveX);
	this->cState.CP.setY(tmp.getY() + additiveY);

}