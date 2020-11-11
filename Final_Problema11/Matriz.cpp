#include "Matriz.h"
#include <string>



Matriz::Matriz()
{
	this->horizontal = NULL;
	this->vertical = NULL;
}

Matriz::~Matriz()
{
}

void Matriz::add(Estudiante* nuevo)
{
	cabecera* vertical = this->getVertical(nuevo->getSeccion());
	cabecera* horizontal = this->getHorizontal(nuevo->getSeccion());
	if (vertical == NULL) {
		vertical = crearVertical(nuevo->getSeccion());
	}
	if (horizontal == NULL) {
		horizontal = crearHorizontal(nuevo->getSeccion());
	}
	nodo* izquierda = obtenerUltimoH(vertical, nuevo->getSeccion());
	nodo* superior = obtenerUltimoV(horizontal, nuevo->getSeccion());
	if (izquierda->getEste() == NULL) {
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
	}
	else {
		nodo* temp = izquierda->getEste();
		izquierda->setEste(nuevo);
		nuevo->setOeste(izquierda);
		temp->setOeste(nuevo);
		nuevo->setEste(temp);
	}
	if (superior->getSur() == NULL) {
		superior->setSur(nuevo);
		nuevo->setNorte(superior);
	}
	else {
		nodo* temp = superior->getSur();
		superior->setSur(nuevo);
		nuevo->setNorte(superior);
		temp->setNorte(nuevo);
		nuevo->setSur(temp);
	}
}
cabecera* Matriz::getVertical(int dato)
{
	if (this->vertical == NULL) {
		return NULL;
	}
	cabecera* aux = this->vertical;
	while (aux != NULL) {
		if (aux->getSeccion() == dato) {
			return aux;
		}
		aux = (cabecera*)aux->getSur();
	}
	return NULL;
}

cabecera* Matriz::getHorizontal(int dato)
{
	if (this->horizontal == NULL) {
		return NULL;
	}
	cabecera* aux = this->horizontal;
	while (aux != NULL) {
		if ((aux->getSeccion() == dato)) {
			return aux;
		}
		aux = (cabecera*)aux->getEste();
	}
	return NULL;
}

cabecera* Matriz::crearVertical(int dato)
{
	if (this->vertical == NULL) {
		cabecera* nueva = new cabecera(dato);
		this->vertical = nueva;
		return nueva;
	}
	cabecera* aux = this->vertical;
	if (dato <= aux->getSeccion()) {
		cabecera* nueva = new cabecera(dato);
		nueva->setSur(aux);
		this->vertical->setNorte(nueva);
		this->vertical = nueva;
		return nueva;
	}
	while (aux->getSur() != NULL) {
		if (dato > aux->getSeccion() &&  dato <= ((cabecera*)aux->getSur())->getSeccion()) {
			cabecera* nueva = new cabecera(dato);
			cabecera* temp = (cabecera*)aux->getSur();
			temp->setNorte(nueva);
			nueva->setSur(temp);
			aux->setSur(nueva);
			nueva->setNorte(aux);
			return nueva;
		}
		aux = (cabecera*)aux->getSur();
	}
	cabecera* nuevo = new cabecera(dato);
	aux->setSur(nuevo);
	nuevo->setNorte(aux);
	return nuevo;
}

cabecera* Matriz::crearHorizontal(int dato)
{
	if (this->horizontal == NULL) {
		cabecera* nueva = new cabecera(dato);
		this->horizontal = nueva;
		return nueva;
	}
	cabecera* aux = this->horizontal;
	if (dato <= aux->getSeccion()) {
		cabecera* nueva = new cabecera (dato);
		nueva->setEste(aux);
		this->horizontal->setOeste(nueva);
		this->horizontal = nueva;
		return nueva;
	}
	while (aux->getEste() != NULL) {
		if (dato > aux->getSeccion() &&  dato <= ((cabecera*)aux->getEste())->getSeccion()) {
			cabecera* nueva = new cabecera(dato);
			cabecera* temp = (cabecera*)aux->getEste();
			temp->setOeste(nueva);
			nueva->setEste(temp);
			aux->setEste(nueva);
			nueva->setOeste(aux);
			return nueva;
		}
		aux = (cabecera*)aux->getEste();
	}
	cabecera* nuevo = new cabecera(dato);
	aux->setEste(nuevo);
	nuevo->setOeste(aux);
	return nuevo;
}

nodo* Matriz::obtenerUltimoV(cabecera* cabecera,int seccion)
{
	if (cabecera->getSur() == NULL) {
		return cabecera;
	}
	nodo* aux = cabecera->getSur();
	while (aux->getSur() != NULL)
	{
		if (seccion <= ((Estudiante*)aux)->getSeccion()) {
			return aux->getNorte();
		}
		aux = aux->getSur();
	}
	if (seccion <= ((Estudiante*)aux)->getSeccion()) {
		return aux->getNorte();
	}
	return aux;
}

nodo* Matriz::obtenerUltimoH(cabecera* cabecera, int seccion)
{
	if (cabecera->getEste() == NULL) {
		return cabecera;
	}
	nodo* aux = cabecera->getEste();
	while (aux->getEste() != NULL)
	{
		if (seccion <= ((Estudiante*)aux)->getSeccion()){  
			return aux->getOeste();
		}
		aux = aux->getEste();
	}
	if (seccion <= ((Estudiante*)aux)->getSeccion()) {
		return aux->getOeste();
	}
	return aux;
}