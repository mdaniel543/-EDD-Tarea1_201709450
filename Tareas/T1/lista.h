#pragma once
#ifndef LISTA_H
#define LISTA_H
#include <iostream>
#include "nodo.h"

class lista
{
public:
	lista();
	~lista();

	void add(nodo *nuevo);
	bool bu(int carnet);
	bool eliminar(int i);
	void buscar(int i);
	nodo* get(int i);
	bool vacia();
	void imprimir();

private: 
	nodo* inicio, * final;
};

#endif 

