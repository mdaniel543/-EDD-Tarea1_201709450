#include <iostream>
#include "Estudiante.h"
#include "Matriz.h"
#include <string>

using namespace std;

int main()
{
    Matriz* m = new Matriz();
    Estudiante* a = new Estudiante(206552, 1);
    Estudiante* b = new Estudiante(282654, 2);
    Estudiante* c = new Estudiante(214564, 1);
    Estudiante* d = new Estudiante(206546, 3);
    Estudiante* e = new Estudiante(265464, 2);
    m->add(a);
    m->add(b);
    m->add(c);
    m->add(d);
    m->add(e);

    

    delete m;
    return 0;
}
