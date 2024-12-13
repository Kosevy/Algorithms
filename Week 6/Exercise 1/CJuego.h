#pragma once
#include "CVecTerrestre.h"
#include <conio.h>

class CJuego {
private:
	int anchoC;
	int largoC;
	char tecla;
	CVecTerrestre* objVecTerrestre;
	CJugador* objJugador;
public:
	CJuego();
	~CJuego();
	void Jugar();
	void Salir();
	void Ganar();
};

CJuego::CJuego() {
	this->anchoC = Console::WindowWidth;
	this->largoC = Console::WindowHeight;

	objVecTerrestre = new CVecTerrestre();
	objJugador = new CJugador(anchoC / 2, largoC - 1, 1, 1, 1, 1);
}
CJuego::~CJuego() {
	delete[] objVecTerrestre;
	delete objJugador;
}
void CJuego::Jugar() {
	objVecTerrestre->AgregarTerrestre(1, 1, 0, 1, 0);
	objVecTerrestre->AgregarTerrestre(1, 1, 10, 2, 0);
	objVecTerrestre->AgregarTerrestre(1, 1, 15, 3, 0);
	objJugador->Dibujar();
	while (true) {
		//Movimeinto del personaje
		if (kbhit()) {
			tecla = getch();
			if (tecla == 27) {
				Salir();
				break;
			}
			objJugador->Mover(tecla, anchoC, largoC);
			if (objJugador->getY() == 0) {
				//cruzo la pista
				Ganar();
				break;
			}
		}
		objVecTerrestre->MoverTerrestre(anchoC, largoC);
		if (objVecTerrestre->ColisionTerrestre(objJugador)) {
			objJugador->setX(anchoC / 2);
			objJugador->setY(largoC - 1);
			objJugador->Dibujar();
		}
		_sleep(100);
	}
}
void CJuego::Salir() {
	system("cls");
	cout << "\tGracias por jugar, vuelve pronto!!!";
}
void CJuego::Ganar() {
	system("cls");
	cout << "Felicitaciones, cruzo satisfactoriamente la pista";
}