#pragma once
#include "CFigura.h"
#include "CRectangulo.h"
#include "CTriangulo.h"
#include "CCirculo.h"
#include <vector>

using namespace System;
using namespace std;

class CVecFigura {
private:
	vector<CFigura*>* arrFigura;
public:
	CVecFigura();
	~CVecFigura();
	void agregar(int tipo);
	void mover(int anchoF, int largoF);
	void dibujar(Graphics^ g);
};

CVecFigura::CVecFigura(){
	arrFigura = new vector<CFigura*>();
}
CVecFigura::~CVecFigura(){
	delete[] arrFigura;
}
void CVecFigura::agregar(int tipo){
	Random^ r = gcnew Random(DateTime::Now.Ticks);
	int x, y, ancho, largo, dx, dy, R, G, B;
	CFigura* objFigura;

	x = r->Next(50, 400);
	y = r->Next(50, 400);
	ancho = r->Next(30, 80);
	largo = r->Next(30, 80);
	dx = r->Next(1, 5);
	dy = r->Next(1, 5);
	R = r->Next(255);
	G = r->Next(255);
	B = r->Next(255);

	//	1 Rectangulo
	// 2 Circulo
	// 3 Triangulo
	switch (tipo) {
	case 1:
		objFigura = new CRectangulo(x, y, ancho, largo, dx, dy, R, G, B);
		break;
	case 2:
		objFigura = new CCirculo(x, y, ancho, largo, dx, dy, R, G, B);
		break;
	case 3:
		objFigura = new CTriangulo(x, y, ancho, largo, dx, dy, R, G, B);
		break;
	}
	arrFigura->push_back(objFigura);
}
void CVecFigura::mover(int anchoF, int largoF){
	for (int i = 0; i < arrFigura->size(); i++) {
		arrFigura->at(i)->mover(anchoF, largoF);
	}
}
void CVecFigura::dibujar(Graphics^ g){
	for (int i = 0; i < arrFigura->size(); i++) {
		arrFigura->at(i)->dibujar(g);
	}
}