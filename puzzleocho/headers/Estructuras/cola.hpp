#ifndef COLA_H
#define COLA_H

#include "ComunStr.hpp"
#include "NodoSingular.hpp"

template <typename T>
class Cola : ComunStr<T>{
    int tamano;
    NodoSingular<T>* frente;
    NodoSingular<T>* cola;
public:
    Cola();
    ~Cola();
    
    void push(T);
    T pop();
    bool vacia();
    void vaciar();
    void imprimir();
    T operator [](int);
};

#endif //COLA_H