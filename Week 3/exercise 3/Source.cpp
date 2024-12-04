#include "Contacto.h"
#include "ListaContactos.h"

int menu() {
	char opcion;

	do {
		cout << "\nMenu de opciones" << endl;
		cout << "================" << endl;
		cout << "1. Registrar un contacto: " << endl;
		cout << "2. Modificar un contacto: " << endl;
		cout << "3. Eliminar un contacto: " << endl;
		cout << "4. Mostrar todos los contactos: " << endl;
		cout << "5. Mostrar contactos con cumpleanos en mayo: " << endl;
		cout << "6. Mostrar contactos varones: " << endl;
		cout << "7. Mostrar contactos damas: " << endl;
		cout << "8. Mostrar contactos que tienen red social Facebook: " << endl;
		cout << "9. Mostrar contactos que tienen red social WhatsApp: " << endl;
		cout << "10. Salir" << endl;
		cout << "Ingrese opcion: "; cin >> opcion;
	} while (opcion < '1' || opcion > '10');

	return opcion;
}

int main() {
	Contacto* c1 = new Contacto("Diego", "982410414", 'H', "Ingenieria", 20030516, "clvy@gmail.com", "Whatsapp");

	ListaContactos* lista = new ListaContactos();
	lista->agregarDefault(c1);

	while (true) {
		char opcion = menu();

			switch (opcion) {
			case '1':
				cout << "\n";
				lista->registroContactos();
				break;
			case '2':
				cout << "\n";
				lista->modificarContactos();
				break;
			case '3':
				cout << "\n";
				lista->eliminarContactos();
				break;
			case '4':
				cout << "\n";
				lista->mostrarContactos();
				break;
			case '5':
				cout << "\n";
				lista->contactosMayo();
				break;
			case '6':
				cout << "\n";
				lista->contactosVaron();
				break;
			case '7':
				cout << "\n";
				lista->contactosDama();
				break;
			case '8':
				cout << "\n";
				lista->contactosFacebook();
				break;
			case '9':
				cout << "\n";
				lista->contactosWhatsApp();
				break;
			case '10':
				return 0;
			}
	}
}