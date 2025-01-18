#pragma once
#include <iostream>

using namespace System;
using namespace std;

class Figura {
public:
	int x, y;
	int dx, dy;

	Figura() {};

	Figura(int x, int y) {
		x = x;
		y = y;
	}

	Figura(int x, int y, int dx, int dy) {
		x = x;
		y = y;
		dx = dx;
		dy = dy;
	}
	~Figura() {}

	virtual void Mover(){}

	virtual void Borrar(){}
	
	virtual void Dibujar(){}
};