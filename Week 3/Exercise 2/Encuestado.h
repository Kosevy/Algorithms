#pragma once
#include <iostream>
#include <conio.h>
#include <string>

using namespace System;
using namespace std;

class Encuestado {
private:
	int dni;
	char tipo;
public:
	//Constructores
	Encuestado() {
		dni = 0;
		tipo = '\0';
	}

	Encuestado(int d, char t) {
		dni = d;
		tipo = t;
	}

	//metodos acceso
	//getters
	int getDni() { return dni; }
	char getTipo() { return tipo; }


	//setters
	void setDni(int d) { dni = d; }
	void setTipo(char t) { tipo = t; }
	

	//metodos acciones
	void mostrarDatos();
};

//implementacion

void Encuestado::mostrarDatos() {
	cout << "DNI: " << dni << endl;
	cout << "Tipo de leche preferida: " << tipo << endl;
}
