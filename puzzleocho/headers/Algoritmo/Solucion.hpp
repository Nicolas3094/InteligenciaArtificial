#ifndef SOLUCION_H
#define SOLUCION_H

#include "Algoritmo.hpp"

#include "../Agentes/entorno.hpp"
#include "../mainh.hpp"

class Solucion : public Algoritmo{
public:
    Solucion();
    ~Solucion();
    list<Nodo*> hijosNodo(Nodo&);
    virtual void Resolver(Nodo**, int&)=0;
};

#endif