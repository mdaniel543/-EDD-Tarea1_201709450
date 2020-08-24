#include "nodo.h"
#include <iostream>

nodo::nodo(int carnet, string nombre)
{
	this->carnet = carnet;
	this->nombre = nombre;
	this->siguiente = NULL;
}

nodo::~nodo()
{

}

string nodo::getNombre()
{
	return this->nombre;
}

int nodo::getCarnet()
{
	return this->carnet;
}

nodo* nodo::getSiguiente()
{
	return this->siguiente;
}

void nodo::setSiguiente(nodo* sig)
{
	this->siguiente = sig;
}

void nodo::imprimir()
{
	cout << "Nombre : " << this->nombre << " Carnet:" << this->getCarnet() << endl;

}
