#pragma once
#include "CONFIG.h"
#include "Point.h"
#include "Turn.h"

#ifndef STATE_H
/**
* @class State
* @description state selection class in which state current axiom is or going to be
*/
class State {
public:
	Point3 CP;
	float CD;
	float size;
	Turn turn;

	State();
	State(float size);
	State(Point3 CP, float CD, float size);

	void setSize(float size);
	void printState();

};

State::State() {
	this->CP.set(0, 0, 0);
	this->CD = 0;
	this->size = SIZE;
	this->turn = DIRECTION;
}


#endif // !STATE_H

