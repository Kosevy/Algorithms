#pragma once
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

class CContrasena {
private:
	int longitud;
	string* contrasena;
public:
	//CONSTRUCTORES
	CContrasena();
	CContrasena(int longitud);

	//setters
	void setLongitud(int longitud);
	void setLongitud(string* contrasena);

	//getters
	int getLongitud();
	string getContrasena();

	//Métodos a implementar
	bool esSeguro();
	void generarContrasena();
	void mostrarContrasena();
};

//arreglos

CContrasena::CContrasena() {
	this->longitud = 8;
	contrasena = new string[this->longitud];
}

CContrasena::CContrasena(int longitud) {
	this->longitud = longitud;
	contrasena = new string[this->longitud];
}

//set


void CContrasena::setLongitud(int longitud) {
	this->longitud = longitud;
}


void CContrasena::setLongitud(string* contrasena) {
	this->contrasena = contrasena;
}

//get

int CContrasena::getLongitud() {
	return this->longitud;
}

string CContrasena::getContrasena() {
	return *this->contrasena;
}

void CContrasena::generarContrasena() {
	int aux;
	for (int i = 0; i < this->longitud; i++) {
		//para validar un digito de la contrasena
		do {
			aux = rand() % (255) + 1;
		} while (!((aux >= 48 && aux <= 57) || (aux >= 65 && aux <= 90) || (aux >= 97 && aux <= 122)));
		//
		this->contrasena[i] = char(aux);
	}
}

//arrays

bool CContrasena::esSeguro() {
	bool resultado = false;
	int cc_mayus, cc_minus, cc_num;
	cc_mayus = cc_minus = cc_num = 0;

	for (int i = 0; i < this->longitud; i++) {
		if (this->contrasena[i] >= "A" && this->contrasena[i] <= "Z") {
			cc_mayus++;
		}
		if (this->contrasena[i] >= "a" && this->contrasena[i] <= "z") {
			cc_minus++;
		}
		if (this->contrasena[i] >= "a" && this->contrasena[i] <= "z") {
			cc_num++;
		}
	}

	if (cc_mayus > 2 && cc_minus > 1 && cc_num > 5) {
		resultado = true;
	}
	return resultado;
}

void CContrasena::mostrarContrasena() {
	for (int i = 0; i < this->longitud; i++) {
		cout << this->contrasena[i];
	}
	cout << " ->" << "Fuerte(0: F; 1: V) = " << this->esSeguro();
}