#ifndef COLA_H
#define COLA_H
#include "nodo.hpp"
template <typename T>
class NodoCola
{
public:
    T valor;
    NodoCola<T> *ptr;
    NodoCola();
    NodoCola(T, NodoCola<T>*);
    ~NodoCola();
};

template <typename T>
class Cola
{
private:
    NodoCola<T> *frente;
    NodoCola<T> *cola;
public:
    Cola();
    ~Cola();
    void push(T);
    void pop(T&);
    bool vacia();
    void recorrer(void(*)(NodoCola<T> *));
};

#endif