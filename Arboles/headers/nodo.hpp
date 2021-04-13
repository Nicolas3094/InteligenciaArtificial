#ifndef nodo_h
#define nodo_h
#include <iostream>
#define print(x) std::cout<<x<<std::endl
template <typename T>
class Nodo{
    public:
        Nodo();
        Nodo(T);
        ~Nodo();
        T info;
        Nodo<T>* Izq;
        Nodo<T>* Der;
};

#endif