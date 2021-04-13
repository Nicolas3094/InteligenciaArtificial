#ifndef ARBOL_H
#define ARBOL_H
#include "nodo.hpp"
#include <functional>
#include <algorithm>
#include <string>
#include <future>
using namespace std;    


template<typename T>
class Arbol{
        
    public:
        Nodo<T>* Raiz;
        Arbol();
        ~Arbol();
        void inOrden(Nodo<T>*, const function<void(Nodo<T>*)> &);
        void postOrden(Nodo<T>*,const function<void(Nodo<T>*)> &);
        void preOrden(Nodo<T>*,const function<void(Nodo<T>*)> &);
        


};


#endif //ARBOL_H