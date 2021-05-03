#ifndef PILA_P
#define PILA_P
#include "enlazada.hpp"
template<typename T>
class Pila {
    private:
        nodo<T>* top;
    public:
        Pila();
        void push(T, long);
        T pop();
        void print();
};

#endif //PILA_P