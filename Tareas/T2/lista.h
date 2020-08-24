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
	void addClon(nodo* nuevo);
	void clon();
	void imprimirclon();
private: 
	nodo* inicio, * final, *InicioClon, *FinalClon;
};

#endif 

