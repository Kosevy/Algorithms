#pragma once
#include <vector>
#include "Fantasma.h"
#include "GhostEater.h"
#include "Pastilla.h"

class Juego : public GhostEater {
protected:
	vector <Fantasma*> objFantasma;
	vector <Pastilla*> objPastilla;
	int contador;
public:
	Juego() {
		agregarFantasma(5);
		agregarPastilla(4);
		contador = 0;
	}

	~Juego(){}

	void agregarFantasma(int totalFantasma) {
		for (int i = 0; i < totalFantasma; i++) {
			objFantasma.push_back(new Fantasma());
		}
	}

	void agregarPastilla(int totalPastilla) {
		for (int i = 0; i < totalPastilla; i++) {
			objPastilla.push_back(new Pastilla());
		}
	}

	void moverJuego() {
		MoverJugador();
		for (int i = 0; i < objFantasma.size(); i++) {
			objFantasma[i]->MoverFantasma();
			if (x >= objFantasma[i]->x && x <= objFantasma[i]->x + 4 && y >= objFantasma[i]->y && y <= objFantasma[i]->y + 2) {
				objFantasma[i]->borrarFantasma();
				delete objFantasma[i];
				objFantasma.erase(objFantasma.begin() + i);
				i--;
				cout << "IMPACTO Ghost-Eater –FANTASMA !!!- GAME OVER !!!" << endl;
			}
		}
		for (int i = 0; i < objPastilla.size(); i++) {
			objPastilla[i]->imprimirPastilla();
			if (x >= objPastilla[i]->x && x <= objPastilla[i]->x + 4 && y >= objPastilla[i]->y && y <= objPastilla[i]->y + 2) {
				objPastilla[i]->BorrarPastilla();
				contador += 1;
				delete objPastilla[i];
				objPastilla.erase(objPastilla.begin() + i);
				i--;
				if (contador == 4) {
					cout << "FELICITACIONES !!! - UD. ES EL GANADOR !!!" << endl;
				}
			}
		}

	}
};