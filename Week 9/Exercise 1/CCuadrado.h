#pragma once
#include "CFigura.h"

class CCuadrado :public CFigura
{
private:
	double lado1;
public:
	CCuadrado(double, int, int);
	~CCuadrado();

	void Dibujar(Graphics^ G) override;
	Rectangle getRectangle();
};

CCuadrado::CCuadrado(double ld1, int _x, int _y) :lado1(ld1), CFigura(_x, _y) {}

CCuadrado::~CCuadrado() {}

void CCuadrado::Dibujar(Graphics^ G)
{
	G->DrawRectangle(Pens::Black, getRectangle());
}

Rectangle CCuadrado::getRectangle()
{
	return Rectangle(x, y, lado1 * 2, lado1 * 2);
}