#pragma once
#include "CONFIG.h"
#include "Point.h"
#include "Turn.h"

#ifndef STATE_H

class State {
public:
	Point3 CP;
	float CD;
	float size;
	Turn turn;


	State() {
		this->CP.set(0, 0, 0);
		this->CD = 0;
		this->size = SIZE;
		this->turn = DIRECTION;
	}
	State(float size) {
		this->CP = CP;
		this->CD = CD;
		this->size = size;
		this->turn = DIRECTION;
	}
	State(Point3 CP, float CD, float size) {
		this->size = size;
	}

	void setSize(float size) {
		this->size = size;
	}
};

#endif // !STATE_H

