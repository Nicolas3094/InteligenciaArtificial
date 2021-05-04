#ifndef SOLUCION_H
#define SOLUCION_H

#include "Algoritmo.hpp"

#include "../Agentes/entorno.hpp"

#include "../Estructuras/ComunStr.hpp"

#include "../mainh.hpp"

class Solucion : public Algoritmo<Nodo*>{
public:
    Solucion();
    ~Solucion();
    list<Nodo*> hijosNodo(Nodo&);
    virtual void Resolver(Nodo**, int&)=0;
    void BusquedaGrafo(Nodo**,int&, ComunStr<Nodo*>*);
};

#endif