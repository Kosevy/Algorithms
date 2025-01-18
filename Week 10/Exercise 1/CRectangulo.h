#pragma once
#include "CFigura.h"

class CRectangulo : public CFigura {
private:
public:
	CRectangulo();
	CRectangulo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B);
	~CRectangulo();
	void dibujar(Graphics^ g);
};

CRectangulo::CRectangulo(){}
CRectangulo::CRectangulo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B)
	:CFigura(x, y, ancho, largo, dx, dy, R, G,B){}
CRectangulo::~CRectangulo(){}
void CRectangulo::dibujar(Graphics^ g){
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(R, G, B));
	g->FillRectangle(objSolidBrush, x, y, ancho, largo);
}