#include "ArrEncuestados.h"

int menu() {
	char opcion;

	do {
		cout << "\nMenu de opciones" << endl;
		cout << "================" << endl;
		cout << "1. Generar un encuestado: " << endl;
		cout << "2. Mostrar los encuestados: " << endl;
		cout << "3. Eliminar encuestado: " << endl;
		cout << "4. Salir" << endl;
		cout << "Ingrese opcion: "; cin >> opcion;
	} while (opcion < '1' || opcion > '4');

	return opcion;
}

int main() {
	srand(int(time(NULL)));
	ArrEncuestados* objEncuestado = new ArrEncuestados();

	while (true) {
		char op = menu();
		switch (op) {
		case '1':
			cout << "\n";
			objEncuestado->generarDatos();
			cout << "Se ha generado un nuevo encuestado." << endl;
			break;
		case '2':
			cout << "\n";
			objEncuestado->mostrarEncuestados();
			break;
		case '3':
			cout << "\n";
			objEncuestado->eliminarEncuestado();
			break;
		case '4':
			return 0;
		}
		system("pause>0");
		system("cls");
	}
}