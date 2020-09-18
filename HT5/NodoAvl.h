#pragma once
#include <iostream>
using namespace std;

class NodoAvl
{
public:
	NodoAvl(int dato);
	void setData(int dato);
	void setFactor(int factor);
	void setIzquierda(NodoAvl* izq);
	void setDerecha(NodoAvl* der);
	NodoAvl* getDerecha();
	NodoAvl* getIzquierda();
	int getFactor();
	int getData();
private:
	int dato; 
	int factorE;
	NodoAvl* izquierda;
	NodoAvl* derecha;
};
