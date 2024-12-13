#pragma once
#include "CAnimal.h"
#include "CGato.h";

class CRaton : public Animal {
private:

public:
	CRaton();
	CRaton(int x, int y);
	~CRaton();

	void Dibujar();
	void Borrar();
	void Mover(char tecla);
	bool Colision(CGato* obj);
};

CRaton::CRaton(int x, int y) {
	x = x;
	y = y;
	dx = 1;
	dy = 1;
	ancho = 7;
	largo = 1;
}

CRaton::~CRaton() {}

void CRaton::Dibujar() {
	Console::SetCursorPosition(x, y);
	cout << "--(_c'>";
}

void CRaton::Borrar() {
	Console::SetCursorPosition(x, y);
	cout << "       ";
}

void CRaton::Mover(char tecla) {
	Borrar();
	int anchoC = Console::WindowWidth;
	int largoC = Console::WindowHeight;

	if (x + dx < 0 || x + dx + ancho > anchoC) {
		dx *= -1;
	}
	if (y + dy < 0 || y + dy + largo > largoC) {
		dy *= -1;
	}

	x += dx;
	y += dy;
	Dibujar();
}

bool CRaton::Colision(CGato* obj) {
	bool existe_colision = false;
	if (
		x < obj->getX() + obj->getAncho() &&
		x + ancho > obj->getX() &&
		y < obj->getY() + obj->getLargo() &&
		y + largo > obj->getY()
		) {
		existe_colision = true;
	}
	return existe_colision;
}