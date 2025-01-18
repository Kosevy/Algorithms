#pragma once
#include "CEntidad.h"
#include <conio.h>

class CNave : public CEntidad {
private:
	int vidas;
public:
	CNave(int x, int y) : CEntidad(x, y, 13, 4) {
		this->dx = 0;
		this->dy = 0;
	}

	~CNave() {}

	void mover()  {
        if (kbhit()) {
            char tecla = getch();
            switch (toupper(tecla)) {
            case 'W':
                if (y - 1 >= 0) {
                    y--;
                }
                break;
            case 'S':
                if (y + alto + 1 < ALTO) {
                    y++;
                }
                break;
            case 'A':
                if (x - 1 >= 0) {
                    x--;
                }
                break;
            case 'D':
                if (x + ancho + 1 < ANCHO) {
                    x++;
                }
                break;
            }
        }
	}

	void dibujar() {
		Console::ForegroundColor = ConsoleColor::Blue;
		Console::SetCursorPosition(x, y);
		cout << "     ___";
		Console::SetCursorPosition(x, y + 1);
		cout << "  ___/ \\___";
		Console::SetCursorPosition(x, y + 2);
		cout << "  ( 'O^O' )";
		Console::SetCursorPosition(x, y + 3);
		cout << "'==ooooooo=='";
		Console::ResetColor();
	}

	void disminuirVida(int hp) {
		vidas = hp;
	}

};