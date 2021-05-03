#ifndef ARBOL_H
#define ARBOL_H

#include "cola.hpp"
#include "../Algoritmo/Algoritmo.hpp"
#include "../Agentes/entorno.hpp"

class Arbol{
public:
    int pasos;
    Nodo* raiz;

    ~Arbol();
    Arbol();
    Arbol(Nodo*);

    void EncontrarSolucion(Algoritmo*, Estado&);
    void MostarCamino(Nodo&);
};

#endif //ARBOL_H