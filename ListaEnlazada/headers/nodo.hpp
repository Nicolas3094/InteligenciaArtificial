#ifndef nodo_h
#define nodo_h
#include "main.hpp"
template<typename T>
class nodo{
    public:
        T info;
        int prioridad;
        nodo* ptr;
        nodo();
        nodo(T);
        nodo(T, nodo*);
        nodo(T, nodo*, int);
        ~nodo();
};
class Nodo {
    public:
        int info;
        Nodo* Rptr;
        Nodo* Lptr;
        Nodo();
        ~Nodo();

};

#endif