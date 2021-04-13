#ifndef STRUCTPILA_H
#define STRUCTPILA_H
#include <iostream>

#define LIMITE 20

struct  PILA{
    int pila[LIMITE];
    int top;
};
typedef struct PILA NODO;

void push(NODO* ptr);

void pop(NODO* ptr);

void printPila(NODO* ptr);


void exe();


#endif //STRUCTPILA_H