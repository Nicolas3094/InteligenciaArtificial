#ifndef COLA_H
#define COLA_H
#include "NodoSingular.hpp"
template <typename T>
class Cola
{
    int tamano;
public:
    NodoSingular<T>* frente;
    NodoSingular<T>* cola;

    Cola();
    ~Cola();
    
    void push(T);
    void pop(T&);
    bool vacia();
    void recorrer(const function<void(T, bool &)>&, bool);

    T operator [](int);
};

#endif