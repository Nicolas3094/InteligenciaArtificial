#include "../headers/nodo.hpp"
template<typename T>
nodo<T>::nodo():prioridad(0), ptr(nullptr){}
template<typename T>
nodo<T>::nodo(T valor):info(valor),prioridad(0), ptr(nullptr){}
template<typename T>
nodo<T>::nodo(T valor, nodo* otro):info(valor),prioridad(0), ptr(otro){}
template<typename T>
nodo<T>::nodo(T valor, nodo* otro, int prior):info(valor),prioridad(prior), ptr(otro){}
template<typename T>
nodo<T>::~nodo(){}
template class nodo<int>;

Nodo::Nodo(){}
Nodo::~Nodo(){}
