#include <iostream>
#include <conio.h>
using namespace std;
using namespace System;
public class Barco {
protected:
	double peso;
public:
	Barco(double p) {
		peso = p;
	}
	~Barco() {}
virtual void getInfo() {
		cout << "El peso es: " << this->peso << endl;
	};
};

public class Submarino: public Barco{
protected:
	string color;
public:
	Submarino(double p, string c) : Barco(p) {
		color = c;
	}

	~Submarino(){}

	void getInfo() {
		cout << "El color es: " << this->color << endl;
	};
};

public class Destructor : public Barco {
protected:
	double velocidad;
public:
	Destructor(double p, int v) : Barco(p) {
		velocidad = v;
	}

	~Destructor() {}

	void getInfo() {
		cout << "La velocidad es: " << this->velocidad << endl;
	};
};

public class SubmarinoDestructor : public Destructor, public Submarino {
private:
	double precio;
public:
	SubmarinoDestructor(double p, string c, double v, double pr) : Submarino(p, c), Destructor(p, v) {
		precio = pr;
	}

	void getInfo() {
		cout << "Algunos datos del Submarino Destructor: " << endl;
		cout << "Color: " << color << endl;
		cout << "Velocidad: " << velocidad << endl;
		cout << "Precio: " << precio << endl;
	}
};

int main()
{
	Submarino* objSubmarino = new Submarino(35.5, "Amarelo");
	Destructor* objDestructor = new Destructor(40.5, 32.6);
	SubmarinoDestructor* objSubmarinoDestructor = new SubmarinoDestructor(89.4, "Naranja", 100, 150);

	objSubmarinoDestructor->getInfo();

	_getch();
	return 0;
}
