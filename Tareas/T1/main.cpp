#include <iostream>
#include "lista.h"
#include "nodo.h"
#include <string.h>

using namespace std;


int main()
{
    cout << "       Primera Tarea de Estructura de Datos!\n";
    cout << "\n";

    int se = 0;
    lista* datos = new lista();
    string name = "";
    do
    {
        cout << "      MENU: \n";
        cout << "1. Insertar Datos \n";
        cout << "2. Buscar Datos \n";
        cout << "3. Eliminar Datos \n";
        cout << "4. Mostrar Datos\n";
        cout << "5. Salir \n";
        cout << "\n Ingrese el numero de la accion que desea realizar: ";
        cin >> se;
        cout << "\n";
        cout << "\n";
        switch (se)
        {
            case 1: 
                system("cls");
                nodo *nuevo;
                int id;
                cout << "Nombre Estudiante: ";
                cin >> name;
                cout << "\nCarnet Estudiante: ";
                cin >> id;
                nuevo = new nodo(id, name);
                datos->add(nuevo);
                system("cls");
                cout << "\n\tEstudiante Agregado correctamente\n\n";
                break;

            case 2:
                system("cls");
                int ir;
                cout << "Carnet del estudiante a buscar: ";
                cin >> ir;
                datos->buscar(ir);

                break;

            case 3: 
                system("cls");
                int d;
                cout << "Carnet del estudiante a eliminar: \n";
                cin >> d;
                if (datos->eliminar(d)) {
                    cout << "Datos del estudiante eliminados correctamente"<<endl<<endl;
                }
                else {
                    cout << "Error al eliminar estudiante o datos no encontrados"<<endl<<endl;
                }
                break;

            case 4: 
                system("cls");
                cout << "'Listado:' ";
                datos->imprimir();
                break;

            case 5: 
                cout << "FINALIZADO CORRECTAMENTE \n";
                break;
            default: cout << " 'No se ha seleccionado una accion valida' \n \n"; break;
              
        }

    } while (se != 5);

    


    return 0;
}


