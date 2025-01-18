#pragma once
#include "CEntidad.h"

class CParticulas : public CEntidad {
private:

public:
	CParticulas(int x, int y) : CEntidad(x, y, 1, 2) {
		this->dx = 0;
		this->dy = 0;
	}

	~CParticulas() {}

	void mover() {}

	void dibujar() {
		for (int i = 0; i < ancho; i++)
		{
			for (int j = 0; j < alto; j++)
			{
				Console::SetCursorPosition(x + j, y + i);
				cout << char(111);
			}
		}
	}
};