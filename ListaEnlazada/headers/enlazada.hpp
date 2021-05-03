#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include "../headers/nodo.hpp"

template <typename T>
class Enlazada
{
protected:
    nodo<T> *inicio;

public:
    Enlazada();
    virtual void Create_List(T) = 0;
    virtual void AddAtBeg(T) = 0;
    virtual void AddAfter(int, T) = 0;
    virtual void Delete() = 0;
    virtual int Count() = 0;
    virtual nodo<T>* Search(int) = 0;
    virtual void Display() = 0;
    virtual void Reverse() = 0;
};
class DobleEnlazada
{
protected:
    Nodo *inicio;

public:
    DobleEnlazada();
    virtual void Create_List(int) = 0;
    virtual void AddAtBeg(int) = 0;
    virtual void AddAfter(int, int) = 0;
    virtual void Delete() = 0;
    virtual Nodo *Search(int) = 0;
    virtual void Display() = 0;
};
#endif //LISTAENLAZADA_H