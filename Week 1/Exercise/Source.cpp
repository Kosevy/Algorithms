#include "CContrasena.h"

int main() {
	srand(int(time(NULL)));
	//default -> longitud de 8
	CContrasena* objContrasena = new CContrasena();
	objContrasena->generarContrasena();
	objContrasena->mostrarContrasena();

	cout << endl;

	//custom -> longitud con parametros
	CContrasena* objContrasena2 = new CContrasena(30);
	objContrasena2->generarContrasena();
	objContrasena2->mostrarContrasena();

	cout << endl << "arreglo: " << endl;

	//array dinamico de contrasena
	int n = 10;
	int longitud_aleatoria;

	//arreglo de contrasena
	CContrasena* arrContrasena = new CContrasena[n];
	for (int i = 0; i < n; i++) {
		longitud_aleatoria = rand() % (30 - 5) + 5; //rand() % (mayor - menor) +  menor
		arrContrasena[i] = CContrasena(longitud_aleatoria);
		arrContrasena[i].generarContrasena();
		arrContrasena[i].mostrarContrasena();
		cout << endl;
	}

	getch();
	return 0;
}