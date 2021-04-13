#ifndef COLACIRCULAR_H
#define COLACIRCULAR_H
#include "colaI.hpp"

class ColaCircular: public COLAI{

    public:
        ColaCircular();
        void push();
        void pop();
        void print();
};

#endif //COLACIRCULAR_H