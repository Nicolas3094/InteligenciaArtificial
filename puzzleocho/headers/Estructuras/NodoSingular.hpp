#ifndef NODOSINGULAR_H
#define NODOSINGULAR_H

#include "nodo.hpp"

template <typename T>
class NodoSingular{
public:
    T valor;
    NodoSingular<T> *ptr;

    NodoSingular();
    NodoSingular(T);
    NodoSingular(T, NodoSingular<T>*);
    ~NodoSingular();
};

#endif //NODOSINGULAR_H
