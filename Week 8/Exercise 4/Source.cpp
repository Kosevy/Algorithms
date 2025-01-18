#include "CJuego.h"
int main() {
	CJuego* objJuego = new CJuego();
	while (!objJuego->gameFinished()) {
		objJuego->iniciarJuego();
		_sleep(20);
	}
	if (objJuego->gameWin()) {
		cout << "Felicidades, ganaste!";
	}
	else {
		cout << "Perdiste.";
	}

	getch();
	return 0;
}