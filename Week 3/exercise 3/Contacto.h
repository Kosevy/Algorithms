#pragma once
#include <iostream>
#include <conio.h>

using namespace System;
using namespace std;

class Contacto {
private:
	string nombreContacto;
	string telefono;
	char sexo;
	string facultad;
	int fechaNacimiento;
	string email;
	string redSocial;
public:
	//constructores
	Contacto();
	Contacto(string, string, char, string, int, string, string);
	~Contacto();

	//setters
	void setNombreContacto(string);
	void setTelefono(string);
	void setSexo(char);
	void setFacultad(string);
	void setfechaNacimiento(int);
	void setEmail(string);
	void setRedSocial(string);

	//getters
	string getNombreContacto();
	string getTelefono();
	char getSexo();
	string getFacultad();
	int getFechaNacimiento();
	string getEmail();
	string getRedSocial();

	//metodos accion

	void mostrarDatos();
};

//metodos acceso

//valores constructores

Contacto::Contacto() {
	this->nombreContacto = "";
	this->telefono = "";
	this->sexo = '\0';
	this->facultad = "";
	this->fechaNacimiento = 0;
	this->email = "",
	this->redSocial = "";
};

Contacto::Contacto(string no, string tf, char s, string fa, int fe, string e, string re) {
	this->nombreContacto = no;
	this->telefono = tf;
	this->sexo = s;
	this->facultad = fa;
	this->fechaNacimiento = fe;
	this->email = e,
	this->redSocial = re;
};

Contacto::~Contacto(){};

//set

void Contacto::setNombreContacto(string no) {
	this->nombreContacto = no;
}

void Contacto::setTelefono(string tf) {
	this->telefono = tf;
}


void Contacto::setSexo(char s) {
	this->sexo = s;
}

void Contacto::setFacultad(string fa) {
	this->facultad = fa;
}

void Contacto::setfechaNacimiento(int fe) {
	this->fechaNacimiento = fe;
}

void Contacto::setEmail(string e) {
	this->email = e;
}

void Contacto::setRedSocial(string re) {
	this->redSocial = re;
}

//get

string Contacto::getNombreContacto() {
	return this->nombreContacto;
}

string Contacto::getTelefono() {
	return this->telefono;
}

char Contacto::getSexo() {
	return this->sexo;
}

string Contacto::getFacultad() {
	return this->facultad;
}

int Contacto::getFechaNacimiento() {
	return this->fechaNacimiento;
}

string Contacto::getEmail() {
	return this->email;
}

string Contacto::getRedSocial() {
	return this->redSocial;
}

void Contacto::mostrarDatos() {
	cout << "Nombre: " << this->nombreContacto << endl;
	cout << "Telefono: " << this->telefono << endl;
	cout << "Sexo: " << this->sexo << endl;
	cout << "Facultad" << this->facultad << endl;
	cout << "Fecha de Nacimiento: " << this->fechaNacimiento << endl;
	cout << "Email: " << this->email << endl;
	cout << "Red Social: " << this->redSocial << endl;
}
