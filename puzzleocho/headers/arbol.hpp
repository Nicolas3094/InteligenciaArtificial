#ifndef ARBOL_H
#define ARBOL_H
#include "cola.hpp"
#include "entorno.hpp"

class Arbol
{
    map<long long int, bool> visitados;
    Cola<Nodo*> cola;
    Estado meta;

public:
    int pasos;
    Nodo* raiz;
    ~Arbol();
    Arbol();
    list<Nodo*> hijosNodo(Nodo&);
    void EncontrarSolucion();
    void MostarCamino(Nodo&);
    void BFS(Estado&);
};

#endif //ARBOL_H