#ifndef COLA_P
#define COLA_P
#include "enlazada.hpp"
#include "comun.hpp"
template<typename T>
class ColaPrioridad :EstructuraComun<T>{
    private:
        nodo<T>* frente;
    public:
        ColaPrioridad();
        void push(T, long);
        T pop();
        void print();
        bool vacia();
};

#endif //COLA_P