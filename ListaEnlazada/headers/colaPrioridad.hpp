#ifndef COLA_P
#define COLA_P
#include "enlazada.hpp"

class ColaPrioridad {
    private:
        nodo* frente;
    public:
        ColaPrioridad();
        void push();
        void pop();
        void print();
};

#endif //COLA_P