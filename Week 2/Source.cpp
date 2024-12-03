#include "VectorEclipse.h"

int main() {
	//resetear la semilla de valores aleatorios
	srand(int(time(NULL)));
	CVectorEclipse* objVectorEclipse = new CVectorEclipse();
	int opcion;
	int aux_i;
	bool flg = true;

	while (flg) {
		system("cls");
		cout << "1. Agregar" << endl;
		cout << "2. Modificar por indice" << endl;
		cout << "3. Eliminar por indice" << endl;
		cout << "4. Listar por indice" << endl;
		cout << "5. Listar todos" << endl;
		cout << "6. Reporte de visibilidad en Europa" << endl;
		cout << "7. Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			system("cls");
			cout << "Su objeto se creo aleatoriamente" << endl;
			objVectorEclipse->agregar();
			objVectorEclipse->imprimirIndex(objVectorEclipse->getTam() - 1);
			break;
		case 2:
			system("cls");
			cout << "Digite el indice a modificar: " << endl;
			cin >> aux_i;
			objVectorEclipse->modificarIndex(aux_i);
			break;
		case 3:
			system("cls");
			cout << "Digite el indice a eliminar: " << endl;
			cin >> aux_i;
			objVectorEclipse->eliminarIndex(aux_i);
			break;
		case 4:
			system("cls");
			cout << "Digite el indice a listar: " << endl;
			cin >> aux_i;
			objVectorEclipse->imprimirIndex(aux_i);
			break;
		case 5:
			system("cls");
			objVectorEclipse->imprimirTodos();
			break;
		case 6:
			system("cls");
			objVectorEclipse->visibilidadEuropa();
			break;
		case 7:
			flg = false;
			break;
		}
		getch();
	}
	getch();
	return 0;
}