#include "lista.h"

using namespace std;

lista::lista()
{
	this->inicio = NULL;
}

lista::~lista()
{
}

void lista::add(nodo* nuevo)
{
	if (inicio == NULL) {
		this->inicio = nuevo;
		this->final = nuevo;
	}
	else {
		this->final->setSiguiente(nuevo);
		this->final = nuevo;
	}
}

bool lista::bu(int i)
{
	nodo* aux = this->inicio;
	bool enco = false;
	while (aux != NULL && enco != true) {
		if (i == aux->getCarnet()) {
			enco = true;
			return enco;
		}
		else {
			aux = aux->getSiguiente();
		}
	}
	return false;
}

bool lista::eliminar(int i)
{
	if (bu(i)) {
		if (inicio->getCarnet() == i) {
			inicio = inicio->getSiguiente();
		}
		else {
			nodo* aux = this->inicio;

			while (aux->getSiguiente()->getCarnet() !=i)
			{
				aux = aux->getSiguiente();
			}
			nodo* sigue = aux->getSiguiente()->getSiguiente();
			aux->setSiguiente(sigue);
		}
		return true;
	}
	else {
		return false;
	}


}

void lista::buscar(int i)
{
	if (bu(i)) {
		nodo* aux = this->inicio;
		bool enco = false;

		while (aux != NULL && enco != true) {
			if (i == aux->getCarnet()) {
				
				cout << "\n\nNOMBRE : " << aux->getNombre() <<" carnet : " << aux->getCarnet()<<endl<<endl;
				cout << "Busqueda Exitosa.";
				enco = true;
			}
			else {
				aux = aux->getSiguiente();
			}
		}
	}
	else {
		cout << "\n Estudiante inexistente en lista";
	}
}



nodo* lista::get(int i)
{
	return nullptr;
}

bool lista::vacia()
{
	return inicio == NULL;
}

void lista::imprimir()
{
	if (!vacia()) {
		nodo* aux = this->inicio;
		int i = 1;
		while (aux != NULL)
		{
			cout <<"\n" << i <<". CARNET: " <<aux->getCarnet() <<" NOMBRE: " << aux->getNombre() <<endl<<endl;
			aux = aux->getSiguiente();
			i++;
		}
	}
	else {
		cout << "\n  LISTA VACIA";
	}

}
