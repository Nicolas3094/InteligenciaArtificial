#ifndef COLA_P
#define COLA_P
#include "enlazada.hpp"
#include "comun.hpp"

template<typename T>
class Cola : EstructuraComun<T>{
    private:
        nodo<T>* frente;
        nodo<T>* cola;
    public:
        Cola();
        void push(T, long);
        T pop();
        void print();
        bool vacia();
};

#endif //COLA_P