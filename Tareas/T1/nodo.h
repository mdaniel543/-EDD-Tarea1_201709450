#pragma once
#ifndef NODO_H
#define NODO_H
#include <string.h>
#include <iostream>
#include <stddef.h>

using namespace std;


class nodo
{
public:
	nodo(int carnet, string nombre);
	~nodo();
	string getNombre();
	int getCarnet();
	nodo *getSiguiente();
	void setSiguiente(nodo *sig);
	void imprimir();
private:
	string nombre;
	int carnet;
	nodo *siguiente;
};

#endif // NODO_H