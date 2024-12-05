#pragma once


#include <iostream>
#include<string>

using namespace std;

class Motorizado {
private:
	string nombre;
	string apellido;
	string placa;
	int kilometraje;
	string empresa;

public:
	Motorizado(string n, string a, string p, int km, string em) {
		nombre = n;
		apellido = a;
		placa = p;
		kilometraje = km;
		empresa = em;
	};

	~Motorizado() {};

	string getNombre() { return nombre; };
	string getApellido() { return apellido; };
	string getPlaca() { return placa; };
	int getKilometraje() { return kilometraje; };
	string getEmpresa() { return empresa; };

	int Precio() {
		return kilometraje * 1.5;
	};
};