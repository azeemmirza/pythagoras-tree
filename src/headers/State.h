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
		this->turn = UP;
	}
	State(float size) {
		
	}
	State(Point3 CP, float CD, float size) {
		
	}

	void setSize(float size) {
		
	}
	void printState() {
		
	}
};

#endif // !STATE_H

