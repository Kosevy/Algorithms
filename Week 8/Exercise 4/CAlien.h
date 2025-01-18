#pragma once
#include "CEntidad.h"

class CAlien : public CEntidad {
private:
	int color;
public:
	CAlien(int x, int y) : CEntidad(x, y, 7, 6) {

		this->color = 11 + rand() % 2;
		if (rand() % 2) {
			this->dx = (rand() % 2) ? 1 : -1;
			this->dy = 0;
		}
		else {
			this->dy = (rand() % 2) ? 1 : -1;
			this->dx = 0;
		}

	}

	~CAlien() {}

	void mover() {
		if (x + dx < 0 || x + dx + ancho >= ANCHO) {
			dx *= -1;
		}
		if (y + dy < 0 || y + dy + alto >= ALTO) {
			dy *= -1;
		}
		x += dx;
		y += dy;
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor(color);
		Console::SetCursorPosition(x, y);
		cout << " ____ ";
		Console::SetCursorPosition(x, y + 1);
		cout << "| o o |";
		Console::SetCursorPosition(x, y + 2);
		cout << "|  ^  |";
		Console::SetCursorPosition(x, y + 3);
		cout << "| ----|";
		Console::SetCursorPosition(x, y + 4);
		cout << "|     |";
		Console::SetCursorPosition(x, y + 5);
		cout << "|_____|";
		Console::ResetColor();
	}
};