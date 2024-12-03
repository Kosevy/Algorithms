#include "Cuenta.h"

int main() {
	//propiedades
	string titular;
	double cantidad;

	//con cantidad
	Cuenta* obj1 = new Cuenta("Anon");

	//sin cantidad
	Cuenta* obj2 = new Cuenta("Anon", 720.5);

	//input & output
	cout << "Cuenta nro. 1: " << obj1->getTitular() << endl;
	cout << "============== " << endl;

	cout << endl << "Cuenta nro. 2: " << obj2->getTitular() << endl;
	cout << "============== " << endl;
	cout << "Monto actual: " << obj2->getCantidad() << endl;

	cout << "Ingrese monto a depositar: "; cin >> cantidad;
	obj2->ingresar(cantidad);
	cout << "Monto total: " << obj2->getCantidad() << endl;

	cout << "Ingrese monto a retirar: "; cin >> cantidad;
	obj2->retirar(cantidad);
	cout << "Monto total: " << obj2->getCantidad() << endl;

	_getch();
	return 0;
};