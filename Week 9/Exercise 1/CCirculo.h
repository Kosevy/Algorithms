#pragma once
#include "CFigura.h"

class CCirculo : public CFigura
{
private:
    int ancho, alto;
    double radio;
public:
    CCirculo(int _x, int _y, double _radio);
    ~CCirculo();                            

    void Dibujar(Graphics^ G) override;
    Rectangle getRectangle();
};

CCirculo::CCirculo(int _x, int _y, double _radio) : CFigura(_x, _y), radio(_radio) {}

CCirculo::~CCirculo() {}

Rectangle CCirculo::getRectangle()
{
    return Rectangle(x, y, radio * 2, radio * 2);
}

void CCirculo::Dibujar(Graphics^ G)
{
    G->DrawEllipse(Pens::Black, getRectangle());
}