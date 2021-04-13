#ifndef COLAI_H
#define COLAI_H
#include <iostream>
#define out(x)  std::cout<< x << std::endl

#define LIMITE 7

class COLAI{
    protected:
        int colaArray[LIMITE];
        int frente;
        int cola;
    public:
        COLAI();
        virtual void push()=0;
        virtual void pop()=0;
        virtual void print()=0;
};

#endif //COLAI_H