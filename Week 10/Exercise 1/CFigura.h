#pragma once

using namespace System::Drawing;

class CFigura {
protected:
	int x, y;
	int ancho, largo;
	int dx, dy;
	int R, G, B;
public:
	CFigura();
	CFigura(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B);
	~CFigura();
	void mover(int anchoF, int largoF);
	virtual void dibujar(Graphics^ g);
};

CFigura::CFigura(){}
CFigura::CFigura(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B){
	this->x = x;
	this->y = y;
	this->ancho = ancho;
	this->largo = largo;
	this->dx = dx;
	this->dy = dy;
	this->R = R;
	this->G = G;
	this->B = B;
}
CFigura::~CFigura(){}
void CFigura::mover(int anchoF, int largoF){
	if (x + dx < 0 || x + ancho + dx > anchoF) {
		dx *= -1;
	}
	if (y + dy < 0 || y + largo + dy > largoF) {
		dy *= -1;
	}
	x += dx;
	y += dy;
}
void CFigura::dibujar(Graphics^ g){}