#pragma once
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

class Cuenta {
private:
	//atributos
	string titular;
	double cantidad;
public:
	//constructores
	Cuenta::Cuenta(string titular);
	Cuenta::Cuenta(string titular, double cantidad);

	//metodos de ACCESO
	void setTitular(string t);
	void setCantidad(double c);

	//get
	string getTitular();
	double getCantidad();

	//metodos accion
	void ingresar(double cantidad);
	void retirar(double cantidad);
};

//implementacion

Cuenta::Cuenta(string titular) {
	this->titular = "Anon";
};

Cuenta::Cuenta(string titular, double cantidad) {
	this->titular = "Anon";
	this->cantidad = 720.5;
};

//metodos de acceso

//setters

void Cuenta::setTitular(string t) {
	this->titular = t;
};

void Cuenta::setCantidad(double c) {
	this->cantidad = c;
};

//getters

string Cuenta::getTitular() {
	return this->titular;
}

double Cuenta::getCantidad() {
	return this -> cantidad;
}

//metodos de accion

void Cuenta::ingresar(double cantidadIngresada) {
	if (cantidadIngresada > 0) {
		cantidad += cantidadIngresada;
	}
};

void Cuenta::retirar(double cantidadRetirada) {
		if (cantidadRetirada > cantidad) {
			cantidad = 0;
		}
		else {
			cantidad -= cantidadRetirada;
		}
};