#include "red.h"

Red::Red()
{

}

void Red::addRuta(const Nodo &nuevoNodo)
{
    for(int i=0; i < topologia.size(); ++i){
        topologia[i].addConexion(nuevoNodo.getNodo(), nuevoNodo.getCosto(topologia[i].getNodo()));
    }
    topologia.push_back(nuevoNodo);
}

void Red::deleteRuta(const string &elimNodo)
{
    for(int i=0; i < topologia.size(); ++i){
        topologia[i].deleteConexion(elimNodo);
    }
    topologia.erase(topologia.begin() + buscarRuta(elimNodo));
}

bool Red::salir(const string &nombre)
{
    for(int i=0; i < topologia.size(); ++i){
        if(topologia[i].getNodo() == nombre){
            return true;
        }
    }
    return false;
}

const vector<string> Red::nombres() const
{
    vector<string> nombres;
    for(int i=0; i < topologia.size(); ++i){
        nombres.push_back(topologia[i].getNodo());
    }
    return nombres;
}

int Red::len() const
{
    return topologia.size();
}

/***/

int Red::buscarRuta(const string &nombreRuta)
{
    for(int i=0; i < topologia.size(); ++i){
        if(topologia[i].getNodo() == nombreRuta){
            return i;
        }
    }

    return 0;
}

void Red::random(const int &numNodos)
{
    nombre = "Red_aleatoria";

    srand(time(NULL));
    vector<char> caracteres;

    for(int i=65; i<=90; ++i){
        caracteres.push_back(i);
    }

    for(int i=0; i < numNodos; ++i){

        int random = rand()%caracteres.size();
        topologia.push_back(Nodo(string(1, caracteres[random])));
        caracteres.erase(caracteres.begin()+random);
    }

    for(int i=0; i < topologia.size(); ++i){

        for(int j=0; j<topologia.size(); ++j){

            if(j != i){

                if(rand()%3){
                    topologia[i].addConexion(topologia[j].getNodo(), 1+rand()%15);
                }

                else{
                    topologia[i].addConexion(topologia[j].getNodo(), INF);
                }

                topologia[j].addConexion(topologia[i].getNodo(), topologia[i].getCosto(topologia[j].getNodo()));
            }
        }
    }
}
