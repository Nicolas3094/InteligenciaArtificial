#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H
#include <iostream>
#include "../headers/nodo.hpp"
#define out(x)  std::cout<< x << std::endl

class Enlazada{
    protected:
        
        nodo *inicio;
    public:
        Enlazada();
        virtual void Create_List(int)=0;
        virtual void AddAtBeg(int)=0;
        virtual void AddAfter(int,int)=0;
        virtual void Delete()=0;
        virtual int Count()=0;
        virtual nodo * Search(int)=0;
        virtual void Display()=0;
        virtual void Reverse()=0;
};
class DobleEnlazada{
    protected:
        
        Nodo *inicio;
    public:
        DobleEnlazada();
        virtual void Create_List(int)=0;
        virtual void AddAtBeg(int)=0;
        virtual void AddAfter(int,int)=0;
        virtual void Delete()=0;
        virtual Nodo * Search(int)=0;
        virtual void Display()=0;
};
#endif //LISTAENLAZADA_H