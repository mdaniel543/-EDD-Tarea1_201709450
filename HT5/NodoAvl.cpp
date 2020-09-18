#include "NodoAvl.h"

NodoAvl::NodoAvl(int dato)
{
	this->dato = dato;
	this->derecha = NULL;
	this->izquierda = NULL;
}

void NodoAvl::setData(int dato)
{
	this->dato = dato;
}

void NodoAvl::setFactor(int factor)
{
	this->factorE = factor;
}

void NodoAvl::setIzquierda(NodoAvl* izq)
{
	this->izquierda = izq;
}

void NodoAvl::setDerecha(NodoAvl* der)
{
	this->derecha = der;
}

NodoAvl* NodoAvl::getDerecha()
{
	return this->derecha;
}

NodoAvl* NodoAvl::getIzquierda()
{
	return this->izquierda;
}

int NodoAvl::getFactor()
{
	return this->factorE;
}

int NodoAvl::getData()
{
	return this->dato;
}
