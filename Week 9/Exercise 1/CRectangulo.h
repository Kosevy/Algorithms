#pragma once
#include "CFigura.h"

class CRectangulo : public CFigura
{
private:
    //int ancho, alto;
    double base, altura;
public:
    CRectangulo(int _x, int _y, double _base, double _altura);  // Only declare here
    ~CRectangulo();                              // Only declare here

    void Dibujar(Graphics^ G) override;
    Rectangle getRectangle();
};

CRectangulo::CRectangulo(int _x, int _y, double _base, double _altura) :CFigura(_x, _y), base(_base), altura(_altura) {}

CRectangulo::~CRectangulo() {}

void CRectangulo::Dibujar(Graphics^ G)
{
    G->DrawRectangle(Pens::Peru, getRectangle());
}

Rectangle CRectangulo::getRectangle()
{
    return Rectangle(x, y, base * 2, altura * 2);
}