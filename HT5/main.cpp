#include <iostream>
#include "ArbolAvl.h"

using namespace std;

int main()
{
    ArbolAvl* arbol = new ArbolAvl();
    arbol->insertar(55);
    arbol->insertar(41);
    arbol->insertar(15);
    arbol->insertar(45);
    arbol->insertar(80);
    arbol->insertar(85);
    arbol->insertar(93);
    arbol->insertar(55);
    arbol->generar();
    delete arbol;
    return 0;
}

