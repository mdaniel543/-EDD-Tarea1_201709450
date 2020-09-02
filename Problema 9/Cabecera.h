#pragma once
#include "nodo.h"
#include <string>
#include <iostream>
using namespace std;

class cabecera:public nodo
{
public:
	cabecera(int s);
	void setSeccion(int s);
	int getSeccion();

private:
	int Seccion;
};

