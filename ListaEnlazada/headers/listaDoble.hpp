#ifndef LISTADOBLE_P
#define LISTADOBLE_P
#include "enlazada.hpp"

class ListaDoble : public DobleEnlazada{
    public:
        ListaDoble();
        void Create_List(int);
        void AddAtBeg(int);
        void AddAfter(int,int);
        void Delete();
        int Count();
        Nodo* Search(int);
        void Display();
        void Reverse();
};

#endif