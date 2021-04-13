#ifndef LISTADOBLE_H
#define LISTADOBLE_H
#include "enlazada.hpp"

class ListaDobleCircular : public DobleEnlazada{
    public:
        ListaDobleCircular();
        void Create_List(int);
        void AddAtBeg(int);
        void AddAfter(int,int);
        void Delete();
        Nodo* Search(int);
        void Display();
};

#endif