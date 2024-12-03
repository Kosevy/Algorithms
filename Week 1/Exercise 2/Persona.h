#pragma once
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

class Persona {
private:
	//atributos
	string nombre;
	int edad;
	int dni;
	char sexo;
	double peso;
	double altura;
public:
	//Constructores
	Persona();
	Persona(string p, int e, char s);
	Persona(string p, int e, int d, char s, double pe, double al);

	//set
	void setNombre(string p);
	void setEdad(int e);
	void setDni(int d);
	void setSexo(char s);
	void setPeso(double pe);
	void setAltura(double al);

	//get
	string getNombre();
	int getEdad();
	int getDni();
	char getSexo();
	double getPeso();
	double getAltura();

	//metodos a implementar
	bool esMayorDeEdad();
	bool comprobarSexo(char sexo);
	void toString();
	void generaDNI();
	void verificaPeso();
	void verificaEdad();
};

//Valores de Constructores

Persona::Persona() {
	this->nombre = "Diego";
	this->edad = 20;
	this->dni = 44424234;
	this->sexo = 'H';
	this->peso = 62.5;
	this->altura = 1.65;
}

Persona::Persona(string _nombre, int _edad, char _sexo) {
	this->nombre = _nombre;
	this->edad = _edad;
	this->dni = 35345355	;
	this->sexo = _sexo;
	this->peso = 62.5;
	this->altura = 1.65;
}

Persona::Persona(string _nombre, int _edad, int _dni, char _sexo, double _peso, double _altura ) {
	this->nombre = _nombre;
	this->edad = _edad;
	this->dni = _dni;
	this->sexo = _sexo;
	this->peso = _peso;
	this->altura = _altura;
}

//metodos de acceso a los atributos

//setters

void Persona::setNombre(string p) {
	this->nombre = p;
}

void Persona::setEdad(int e) {
	this->edad = e;
}

//no es necesario
//void Persona::setDni(int d) {
//	this->dni = d;
//}

void Persona::setSexo(char s) {
	this->sexo = s;
}

void Persona::setPeso(double pe) {
	this->peso = pe;
}

void Persona::setAltura(double al) {
	this->altura = al;
}

//getters

string Persona::getNombre() {
	return this->nombre;
}

int Persona::getEdad() {
	return this->edad;
}

//no es necesario
//int Persona::getDni() {
//	return this->dni;
//}

char Persona::getSexo() {
	return this->sexo;
}

double Persona::getPeso() {
	return this->peso;
}

double Persona::getAltura() {
	return this->altura;
}

//metodos de accion

bool Persona::esMayorDeEdad() {
	bool resultado;

	if (this->edad >= 18) {
		resultado = true;
	}
	if (this->edad < 18) {
		resultado = false;
	}
	return resultado;
}

void Persona::verificaEdad() {
	cout << " -> " << "Es mayor de edad (0: NO; 1: SI) = " << this->esMayorDeEdad();
}


bool Persona::comprobarSexo(char sexo) {
	bool resultado = false;
	if (this->sexo == 'H' || this->sexo == 'h' || this->sexo == 'M' || this->sexo == 'm') {
		return resultado = true;
	}
	else {
		return resultado = 'H';
	}
}

void Persona::toString() {
	cout << "Nombre: " << this->nombre << ", Edad: " << this->edad
		<< ", DNI: " << this->dni << ", Sexo: " << this->sexo
		<< ", Peso: " << this->peso << ", Altura: " << this->altura << endl;
}

void Persona::generaDNI() {
	this->dni = 0;
	for (int i = 0; i < 8; i++) {
		this->dni = this->dni * 10 + rand() % 10;
	}
}

void Persona::verificaPeso() {
	double imc = this->peso / (this->altura * this->altura);
	if (imc < 20) {
		cout << " -> " << "Está por debajo de su peso ideal";
	}
	else if (imc >= 20 && imc <= 25) {
		cout << " -> " << "Esta en su peso ideal";
	}
	else {
		cout << " -> " << "Tiene sobrepeso";
	}
}