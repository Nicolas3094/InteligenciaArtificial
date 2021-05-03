#ifndef ColaPrioridad_H
#define ColaPrioridad_H

#include "NodoPrioridad.hpp"
#include "../Algoritmo/As.hpp"

template <typename T, typename K>
class ColaPrioridad{
public:
    NodoPrioridad<T>* frente;
    long (K::*eval)(T);
    
    ColaPrioridad();
    void push(T, long);
    T pop();
    bool vacia();
    void vaciar();
    void imprimir();
};



#endif //ColaPrioridad_HA