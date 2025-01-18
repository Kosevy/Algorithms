#pragma once
#include "Figura.h"

class Fantasma : public Figura {
protected:
	int direccion;
	ConsoleColor codigoColor;
public:
	Fantasma() {
		x = numAleatorio();
		y = numAleatorio();
		direccion = 1;

		int coloresDestacados[] = { 11, 12};
		codigoColor = (ConsoleColor)coloresDestacados[rand() % 2];
	};

	~Fantasma(){}

	int numAleatorio() {
		int number = rand() % 39;
		return number;
	}

	void dibujarFantasma() {
		Console::ForegroundColor = codigoColor;
		Console::SetCursorPosition(x, y);     cout << " OO ";
		Console::SetCursorPosition(x, y + 1); cout << "/  \\";
		Console::ResetColor;
	}

	void borrarFantasma() {
		Console::SetCursorPosition(x, y);     cout << "       ";
		Console::SetCursorPosition(x, y + 1); cout << "       ";
	}

	void MoverFantasma() {
		borrarFantasma();
		x += direccion;
		if (x >= Console::WindowWidth - 7) {
			direccion *= -1;
		}
		if (x <= 1) {
			direccion *= -1;
		}
		dibujarFantasma();
	}

};