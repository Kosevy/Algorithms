#include "CJuego.h"

int main() {
	_sleep(1000);
	//
	Console::CursorVisible = false;
	CJuego* objJuego = new CJuego();
	objJuego->Jugar();

	getch();
	return 0;
}