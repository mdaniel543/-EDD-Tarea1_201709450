#pragma once
#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include <iostream>
#include "NodoAvl.h"
using namespace std;

class ArbolAvl
{
public:
	ArbolAvl();
	~ArbolAvl();
	NodoAvl* getRaiz();
	void insertar(int valor);
	void generar();
private:
	NodoAvl* raiz;
	NodoAvl* insertar(NodoAvl* raiz, int dato, bool &hc);
	NodoAvl* rotacionII(NodoAvl* n, NodoAvl* n1);
	NodoAvl* rotacionDD(NodoAvl* n, NodoAvl* n1);
	NodoAvl* rotacionID(NodoAvl* n, NodoAvl* n1);
	NodoAvl* rotacionDI(NodoAvl* n, NodoAvl* n1);
	void generar(stringstream* cadena, NodoAvl* padre, NodoAvl* actual, bool izquierda);
	void Delete(NodoAvl* raiz);
};

#endif // !ARBOLAVL_H