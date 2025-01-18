#pragma once
#include "CCuadrado.h"
#include "CFigura.h"
#include "CCirculo.h"
#include "CRectangulo.h"
#include "CElipse.h"
#include <vector>

class CVCFiguras
{
private:
	vector<CFigura*> Fgrs;
public:
	CVCFiguras();
	~CVCFiguras();

	void AgregarFigura(CFigura*);
	void Dibujar(Graphics^ G);

	void Eliminar();
	CFigura* getFigura(int indx);

};

CVCFiguras::CVCFiguras()
{
}

CVCFiguras::~CVCFiguras()
{
}

void CVCFiguras::AgregarFigura(CFigura* F)
{
	Fgrs.push_back(F);
}

void CVCFiguras::Dibujar(Graphics^ G)
{
	if (Fgrs.size() != 0)
	{
		for (int i = 0; i < Fgrs.size(); i++)
		{
			Fgrs.at(i)->Dibujar(G);
		}
	}
}

void CVCFiguras::Eliminar()
{
	for (int i = 0; i < Fgrs.size(); i++)
	{
		delete Fgrs[i];
		Fgrs[i] = nullptr;
	}
	Fgrs.clear();
}

CFigura* CVCFiguras::getFigura(int indx)
{
	if (indx > 0 && Fgrs.size() != 0)
		return Fgrs[indx];
}