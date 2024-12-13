#pragma once
#include "CTerrestre.h"

class CCarro : public CTerrestre {
private:
public:
	CCarro();
	CCarro(int x, int y, int dx, int dy, int ancho, int largo);
	CCarro(int x, int y, int dx, int dy);
	~CCarro();
	void Dibujar();
	void Borrar();
	bool Colision(CJugador* objJugador);
};
CCarro::CCarro() {}
CCarro::CCarro(int x, int y, int dx, int dy, int ancho, int largo) :CTerrestre(x, y, dx, dy, ancho, largo) {
}
CCarro::CCarro(int x, int y, int dx, int dy) : CTerrestre(x, y, dx, dy) {
	this->ancho = 8;
	this->largo = 3;
}
CCarro::~CCarro() {}
void CCarro::Dibujar() {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(15);
	cout << " ___|~\\_";
	Console::SetCursorPosition(x, y + 1);
	Console::ForegroundColor = ConsoleColor(15);
	cout << "[___|_|-";
	Console::SetCursorPosition(x, y + 2);
	Console::ForegroundColor = ConsoleColor(15);
	cout << "(_) (_)";
}
void CCarro::Borrar() {
	Console::SetCursorPosition(x, y);
	Console::ForegroundColor = ConsoleColor(0);
	cout << "        ";
	Console::SetCursorPosition(x, y + 1);
	Console::ForegroundColor = ConsoleColor(0);
	cout << "        ";
	Console::SetCursorPosition(x, y + 2);
	Console::ForegroundColor = ConsoleColor(0);
	cout << "       ";
}
bool CCarro::Colision(CJugador* obj) {
	bool existe_colision = false;
	if (x < obj->getX() + obj->getAncho() &&
		x + ancho > obj->getX() &&
		y < obj->getY() + obj->getLargo() &&
		y + largo > obj->getY()) {
		existe_colision = true;
	}
	return existe_colision;
}