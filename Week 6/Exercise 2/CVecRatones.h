#pragma once
#include "CRaton.h"
#include <vector>

class CVecRatones {
private:
	vector<CRaton*>* vecRatones;
	int n_ratones_eliminados;
public:
	CVecRatones();
	~CVecRatones();
	void AgregarRaton();
	void MoverRatones();
	void EliminarRaton(CGato* obj);
	int getTamanioVector();
	int getN_ratones_eliminados();
};

CVecRatones::CVecRatones() {
	vecRatones = new vector<CRaton*>();
	n_ratones_eliminados = 0;
}
CVecRatones::~CVecRatones() {
	delete[] vecRatones;
}
void CVecRatones::AgregarRaton() {
	int aux_x, aux_y;
	aux_x = rand() % 50;
	aux_y = rand() % (15 - 2) + 2; //rand() % (mayor - menor) + menor
	CRaton* obj = new CRaton(aux_x, aux_y);
	vecRatones->push_back(obj);
}
void CVecRatones::MoverRatones() {
	for (int i = 0; i < vecRatones->size(); i++) {
		vecRatones->at(i)->Mover(' ');
	}
}
void CVecRatones::EliminarRaton(CGato* obj) {
	for (int i = 0; i < vecRatones->size(); i++) {
		if (vecRatones->at(i)->Colision(obj)) {
			//eliminar visualmente
			vecRatones->at(i)->Borrar();
			//eliminar logicamente
			vecRatones->erase(vecRatones->begin() + i);
			n_ratones_eliminados++;
		}
	}
}
int CVecRatones::getTamanioVector() {
	return this->vecRatones->size();
}
int CVecRatones::getN_ratones_eliminados() {
	return this->n_ratones_eliminados;
}