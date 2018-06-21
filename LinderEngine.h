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
	std::vector<State> Memory;
	std::string str;
	float alpha, beta;
	int branchCount;

	/* Here will be the instance stored. */
	static LinderEngine* instance;

	/* Private constructor to prevent instancing. */
	LinderEngine();
	
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
	static LinderEngine* getInstance();

};

/* Null, because instance will be initialized on demand. */
LinderEngine* LinderEngine::instance = 0;

LinderEngine::LinderEngine() {

}

LinderEngine* LinderEngine::getInstance () {
	if (instance == 0)
	{
		instance = new LinderEngine();
	}

	return instance;
}