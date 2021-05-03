#ifndef ASTAR_H
#define ASTAR_H

#include "Solucion.hpp"
#include "../Estructuras/colaPrioridad.hpp"

class As : public Solucion{

public:
    As();
    ~As();

    void Resolver(Nodo**, int&);

    long CostoAlcance(Nodo&);
    long CostoObjetivo(Nodo&);
    long CostoTotal(Nodo&);
    long Heuristica(Nodo*);
};

#endif