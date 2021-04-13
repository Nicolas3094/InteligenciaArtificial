#include "../headers/arbol.hpp"
template<typename T>
Arbol<T>::Arbol()
{
}
template<typename T>
Arbol<T>::~Arbol(){}

// A B D E H I C F G J
template<typename T>
void Arbol<T>::preOrden(Nodo<T> *raiz, const function<void(Nodo<T>*)> &func)
{
    if (raiz != nullptr)
    {
        func(raiz);
        preOrden(raiz->Izq, func);
        preOrden(raiz->Der, func);
    }
}
// D B H E I A F C J G
template<typename T>
void Arbol<T>::inOrden(Nodo<T> *raiz, const function<void(Nodo<T>*)> &func)
{
    if (raiz != nullptr)
    {
        inOrden(raiz->Izq, func);
        func(raiz);
        inOrden(raiz->Der, func);
    }
}
// D H I E B F J G C A
template<typename T>
void Arbol<T>::postOrden(Nodo<T> *raiz, const function<void(Nodo<T>*)> &func)
{
    if (raiz != nullptr)
    {
        postOrden(raiz->Izq, func);
        postOrden(raiz->Der, func);
        func(raiz);
    }
}
template class Arbol<int>;
