#ifndef DOBLECOLA_H
#define DOBLECOLA_H
#include "colaI.hpp"


class DobleCola: public COLAI{
 
    public:
        DobleCola();
        void push();
        void pop();
        void print();
        
        void pushLeft();
        void pushRight();
        void popLeft();
        void popRight();
};
#endif //DOBLECOLA_H