#pragma once
#include "Figura.h"
#include <conio.h>
#define ARRIBA 72
#define ABAJO 80
#define IZQUIERDA 75 
#define DERECHA 77

class GhostEater : public Figura {

public:

	GhostEater() {
		x = Console::WindowWidth / 2;
		y = Console::WindowHeight / 2;
	}

	~GhostEater() {}

	void dibujarPersonaje() {
		Console::SetCursorPosition(x, y);cout << "#";
		Console::ResetColor;
	}

	void borrarPersonaje() {
		Console::SetCursorPosition(x, y); cout << " ";
	}

	void MoverJugador() {
		if (_kbhit()) {
			borrarPersonaje();
			char tecla = getch();
			if (tecla == ARRIBA && y > 0) y--;
			else if (tecla == ABAJO && y < 39) y++;
			else if (tecla == DERECHA && x < 79) x++;
			else if (tecla == IZQUIERDA && x > 0) x--;
		}
		dibujarPersonaje();
	}
};