#pragma once
#include "Encuestado.h"

class ArrEncuestados {
private:
	Encuestado** encuestados;
	int n;
public:
	ArrEncuestados() {
		encuestados = nullptr;
		n = 0;
	}
	~ArrEncuestados();

	void generarDatos();
	void mostrarEncuestados();
    void eliminarEncuestado();
};


void ArrEncuestados::generarDatos() {
    Encuestado** nuevoArreglo = new Encuestado * [n + 1];

    for (int i = 0; i < n; i++) {
        nuevoArreglo[i] = encuestados[i];
    }
    
    int aux1 = 1000 + rand() % 9000; 
    char aux2;

    do {
        aux2 = (char)(49 + rand() % 4);
    } while (aux2 < '1' || aux2 > '4');

    nuevoArreglo[n] = new Encuestado(aux1, aux2);

    if (encuestados != nullptr) {
        delete[] encuestados;
    }

    encuestados = nuevoArreglo;
    n++;
}

void ArrEncuestados::mostrarEncuestados() {
	cout << "Lista de encuestados:\n";
    cout << "=====================\n";
	for (int i = 0; i < n; i++) {
		cout << "Encuestado nro. " << i + 1 << ":" << endl;
		encuestados[i]->mostrarDatos();
		cout << endl;
	}
}

void ArrEncuestados::eliminarEncuestado() {
    int elim;

    cout << "Ingrese DNI del encuestado a eliminar: "; cin >> elim;

    int index = -1;
    for (int i = 0; i < n; i++) {
        if (encuestados[i]->getDni() == elim) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        cout << "Encuestado con DNI " << elim << " no encontrado.\n";
        return;
    }

    Encuestado** nuevoArreglo = new Encuestado * [n - 1];

    for (int i = 0, j = 0; i < n; i++) {
        if (i != index) {
            nuevoArreglo[j] = encuestados[i];
            j++;
        }
        else {
            delete encuestados[i];
        }
    }

    delete[] encuestados;
    encuestados = nuevoArreglo;
    n--;

    cout << "El encuestado con DNI " << elim << " ha sido eliminado.\n";
}