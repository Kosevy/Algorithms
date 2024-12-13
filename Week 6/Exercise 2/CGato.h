#pragma once
#include <iostream>
#include "CAnimal.h"

using namespace std;
using namespace System;

class CGato : public Animal {
private:
public:
	CGato();
	~CGato();

	void Dibujar();
	void Borrar();
	void Mover(char tecla);
};

CGato::CGato() {
	this->x = Console::WindowWidth / 2;
	this->y = Console::WindowHeight / 2;
	this->dx = 1;
	this->dy = 1;
	this->ancho = 7;
	this->largo = 3;
}
CGato::~CGato() {}

void CGato::Dibujar() {
	Console::SetCursorPosition(x, y);
	cout << " /\\_/\\";
	Console::SetCursorPosition(x, y + dy);
	cout << "( o.o )";
	Console::SetCursorPosition(x, y + dy + 1);
	cout << " > ^ <";
}
void CGato::Borrar() {
	Console::SetCursorPosition(x, y);
	cout << "      ";
	Console::SetCursorPosition(x, y + dy);
	cout << "       ";
	Console::SetCursorPosition(x, y + dy + 1);
	cout << "      ";
}
void CGato::Mover(char tecla) {
	tecla = toupper(tecla);
	switch (tecla)
	{
	case 'A':
		Borrar();
		x -= dx;
		Dibujar();
		break;
	case 'D':
		Borrar();
		x += dx;
		Dibujar();
		break;
	case 'W':
		Borrar();
		y -= dy;
		Dibujar();
		break;
	case 'S':
		Borrar();
		y += dy;
		Dibujar();
		break;
	}
}