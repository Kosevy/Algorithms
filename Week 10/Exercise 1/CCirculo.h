#pragma once
#include "CFigura.h"

class CCirculo : public CFigura {
private:
public:
	CCirculo();
	CCirculo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B);
	~CCirculo();
	void dibujar(Graphics^ g);
};

CCirculo::CCirculo(){}
CCirculo::CCirculo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B)
:CFigura(x, y, ancho, largo, dx, dy, R, G, B){}
CCirculo::~CCirculo(){}
void CCirculo::dibujar(Graphics^ g){
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(R, G, B));
	g->FillEllipse(objSolidBrush, x, y, ancho, largo);
}