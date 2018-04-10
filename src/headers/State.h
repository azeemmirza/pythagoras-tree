#pragma once
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

