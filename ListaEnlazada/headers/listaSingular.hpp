#ifndef LISTASINGULAR_P
#define LISTASINGULAR_P
#include "enlazada.hpp"

class ListaSingular : public Enlazada{
    public:
        ListaSingular();
        void Create_List(int);
        void AddAtBeg(int);
        void AddAfter(int,int);
        void Delete();
        int Count();
        nodo* Search(int);
        void Display();
        void Reverse();
};

#endif