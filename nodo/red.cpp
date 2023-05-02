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


