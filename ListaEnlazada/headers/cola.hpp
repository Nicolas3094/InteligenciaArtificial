#ifndef COLA_P
#define COLA_P
#include "enlazada.hpp"

class Cola {
    private:
        nodo* frente;
        nodo* cola;
    public:
        Cola();
        
        void push();
        void pop();
        void print();
};

#endif //COLA_P