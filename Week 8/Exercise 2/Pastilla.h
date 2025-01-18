#pragma once
#include "Figura.h"

class Pastilla : public Figura {
protected:

public:

	Pastilla() {
		x = numAleatorio();
		y = numAleatorio();
	}

	int numAleatorio() {
		int number = rand() % 39;
		return number;
	}

	void DibujarPastilla() {
		ConsoleColor::White;
		Console::SetCursorPosition(x, y);     cout << "(%%%)";
		Console::ResetColor;
	}

	void BorrarPastilla() {
		Console::SetCursorPosition(x, y);     cout << "   ";
	}

	void imprimirPastilla() {
		BorrarPastilla();
		DibujarPastilla();
	}
};