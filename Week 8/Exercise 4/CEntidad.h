#pragma once
#include <iostream>
#define ANCHO 80
#define ALTO 40


using namespace std;
using namespace System;

class CEntidad {
protected:
	float x, y;
	float dx, dy;
	int ancho, alto;
	
public:

	CEntidad(int x, int y, int ancho, int alto) {
		this->x = x;
		this->y = y;
		this->ancho = ancho;
		this->alto = alto;
	}

	~CEntidad() {}

	void borrar() {
		for (int i = 0; i < ancho; i++) {
			for (int j = 0; j < alto; j++) {
				Console::SetCursorPosition(x + i, y + j);
				cout << ' ';
			}
		}
	}

	virtual void mover() {}
	virtual void dibujar() {}

	void animar() {
		borrar();
		mover();
		dibujar();
	}

	virtual bool intersectar(CEntidad* e) {
		return (x <= e->x + e->ancho && e->x <= x + ancho &&
			y <= e->y + e->alto && e->y <= y + alto);
	}
};