#pragma once
#include "CONFIG.hpp"
#include "Point.hpp"
#include "Turn.hpp"

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

State::State(float size) {
	this->CP = CP;
	this->CD = CD;
	this->size = size;
	this->turn = DIRECTION;
}

State::State(Point3 CP, float CD, float size) {
	this->size = size;
}

void State::setSize(float size) {
	this->size = size;
}

void State::printState() {
	Point3 tmp = this->CP;
	printf(" Position: ( %f , %f , %f ) Size: %f Angle: %f\n", tmp.getX(), tmp.getY(), tmp.getZ(), this->size, this->CD);
}

#endif // !STATE_H