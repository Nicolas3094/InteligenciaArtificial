#ifndef VARBOL_H
#define VARBOL_H
#include "../src/nodo.cpp"
#include <functional>
#include <algorithm>
#include <string>
#include <future>
using namespace std;    
template<typename T>
class VArbol{
    public:
        virtual void crearArbol()=0;
        virtual void eliminarNodo(T)=0;
        virtual void buscarNodo(T, Nodo<T>**, Nodo<T>**)=0;
        virtual Nodo<T>* encontrarPadre(T)=0;
        virtual void insertarNodo(T)=0;      
};
#endif