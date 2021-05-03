#ifndef NODOPRIORIDAD_H
#define NODOPRIORIDAD_H

#include "NodoSingular.hpp"

template <typename T>
class NodoPrioridad{
public:
    T valor;
    long prioridad;
    NodoPrioridad<T>* ptr;
    NodoPrioridad();
    NodoPrioridad(long,T);
    NodoPrioridad(long, T, NodoPrioridad<T>*);
    ~NodoPrioridad();
};

#endif //NODOPRIORIDAD_H
