#pragma once
#include <iostream>
#include <conio.h>

using namespace std;
using namespace System;

class CEclipse {
private:
	char tipo;
	long fecha; //20240824
	int hora;
	bool sismo;
	bool lluvia;
	string visibilidad; // AS

public:
	CEclipse();
	CEclipse(char tipo, long fecha, int hora, bool sismo, bool lluvia, string visibilidad);
	~CEclipse();
	//getters
	//nomenclatura camelcase
	char getTipo();
	long getFecha();
	int getHora();
	bool getSismo();
	bool getLluiva();
	string getVisibilidad();

	//setters
	void setTipo(char tipo);
	void setFecha(long fecha);
	void setHora(int hora);
	void setSismo(bool sismo);
	void setLluvia(bool lluvia);
	void setVisibilidad(string visibilidad);

	//Metodos adicionales
	void generarAleatorio();
	void imprimir();
};

CEclipse::CEclipse() {
	this->tipo = ' ';
	this->fecha = 0;
	this->hora = 0;
	this->sismo = false;
	this->lluvia = false;
	this->visibilidad = " ";
}
CEclipse::CEclipse(char tipo, long fecha, int hora, bool sismo, bool lluvia, string visibilidad) {
	this->tipo = tipo;
	this->fecha = fecha;
	this->hora = hora;
	this->sismo = sismo;
	this->lluvia = lluvia;
	this->visibilidad = visibilidad;
}
CEclipse::~CEclipse() {}

char CEclipse::getTipo() {
	return this->tipo;
}
long CEclipse::getFecha() {
	return this->fecha;
}
int CEclipse::getHora() {
	return this->hora;
}
bool CEclipse::getSismo() {
	return this->sismo;
}
bool CEclipse::getLluiva() {
	return this->lluvia;
}
string CEclipse::getVisibilidad() {
	return this->visibilidad;
}


void CEclipse::setTipo(char tipo) {
	this->tipo = tipo;
}
void CEclipse::setFecha(long fecha) {
	this->fecha = fecha;
}
void CEclipse::setHora(int hora) {
	this->hora = hora;
}
void CEclipse::setSismo(bool sismo) {
	this->sismo = sismo;
}
void CEclipse::setLluvia(bool lluvia) {
	this->lluvia = lluvia;
}
void CEclipse::setVisibilidad(string visibilidad) {
	this->visibilidad = visibilidad;
}


void CEclipse::generarAleatorio() {
	Random x;
	int aux_tipo, aux_anio, aux_mes, aux_dia, aux_hora, aux_sismo, aux_lluvia, aux_visibilidad;
	long aux_fecha;

	aux_tipo = x.Next(1, 3); // [1,3>
	switch (aux_tipo) {
	case 1:
		this->tipo = 'S';
		break;
	case 2:
		this->tipo = 'L';
		break;
	}
	aux_anio = x.Next(2014, 2025);
	aux_mes = x.Next(1, 13);
	aux_dia = x.Next(1, 29);
	//20240824
	aux_fecha = aux_anio * 10000 + aux_mes * 100 + aux_dia;
	this->fecha = aux_fecha;

	aux_hora = x.Next(1, 25);
	this->hora = aux_hora * 100; // 14 -> 1400

	aux_sismo = x.Next(0, 2);
	this->sismo = aux_sismo;

	aux_lluvia = x.Next(0, 2);
	this->lluvia = aux_lluvia;

	aux_visibilidad = x.Next(1, 6);
	switch (aux_visibilidad)
	{
	case 1:
		this->visibilidad = "AS";
		break;
	case 2:
		this->visibilidad = "EU";
		break;
	case 3:
		this->visibilidad = "AF";
		break;
	case 4:
		this->visibilidad = "AN";
		break;
	case 5:
		this->visibilidad = "AA";
		break;
	}
}

void CEclipse::imprimir() {
	cout << "{" << endl;
	cout << "tipo: " << this->tipo << "," << endl;
	cout << "fecha: " << this->fecha << "," << endl;
	cout << "hora: " << this->hora << "," << endl;
	cout << "sismo: " << this->sismo << "," << endl;
	cout << "lluvia: " << this->lluvia << "," << endl;
	cout << "visibilidad: " << this->visibilidad << endl;
	cout << "}" << endl;
}