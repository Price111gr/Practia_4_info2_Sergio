#include "red.h"
#include <iostream>

/**/

using namespace std;

int menu(const int &opc);

int main()
{
    Red rednodos;
    int opcion = menu(0);
    string aux[2];

    while(true){
        system("pause");
        opcion = menu(1);

        if(opcion == 1){
            Nodo nuevoNodo;

            cout << "Ingrese el nombre del nuevo enrutador: \n";
            getline(cin, aux[0]);

            if(!rednodos.salir(aux[0])){
                nuevoNodo.setNombre(aux[0]);

                for(int i=0; i < rednodos.len(); ++i){
                    cout << "Ingrese el valor de la conexion con: " << rednodos.nombres()[i] << "\n -> ";
                    getline(cin, aux[0]);

                    if(aux[0] == "~"){ nuevoNodo.addConexion(rednodos.nombres()[i], INF); }
                    else{
                        nuevoNodo.addConexion(rednodos.nombres()[i], stoi(aux[0])); }
                }
                rednodos.addRuta(nuevoNodo);

                cout << "Enrutador agregado con exito.\n" << endl;
                cout << rednodos << endl;

            }
            else{
                cout << "El enrutador ya esta en la red.\n" << endl;
            }

        }
        else if(opcion == 2){
            cout << rednodos << endl;
            cout << "Ingrese el nombre del enrutador a eliminar: \n";
            getline(cin, aux[0]);

            if(rednodos.salir(aux[0])){
                rednodos.deleteRuta(aux[0]);

                cout << "Enrutador eliminado con exito.\n" << endl;
                cout << rednodos << endl;

            }
            else{cout << "El enrutador: " << aux[0] << " no existe.\n" << endl; }

        }

        else if(opcion == 4){
            cout << rednodos << endl;
            break;

        }

    }
    return 0;
}

int menu(const int &opc){

    string opcion;

    while(true){
        if(opc == 0){
            cout << "Menu:\n"
                    "  1. Generar red aleatoria(Construyendose).\n"
                    "  2. Generar red vacia.\n"
                    " Opcion: ";

            cin >> opcion; cin.ignore();


            if(opcion[0] < 49 || opcion[0] > 50 || opcion.length() > 1){
                cout << "Opcion no valida, Intente de nuevo.\n" << endl;
            }
            else{
                break;
            }

        }
        else{ // Se imprime el menu principal

            cout << "\nQue desea hacer?\n"
                    "  1. Agregar enrrutador.\n"
                    "  2. Eliminar enrrutador.\n"
                    "  4. Salir.\n "
                    " Opcion: ";
            cin >> opcion; cin.ignore();

            if(opcion[0] < 49 || opcion[0] > 53 || opcion.length() > 1){
                cout << "Opcion no valida, Intente de nuevo.\n" << endl;
            }
            else{
                break;
            }
        }
    }

    return stoi(opcion); // Se retorna la opcion tomada por el usuario
}

