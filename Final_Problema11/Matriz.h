#pragma once
#include "nodo.h"
#include "cabecera.h"
#include "Estudiante.h"
#include <iostream>
#include <string>
#include <ostream>
#include <sstream>
#include <fstream>
using namespace std;

class Matriz
{
public:
	Matriz();
	~Matriz();
	void add(Estudiante* nuevo);
	void codigo();
private:
	cabecera* horizontal;
	cabecera* vertical;
	cabecera* getVertical(int dato);
	cabecera* getHorizontal(int dato);
	cabecera* crearVertical(int dato);
	cabecera* crearHorizontal(int dato);

	nodo* obtenerUltimoV(cabecera* cabecera, int seccion);
	nodo* obtenerUltimoH(cabecera* cabecera, int seccion);

};