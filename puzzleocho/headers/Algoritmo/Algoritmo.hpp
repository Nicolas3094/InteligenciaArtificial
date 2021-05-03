#ifndef ALG_H
#define ALG_H

#include "../Estructuras/nodo.hpp"

class Algoritmo{
public:
    virtual void Resolver(Nodo**, int&)=0;
};
#endif