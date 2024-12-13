#pragma once
#include "CJugador.h"

class CTerrestre {
protected:
	int x;
	int y;
	int dx;
	int dy;
	int ancho;
	int largo;
public:
	CTerrestre();
	CTerrestre(int x, int y, int dx, int dy, int ancho, int largo);
	CTerrestre(int x, int y, int dx, int dy);
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

	virtual void Dibujar();
	virtual void Borrar();
	virtual bool Colision(CJugador* objJugador);
};

CTerrestre::CTerrestre() {}
CTerrestre::CTerrestre(int x, int y, int dx, int dy, int ancho, int largo) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
	this->ancho = ancho;
	this->largo = largo;
}
CTerrestre::CTerrestre(int x, int y, int dx, int dy) {
	this->x = x;
	this->y = y;
	this->dx = dx;
	this->dy = dy;
}
int CTerrestre::getX() { return this->x; }
int CTerrestre::getY() { return this->y; }
int CTerrestre::getDx() { return this->dx; }
int CTerrestre::getDy() { return this->dy; }
int CTerrestre::getAncho() { return this->ancho; }
int CTerrestre::getLargo() { return this->largo; }
void CTerrestre::setX(int x) { this->x = x; }
void CTerrestre::setY(int y) { this->y = y; }
void CTerrestre::setDx(int dx) { this->dx = dx; }
void CTerrestre::setDy(int dy) { this->dy = dy; }
void CTerrestre::setAncho(int ancho) { this->ancho = ancho; }
void CTerrestre::setLargo(int largo) { this->largo = largo; }

void CTerrestre::Dibujar() {}
void CTerrestre::Borrar() {}
bool CTerrestre::Colision(CJugador* objJugador) { return false; }