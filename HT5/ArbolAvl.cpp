#include "ArbolAvl.h"
#include <stdbool.h>
#include <ostream>
#include <sstream>
#include <fstream>
//#include <bits/stdc++.h>

ArbolAvl::ArbolAvl()
{
	this->raiz = NULL;
}

ArbolAvl::~ArbolAvl()
{
	Delete(this->raiz);
}

NodoAvl* ArbolAvl::getRaiz()
{
	return this->raiz;
}

void ArbolAvl::insertar(int valor)
{
	bool b = false;
	bool* a = &b;
	this->raiz = insertar(this->raiz, valor, *a);

}

void ArbolAvl::generar()
{
	stringstream cadena; 
	cadena << "digraph G{\n" << endl;
	cadena << "node[shape=\"record\"]" << endl;
	if (raiz != NULL) {
		cadena << "node" << &(*this->raiz) << "[label = \"<f0>|<f1>" << this->raiz->getData() << "factor:" << this->raiz->getFactor() << "|<f2>\"]" << endl;
		this->generar(&cadena, this->raiz, this->getRaiz()->getIzquierda(), true);
		this->generar(&cadena, this->raiz, this->getRaiz()->getDerecha(), false);
	}
	cadena << "}" << endl;
	cout << cadena.str() << endl;
	ofstream file("salida.dot");
	file << cadena.str();
	file.close();
	system("dot -Tpng salida.dot -o imagen.png");
	system("imagen.png");

}

NodoAvl* ArbolAvl::insertar(NodoAvl* raiz, int dato, bool &hc)
{
	NodoAvl* n1;
	if (raiz == NULL) {
		raiz = new NodoAvl(dato);
		hc = true;
	}
	else if(dato <= raiz->getData()) {
		NodoAvl* izq = insertar(raiz->getIzquierda(), dato, hc);
		raiz->setIzquierda(izq);
		if (hc) {
			switch (raiz->getFactor())
			{
			case 1:
				raiz->setFactor(0);
				hc = false;
				break;
			case 0:
				raiz->setFactor(-1);
				break;
			case -1:
				n1 = raiz->getIzquierda();
				if (n1->getFactor() == -1) {
					raiz = rotacionII(raiz, n1);
				}
				else {
					raiz = rotacionDD(raiz, n1);
				}
				hc = false;
				break;
			}
		}
	}
	else if (dato > raiz->getData()) {
		NodoAvl* der = insertar(raiz->getDerecha(), dato, hc);
		raiz->setDerecha(der);
		if (hc) {
			switch (raiz->getFactor())
			{
			case 1:
				n1 = raiz->getDerecha();
				if (n1->getFactor() == 1) {
					raiz = rotacionDD(raiz, n1);
				}
				else {
					raiz = rotacionDI(raiz, n1);
				}
				hc = false;
				break;
			case 0:
				raiz->setFactor(1);
				break;
			case -1:
				raiz->setFactor(0);
				hc = false;
				break;
			}

		
		}
	}
	return raiz;
}

NodoAvl* ArbolAvl::rotacionII(NodoAvl* n, NodoAvl* n1)
{
	n->setIzquierda(n1->getDerecha());
	n1->setDerecha(n);
	if (n1->getFactor()==-1) {
		n->setFactor(0);
		n1->setFactor(0);
	}
	else {
		n->setFactor(-1);
		n1->setFactor(1);
	}
	return n1;
}

NodoAvl* ArbolAvl::rotacionDD(NodoAvl* n, NodoAvl* n1)
{
	n->setDerecha(n1->getIzquierda());
	n1->setIzquierda(n);
	if (n1->getFactor() == 1) {
		n->setFactor(0);
		n1->setFactor(0);
	}
	else {
		n->setFactor(1);
		n1->setFactor(-1);
	}
	return n1;
}

NodoAvl* ArbolAvl::rotacionID(NodoAvl* n, NodoAvl* n1)
{
	NodoAvl* n2 = n1->getDerecha();
	n->setIzquierda(n2->getDerecha());
	n2->setDerecha(n);
	n1->setDerecha(n2->getIzquierda());
	n1->setIzquierda(n1);

	if (n2->getFactor() == 1) {
		n1->setFactor(-1);
	}
	else {
		n1->setFactor(0);
	}

	if (n2->getFactor() == -1) {
		n->setFactor(1);
	}
	else {
		n->setFactor(0);
	}
	n2->setFactor(0);
	return n2;
}

NodoAvl* ArbolAvl::rotacionDI(NodoAvl* n, NodoAvl* n1)
{
	NodoAvl* n2 = n1->getIzquierda();
	n->setDerecha(n2->getIzquierda());
	n2->setIzquierda(n);
	n1->setIzquierda(n2->getDerecha());
	n1->setDerecha(n1);

	if (n2->getFactor() == 1) {
		n->setFactor(-1);
	}
	else {
		n->setFactor(0);
	}

	if (n2->getFactor() == -1) {
		n1->setFactor(1);
	}
	else {
		n1->setFactor(0);
	}
	n2->setFactor(0);
	return n2;
}

void ArbolAvl::generar(stringstream* cadena, NodoAvl* padre, NodoAvl* actual, bool izquierda)
{
	if (actual != NULL) {
		*cadena << "node" << &(*actual) << "[label= \"<f0> | <f1>" << actual->getData() << "factor:" << actual->getFactor() << "| <f2>\"]" << endl;
		if (izquierda) {
			*cadena << "node" << &(*padre) << ": f0->node" << &(*actual) << ":f1" << endl;
		}
		else {
			*cadena << "node" << &(*padre) << ": f2->node" << &(*actual) << ":f1" << endl;
		}
		generar(cadena, actual, actual->getIzquierda(), true);
		generar(cadena, actual, actual->getDerecha(), true);
	}
}

void ArbolAvl::Delete(NodoAvl* raiz)
{
	if (raiz == NULL) {
		return;
	}
	Delete(raiz->getDerecha());
	Delete(raiz->getIzquierda());
	delete raiz;
}
