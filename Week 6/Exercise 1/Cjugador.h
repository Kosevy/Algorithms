#pragma once
#include <iostream>
using namespace System;
using namespace std;

class CJugador {
private:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int largo;
	ConsoleColor color;
public:
	CJugador();
	CJugador(int x, int y, int dx, int dy, int ancho, int largo);
	//getters y setters
	int getX();
	int getY();
	int getDx();
	int getDy();
	int getAncho();
	int getLargo();
	void setX(int x);
	void setY(int y);
	void setDx(int dx);
	void setDy(int dy);
	void setAncho(int ancho);
	void setLargo(int largo);

	void Mover(char tecla, int anchoC, int largoC);
	void Dibujar();
	void Borrar();
};

CJugador::CJugador() {}
CJugador::CJugador(int x, int y, int dx, int dy, int ancho, int largo) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->ancho = ancho;
	this->largo = largo;
	this->color = ConsoleColor::Green;
}

int CJugador::getX() { return this->x; }
int CJugador::getY() { return this->y; }
int CJugador::getDx() { return this->dx; }
int CJugador::getDy() { return this->dy; }
int CJugador::getAncho() { return this->ancho; }
int CJugador::getLargo() { return this->largo; }
void CJugador::setX(int x) { this->x = x; }
void CJugador::setY(int y) { this->y = y; }
void CJugador::setDx(int dx) { this->dx = dx; }
void CJugador::setDy(int dy) { this->dy = dy; }
void CJugador::setAncho(int ancho) { this->ancho = ancho; }
void CJugador::setLargo(int largo) { this->largo = largo; }

void CJugador::Mover(char tecla, int anchoC, int largoC) {
	//72->Arriba
	//80->Abajo
	//75->Izquierda
	//77->Derecha
	Borrar();
	switch (tecla)
	{
	case 72:
		if (!(y - dy < 0)) {
			y -= dy;
		}
		break;
	case 80:
		if (!(y + dy > largoC)) {
			y += dy;
		}
		break;
	case 75:
		if (!(x - dx < 0)) {
			x -= dx;
		}
		break;
	case 77:
		if (!(x + dx > anchoC)) {
			x += dx;
		}
		break;
	}
	Dibujar();
}
void CJugador::Dibujar() {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = color;
	cout << char(254);
}
void CJugador::Borrar() {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(0);
	cout << ' ';
}