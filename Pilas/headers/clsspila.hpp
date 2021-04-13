#ifndef CLSSPILA_H
#define CLSSPILA_H
#include <iostream>
#define out(x)  std::cout<< x << std::endl

#define LIMITE 20

class PILA{
    private:
        int pila[LIMITE];
        int top;
    public:
        PILA();
        void push();
        void pop();
        void print();
};
void exe2();

#endif //CLSSPILA_H