#include "Persona.h"

int main() {

	string nombre;
	int edad;
	int dni;
	char sexo;
	double peso;
	double altura;


	//default
	Persona* obj1 = new Persona();

	//custom
	Persona* obj2 = new Persona();


	//input
	cout << "DATOS DE LA PERSONA: " << endl;
	cout << "---------------------" << endl;
	cout << "Ingrese Nombre: "; cin >> nombre;
	obj2->setNombre(nombre);
	cout << "Ingrese edad: "; cin >> edad;
	obj2->setEdad(edad);
	cout << "Ingrese sexo: "; cin >> sexo;
	obj2->setSexo(sexo);
	cout << "Ingrese peso: "; cin >> peso;
	obj2->setPeso(peso);
	cout << "Ingrese altura: "; cin >> altura;
	obj2->setAltura(altura);

	//output 

	Persona* arrPersona = new Persona;

	cout << endl << "DATOS DE LA PERSONA 1: " << endl;
	cout << "---------------------" << endl;
	cout << "Nombre: " << obj2->getNombre() << endl;
	cout << "Edad: " << obj2->getEdad() << endl;
	cout << "Sexo:" << obj2->getSexo() << endl;
	cout << "Peso: " << obj2->getPeso() << endl;
	cout << "Altura: " << obj2->getAltura() << endl;
	obj2->verificaPeso(); cout << endl;
	obj2->verificaEdad(); cout << endl;

	cout << endl << "DATOS DE LA PERSONA 2: " << endl;
	cout << "---------------------" << endl;
	cout << "Nombre: " << obj2->getNombre() << endl;
	cout << "Edad: " << obj2->getEdad() << endl;
	cout << "Sexo:" << obj2->getSexo() << endl;
	cout << "Peso: " << obj1->getPeso() << endl;
	cout << "Altura: " << obj1->getAltura() << endl;
	obj1->verificaPeso(); cout << endl;
	obj2->verificaEdad(); cout << endl;

	cout << endl << "DATOS DE LA PERSONA 3: " << endl;
	cout << "---------------------" << endl;
	cout << "Nombre: " << obj1->getNombre() << endl;
	cout << "Edad: " << obj1->getEdad() << endl;
	cout << "Sexo:" << obj1->getSexo() << endl;
	cout << "Peso: " << obj1->getPeso() << endl;
	cout << "Altura: " << obj1->getAltura() << endl;
	obj1->verificaPeso(); cout << endl;
	obj1->verificaEdad(); cout << endl;

	_getch();
	return 0;
}