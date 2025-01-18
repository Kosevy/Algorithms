#pragma once
#include "CFigura.h"

class CTriangulo : public CFigura {
private:
public:
	CTriangulo();
	CTriangulo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B);
	~CTriangulo();
	void dibujar(Graphics^ g);
};

CTriangulo::CTriangulo(){}
CTriangulo::CTriangulo(int x, int y, int ancho, int largo, int dx, int dy, int R, int G, int B)
:CFigura(x, y, ancho, largo, dx, dy, R, G, B){}
CTriangulo::~CTriangulo(){}
void CTriangulo::dibujar(Graphics^ g){
	SolidBrush^ objSolidBrush = gcnew SolidBrush(Color::FromArgb(R, G, B));

	Point p1 = Point(x, y + largo);
	Point p2 = Point(x + ancho, y + largo);
	Point p3 = Point(x + (ancho / 2), y);

	cli::array<Point>^ arrPoints = { p1,p2,p3 };

	g->FillPolygon(objSolidBrush, arrPoints);
}