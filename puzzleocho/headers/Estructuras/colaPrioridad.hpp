#ifndef ColaPrioridad_H
#define ColaPrioridad_H

#include "NodoPrioridad.hpp"

template <typename T>
class ColaPrioridad{
    int tamano;
    function<long(T)> lambda;
    NodoPrioridad<T>* frente;
public:
    ColaPrioridad(function<long(T)>);
    ~ColaPrioridad();

    void push(T);
    T pop();
    bool vacia();
    void vaciar();
    void imprimir();
    T operator [](int);
};

#endif //ColaPrioridad_H