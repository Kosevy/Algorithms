#include <vector>
#include "iostream"
using namespace System;
using namespace std;

public class Empleado {
public:
	int horas;
	float sueldo;
	Empleado(int horas, float sueldo) {
		this->horas = horas;
		this->sueldo = sueldo;
	}
	~Empleado() {}

	virtual float calcularLiquidacion() { return 0; };

};

public class ERegular : public Empleado {
public:
	ERegular(int horas, float sueldo) :Empleado(horas, sueldo) {}

	float calcularLiquidacion() {
		return horas* sueldo;
	}
};

public class EComercial : public Empleado {
private:
	int basico;
public:
	EComercial(int horas, float sueldo) :Empleado(horas, sueldo) {
		basico = 800;
	}

	float calcularLiquidacion() {
		return basico + (sueldo * horas);
	}
};

public class EEjecutivo : public Empleado {
public:
	EEjecutivo(int horas, float sueldo) : Empleado(horas, sueldo) {}

	float calcularLiquidacion() {
		return horas * sueldo * 1.02;
	}
};

public class Gestion{
private:
	vector<Empleado*> empleados;
public:
	Gestion() {}

	void agregarEmpleado(ERegular* empleado) {
		empleados.push_back(empleado);
	}

	void agregarEmpleado(EComercial* empleado) {
		empleados.push_back(empleado);
	}

	void agregarEmpleado(EEjecutivo* empleado) {
		empleados.push_back(empleado);
	}
	
	void calcularSueldos() {
		for (int i = 0; i < empleados.size(); i++) {
			cout << "sueldo: " << empleados[i]->calcularLiquidacion() << endl; 
		}
	}

	void diferenciaSueldos() {
		if (empleados.size() >= 2) {
			float diferencia = empleados[0]->calcularLiquidacion() - empleados[1]->calcularLiquidacion();
			if (diferencia < 0) {
				diferencia *= -1;
			}
			cout << "Diferencia de sueldos: " << diferencia << endl;
		}
	}
};

int main() {
	Gestion G;
	EComercial* comercial = new EComercial(8, 800);
	ERegular* regular = new ERegular(8, 800);
	EEjecutivo* ejecutivo = new EEjecutivo(8, 1200);

	G.agregarEmpleado(comercial);
	G.agregarEmpleado(regular);
	G.agregarEmpleado(ejecutivo);
	G.calcularSueldos();
	G.diferenciaSueldos();
	
	system("pause");
	return 0;
}