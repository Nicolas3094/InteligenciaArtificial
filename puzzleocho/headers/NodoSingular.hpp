#ifndef NODOCOLA_H
#define NODOCOLA_H
#include "nodo.hpp"
template <typename T>
class NodoSingular
{
public:
    T valor;
    NodoSingular<T> *ptr;

    NodoSingular();
    NodoSingular(T);
    NodoSingular(T, NodoSingular<T>*);
    ~NodoSingular();
};

#endif //NODOCOLA_H
