#pragma once
#include <vector>
#include "Eclipse.h"

class CVectorEclipse {
private:
	int tam;
	vector<CEclipse*>* arrEclipse;
public:
	CVectorEclipse();
	~CVectorEclipse();
	int getTam();
	//metodos propias de la clase
	void agregar();
	void modificarIndex(int i);
	void eliminarIndex(int i);
	void imprimirIndex(int i);
	void imprimirTodos();
	void visibilidadEuropa();
};

CVectorEclipse::CVectorEclipse() {
	this->tam = 0;
	arrEclipse = new vector<CEclipse*>();
}
CVectorEclipse::~CVectorEclipse() {
	delete[] arrEclipse;
}
int CVectorEclipse::getTam() {
	return this->tam;
}

void CVectorEclipse::agregar() {
	CEclipse* obj = new CEclipse();
	obj->generarAleatorio();
	arrEclipse->push_back(obj);
	this->tam++;
}
void CVectorEclipse::modificarIndex(int i) {
	char aux_tipo;
	long aux_fecha;
	int aux_hora;
	bool aux_sismo;
	bool aux_lluvia;
	string aux_visibilidad;
	cout << "Objeto a modificar: " << endl;
	this->imprimirIndex(i);
	cout << "Digite el nuevo tipo de eclipse: ";
	cin >> aux_tipo;
	cout << "Digite la nueva fecha: ";
	cin >> aux_fecha;
	cout << "Digite la nueva hora: ";
	cin >> aux_hora;
	cout << "Digite si hay sismo: ";
	cin >> aux_sismo;
	cout << "Digite si hay lluvia: ";
	cin >> aux_lluvia;
	cout << "Digite la nueva visibilidad: ";
	cin >> aux_visibilidad;

	arrEclipse->at(i)->setTipo(aux_tipo);
	arrEclipse->at(i)->setFecha(aux_fecha);
	arrEclipse->at(i)->setHora(aux_hora);
	arrEclipse->at(i)->setSismo(aux_sismo);
	arrEclipse->at(i)->setLluvia(aux_lluvia);
	arrEclipse->at(i)->setVisibilidad(aux_visibilidad);
	cout << "El objeto se ha modificado correctamente" << endl;
}
void CVectorEclipse::eliminarIndex(int i) {
	cout << "Esta eliminando este objeto del vector: " << endl;
	this->imprimirIndex(i);
	arrEclipse->erase(arrEclipse->begin() + i);
	cout << "El objeto se elimino correctamente" << endl;
	this->tam--;
}
void CVectorEclipse::imprimirIndex(int i) {
	arrEclipse->at(i)->imprimir();
}
void CVectorEclipse::imprimirTodos() {
	cout << "Los elementos del vector son: " << endl;
	for (int n = 0; n < arrEclipse->size(); n++) {
		arrEclipse->at(n)->imprimir();
	}
}
void CVectorEclipse::visibilidadEuropa() {
	for (int n = 0; n < arrEclipse->size(); n++) {
		if (arrEclipse->at(n)->getVisibilidad() == "EU") {
			this->imprimirIndex(n);
		}
	}
}