#pragma once
#include <vector>
#include "CTerrestre.h"
#include "CCarro.h"

class CVecTerrestre {
private:
	vector<CTerrestre*>* vecTerrestre;
public:
	CVecTerrestre();
	~CVecTerrestre();
	void AgregarTerrestre(int tipo, int x, int y, int dx, int dy);
	void MoverTerrestre(int anchoC, int largoC);
	bool ColisionTerrestre(CJugador* objJugador);
};

CVecTerrestre::CVecTerrestre() {
	vecTerrestre = new vector<CTerrestre*>();
}
CVecTerrestre::~CVecTerrestre() {
	delete[] vecTerrestre;
}
void CVecTerrestre::AgregarTerrestre(int tipo, int x, int y, int dx, int dy) {
	CTerrestre* objTerrestre;
	switch (tipo)
	{
	case 1:
		//Carro
		objTerrestre = new CCarro(x, y, dx, dy);
		break;
	}
	vecTerrestre->push_back(objTerrestre);
}
void CVecTerrestre::MoverTerrestre(int anchoC, int largoC) {
	for (int i = 0; i < vecTerrestre->size(); i++) {
		vecTerrestre->at(i)->Borrar();

		if (vecTerrestre->at(i)->getX() + vecTerrestre->at(i)->getDx() < 0 ||
			vecTerrestre->at(i)->getX() + vecTerrestre->at(i)->getAncho() + vecTerrestre->at(i)->getDx() > anchoC) {
			vecTerrestre->at(i)->setDx(vecTerrestre->at(i)->getDx() * -1);
		}

		if (vecTerrestre->at(i)->getY() + vecTerrestre->at(i)->getDy() < 0 ||
			vecTerrestre->at(i)->getY() + vecTerrestre->at(i)->getLargo() + vecTerrestre->at(i)->getDy() > anchoC) {
			vecTerrestre->at(i)->setDy(vecTerrestre->at(i)->getDy() * -1);
		}
		vecTerrestre->at(i)->setX(vecTerrestre->at(i)->getX() + vecTerrestre->at(i)->getDx()); //mov horizontal
		vecTerrestre->at(i)->setY(vecTerrestre->at(i)->getY() + vecTerrestre->at(i)->getDy()); // mov vertical

		vecTerrestre->at(i)->Dibujar();
	}
}
bool CVecTerrestre::ColisionTerrestre(CJugador* objJugador) {
	bool existe_colison = false;
	for (int i = 0; i < vecTerrestre->size(); i++) {
		if (vecTerrestre->at(i)->Colision(objJugador)) {
			existe_colison = true;
		}
	}
	return existe_colison;
}