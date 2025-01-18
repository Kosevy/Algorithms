#pragma once
#include <vector>
#include "CEntidad.h"
#include "CNave.h"
#include "CParticulas.h"
#include "CAlien.h"

class CJuego {
private:
	CNave* nave;
	vector<CAlien*> alien;
	vector<CParticulas*> particulas;
	bool gameover;

public:
	CJuego() {
		Console::SetWindowSize(ANCHO, ALTO);
		Console::CursorVisible = false;
		srand(time(nullptr));
		gameover = false;
		nave = new CNave(ANCHO / 2 - 2, ALTO - 8);
		for (int i = 0; i < 4; i++) {
			alien.push_back(new CAlien(rand() % (ANCHO - 9), rand() % (ALTO - 8)));
		}
		for (int i = 0; i < 4; i++) {
			particulas.push_back(new CParticulas(rand() % (ANCHO - 9), rand() % (ALTO - 4)));
		}
	}

	~CJuego() {
		delete nave;
		for (int i = 0; i < alien.size(); i++) {
			delete alien[i];
		}
		alien.clear();
		for (int i = 0; i < particulas.size(); i++) {
			delete particulas[i];
		}
		particulas.clear();
	}

	void iniciarJuego() {

		nave->animar();
		for (int i = 0; i < alien.size(); i++) 
		{
			alien[i]->borrar();
			if (alien[i]->intersectar(nave)) {
				this->gameover = true;
			}
			alien[i]->mover();
			alien[i]->dibujar();
		}

		for (int i = 0; i < particulas.size(); i++) {
			particulas[i]->borrar();
			if (particulas[i]->intersectar(nave)) {
				particulas.erase(particulas.begin() + i);
				i--;
				continue;
			}
			particulas[i]->mover();
			particulas[i]->dibujar();
		}
		if (particulas.size() == 0) {
			this->gameover = true;
		}
	}

	bool gameFinished() {
		return gameover;
	}

	bool gameWin() {
		return (particulas.size() == 0);
	}
};