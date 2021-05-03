#ifndef LISTASINGULAR_P
#define LISTASINGULAR_P
#include "enlazada.hpp"


template<typename T>
class ListaSingular : public Enlazada{
    public:
        ListaSingular();
        void Create_List(T);
        void AddAtBeg(T);
        void AddAfter(int,T);
        void Delete();
        int Count();
        nodo<T>* Search(int);
        void Display();
        void Reverse();
};

#endif