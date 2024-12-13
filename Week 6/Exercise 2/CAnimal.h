#pragma once
#include "conio.h"
#include "iostream"
#include <string>
#include <windows.h>


using namespace System;
using namespace std;

class Animal {
protected:
    int x, y;
    int dx, dy;
    int ancho, largo;
public:
    Animal() {
        x = 0;
        y = 0;
        dx = 0;
        dy = 0;
        ancho = 0;
        largo = 0;
    }

    ~Animal() {}

    //getters

    int getX() { return x; }
    int getY() { return y; }
    int getDX() { return dx; }
    int getDY() { return dy; }
    int getAncho() { return ancho; }
    int getLargo() { return largo; }

    //setters

    void setX(int x) { x = x; }
    void setY(int y) { y = y; }
    void setDX(int dx) { dy = dy; }
    void setDY(int dy) { dy = dy; }
    void setAncho(long Ancho) { ancho = ancho; }
    void setLargo(long Largo) { largo = largo; }


    virtual void Borrar() {}

    virtual void Mover(){}

    virtual void Dibujar() {}


};