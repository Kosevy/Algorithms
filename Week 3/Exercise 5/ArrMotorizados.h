#pragma once

#include "Motorizado.h"

class ListaMotorizados {
private:
	Motorizado** listaMot;
	int nMot;

public:
	ListaMotorizados() {
		nMot = 0;
		listaMot = new Motorizado * [nMot];
	};

	~ListaMotorizados() {};


	void AgregarMotorizados(Motorizado* m) {
		Motorizado** aux = new Motorizado * [nMot + 1];

		for (int i = 0; i < nMot; i++)
			aux[i] = listaMot[i];

		aux[nMot] = m;
		nMot++;

		if (listaMot != nullptr) delete[]listaMot;
		listaMot = aux;
	};


	void EliminarMotorizado(int ind) {
		if (ind < nMot - 1 && nMot>0)
		{
			for (int i = 0; i < nMot; i++) {
				if (i == ind) {
					for (int j = ind; i < nMot - 1; j++)
						listaMot[j] = listaMot[j + 1];

				}
			}
			if (ind == nMot - 1)
				listaMot[nMot - 1]->~Motorizado();

			cout << endl << "Motorizado eliminado" << endl;
			nMot--;
		}
		else cout << endl << "No existe el motorizado" << endl;

	};

	void MotorizadoMapi() {
		if (nMot == 0)
			cout << endl << "No existen motoridzados" << endl;
		else
		{
			cout << "\tNombre\tApellido\tPlaca\tKilometraje\tPrecio\tEmpresa\n";

			for (int i = 0; i < nMot; i++) {
				if (listaMot[i]->getEmpresa() == "Mapi" || listaMot[i]->getEmpresa() == "mapi")
				{
					cout << listaMot[i]->getNombre() << "\t";
					cout << listaMot[i]->getApellido() << "\t";
					cout << listaMot[i]->getPlaca() << "\t";
					cout << listaMot[i]->getKilometraje() << "\t";
					cout << listaMot[i]->Precio() << "\t";
					cout << listaMot[i]->getEmpresa() << "\t";
				}

			}

		}
	}
};
