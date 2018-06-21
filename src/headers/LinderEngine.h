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
#include "CONFIG.h"

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

float degreeToRad(float d) {
	float r = (d * M_PI) / 180;
	return r;
}

