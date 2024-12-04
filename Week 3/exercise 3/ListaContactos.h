#pragma once
#include "Contacto.h"
#include <string>

class ListaContactos {
private:
	Contacto** registro;
	int num;
public:
	ListaContactos();
	~ListaContactos();

	// Metodos
	void registroContactos();
	void agregarDefault(Contacto *c);
	void modificarContactos();
	void eliminarContactos();
	void mostrarContactos();
	void contactosMayo();
	void contactosVaron();
	void contactosDama();
	void contactosFacebook();
	void contactosWhatsApp();
};

//constructor - destructor

ListaContactos::ListaContactos() {
	this->registro = nullptr; // para representar un valor nulo en punteros
	this->num = 0;
}

ListaContactos::~ListaContactos() {}

// Metodos

void ListaContactos::registroContactos() {

	string nombre; 
	string telefono;
	char sexo;
	string facultad;
	int fechaNacimiento;
	string email;
	string redSocial;

	cout << "Ingresa nombre: "; cin >> nombre;
	cout << "Ingresa numero telefonico: "; cin >> telefono;
	cout << "Ingresa sexo (H o M): "; cin >> sexo;
	cout << "Ingresa facultad: "; cin >> facultad;
	cout << "Ingresa fecha de nacimiento (yyyymmdd): "; cin >> fechaNacimiento;
	cout << "Ingresa email: "; cin >> email;
	cout << "Ingresa red social: "; cin >> redSocial;

	Contacto* c = new Contacto();

	
	c->setNombreContacto(nombre);
	c->setTelefono(telefono);
	c->setSexo(sexo);
	c->setFacultad(facultad);
	c->setfechaNacimiento(fechaNacimiento);
	c->setEmail(email);
	c->setRedSocial(redSocial);


	Contacto** tmp = new Contacto * [num + 1];

	for (int i = 0; i < num; i++) {
		tmp[i] = registro[i];
	}

	tmp[num] = c;

	if (registro != nullptr)
		delete[] registro;
	registro = tmp;
	num++;
}

void ListaContactos::modificarContactos() {
	int mod;
	cout << "Ingrese numero de contacto a modificar: "; cin >> mod;
	mod--;
	if (mod > num || mod < 0) {
		cout << "Numero invalido" << endl;
		return;
	}
	else {
		string nombre, telefono, facultad, email, redSocial;
		char sexo;
		int fechaNacimiento;

		cout << "Ingresa nombre: "; cin >> nombre;
		cout << "Ingresa numero telefonico: "; cin >> telefono;
		cout << "Ingresa sexo (H o M): "; cin >> sexo;
		cout << "Ingresa facultad: "; cin >> facultad;
		cout << "Ingresa fecha de nacimiento (yyyymmdd): "; cin >> fechaNacimiento;
		cout << "Ingresa email: "; cin >> email;
		cout << "Ingresa red social (Facebook o WhatsApp): "; cin >> redSocial;

		this->registro[mod]->setNombreContacto(nombre);
		this->registro[mod]->setTelefono(telefono);
		this->registro[mod]->setSexo(sexo);
		this->registro[mod]->setFacultad(facultad);
		this->registro[mod]->setfechaNacimiento(fechaNacimiento);
		this->registro[mod]->setEmail(email);
		this->registro[mod]->setRedSocial(redSocial);
	}
}

void ListaContactos::eliminarContactos() {
	Contacto** tmp = new Contacto * [num - 1];
	int mod;
	
	cout << "Ingrese el numero de contacto a eliminar: "; cin >> mod;
	mod--;

	if (mod < 0 || mod >= num) {
		cout << "Fuera de rango \n";
		return;
	}

	int j = 0;
	for (int i = 0; i < j; i++) {
		tmp[i] = registro[i];
		if (i == j) {
			for (int i = j; i < num; i++) {
				tmp[i] = registro[i + 1];
			}
		}
	}

	delete[] registro;
	registro = tmp;
	num--;
}

void ListaContactos::mostrarContactos() {
	for (int i = 0; i < num; i++) {
		registro[i]->mostrarDatos();
	}
	cout << endl;
}

void ListaContactos::agregarDefault(Contacto* c) {
	Contacto** tmp = new Contacto * [num + 1];
	for (int i = 0; i < num; i++) {
		tmp[i] = registro[i];
	}

	tmp[num] = c;

	if (registro != nullptr)
		delete[] registro;

	registro= tmp;
	num++;
}

void ListaContactos::contactosMayo() {
	cout << "Los contactos que cumplen en mayo son:\n";
	for (int i = 0; i < num; i++) {
		int fecha = registro[i]->getFechaNacimiento();
		string fechaStr = to_string(fecha).substr(4, 2);

		if (fechaStr == "05")
			registro[i]->mostrarDatos();
	}
}

void ListaContactos::contactosVaron() {
	cout << "Estos son los contactos que son varones:\n";
	for (int i = 0; i < num; i++) {
		if (registro[i]->getSexo() == 'H' || registro[i]->getSexo() == 'h')
			registro[i]->mostrarDatos();
	}
} 

void ListaContactos::contactosDama() {
	cout << "Estos son los contactos que son damas:\n";
	for (int i = 0; i < num; i++) {
		if (registro[i]->getSexo() == 'M' || registro[i]->getSexo() == 'm')
			registro[i]->mostrarDatos();
	}
}

void ListaContactos::contactosFacebook() {
	cout << "Estos son los contactos que tienen Facebook:\n";
	for (int i = 0; i < num; i++) {
		if (registro[i]->getRedSocial() == "Facebook" || 
			registro[i]->getRedSocial() == "facebook")
				registro[i]->mostrarDatos();
	}
}

void ListaContactos::contactosWhatsApp() {
	cout << "Estos son los contactos que tienen Facebook:\n";
	for (int i = 0; i < num; i++) {
		if (registro[i]->getRedSocial() == "WhatsApp" || 
			registro[i]->getRedSocial() == "whatsapp" || 
			registro[i]->getRedSocial() == "whatsApp" || 
			registro[i]->getRedSocial() == "Whatsapp")
				registro[i]->mostrarDatos();
	}
}