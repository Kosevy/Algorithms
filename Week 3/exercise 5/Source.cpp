#include "ArrMotorizados.h"
#include <conio.h>

using namespace System;

int Menu() {
	int op;

	do {
		cout << endl << "MENU" << endl;
		cout << "1. Agregar motorizado" << endl;
		cout << "2. Eliminar motorizado" << endl;
		cout << "3. Mostrar todos los motorizados" << endl;
		cout << "4. Motorizados Mapi" << endl;
		cout << "5. Motorizados Glopo" << endl;
		cout << "Seleccione la opcion: "; cin >> op;
	} while (op < 1 || op>5);
	return op;
}

void PresionaContinuar() {
	cout << endl << "Presiona una tecla para continuar...";
	_getch();
}

int main() {
	setlocale(LC_ALL, "");

	Motorizado* motorizado;
	ListaMotorizados* arregloM = new ListaMotorizados();

	int op;
	int ind;
	string nombre;
	string apellido;
	string placa;
	int kilometraje;
	string empresa;

	while (true) {
		system("cls");

		op = Menu();

		switch (op) {
		case 1:
			cout << endl << "Ingrese los datos del motorizado: " << endl;
			cout << "Nombre: "; cin >> nombre;
			cout << "Apellido: "; cin >> apellido;
			cout << "Placa: "; cin >> placa;
			cout << "Kilometraje: "; cin >> kilometraje;
			cout << "Empresa(Mapi, Glopo): "; cin >> empresa;

			motorizado = new Motorizado(nombre, apellido, placa, kilometraje, empresa);

			arregloM->AgregarMotorizados(motorizado);
			PresionaContinuar();
			break;

		case 4:
			arregloM->MotorizadoMapi();
			PresionaContinuar();
			break;



		}




	}

	_getch();
	return 0;
}