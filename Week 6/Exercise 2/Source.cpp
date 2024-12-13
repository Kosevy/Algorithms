#include "CVecRatones.h"
#include <conio.h>

void ReporteRatones(CVecRatones* obj, int max) {
	Console::SetCursorPosition(0, 0);
	cout << "                         ";
	Console::SetCursorPosition(0, 0);
	cout << "Maximo de ratones: " << max << ", Vivos: " << obj->getTamanioVector();
	Console::SetCursorPosition(0, 1);
	cout << "                        ";
	Console::SetCursorPosition(0, 1);
	cout << "Ratones eliminados: " << obj->getN_ratones_eliminados();
}

int main() {
	srand(int(time(NULL)));
	Console::CursorVisible = false;

	int max = 15;
	char tecla;
	int tiempo = 0;

	CVecRatones* objVecRatones = new CVecRatones();

	CGato* objGato = new CGato();
	objGato->Dibujar();

	_sleep(1000);
	while (true) {
		if (tiempo % 2000 == 0 && objVecRatones->getTamanioVector() <= max) {
			objVecRatones->AgregarRaton();
		}
		objVecRatones->MoverRatones();
		if (kbhit()) {
			tecla = getch();
			objGato->Mover(tecla);
		}

		objVecRatones->EliminarRaton(objGato);
		ReporteRatones(objVecRatones, max);
		_sleep(100);
		tiempo += 100;
	}

	getch();
	return 0;
}