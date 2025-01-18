#include "Juego.h"

int main() {
	Console::CursorVisible = false;
	Console::SetWindowSize(80, 40);

	srand(time(0));
	Juego J;
	bool gameover = false;

	while (!gameover) {
		J.moverJuego();
		_sleep(50);
	}

	getch();
	return 0;
};