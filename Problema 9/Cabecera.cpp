#include "cabecera.h"

cabecera::cabecera(int s)
{
    this->Seccion = s;
}

void cabecera::setSeccion(int s)
{
    this->Seccion = s;
}

int cabecera::getSeccion()
{
    return this->Seccion;
}
