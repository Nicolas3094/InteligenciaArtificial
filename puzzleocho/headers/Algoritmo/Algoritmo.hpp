#ifndef ALG_H
#define ALG_H

#include "../Estructuras/nodo.hpp"

template<typename T>
class Algoritmo{
public:
    virtual void Resolver(T*, int&)=0;
};
#endif