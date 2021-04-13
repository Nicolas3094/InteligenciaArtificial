#ifndef PILA_P
#define PILA_P
#include "enlazada.hpp"

class Pila {
    private:
        nodo* top;
    public:
        Pila();
        
        void push();
        void pop();
        void print();
};

#endif //PILA_P