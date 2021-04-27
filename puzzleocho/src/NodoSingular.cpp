#include "../headers/NodoSingular.hpp"

template <typename T>
NodoSingular<T>::NodoSingular():ptr(nullptr){}

template <typename T>
NodoSingular<T>::NodoSingular(T val):valor(val), ptr(nullptr){}

template <typename T>
NodoSingular<T>::NodoSingular(T val, NodoSingular<T>* cola):valor(val), ptr(cola){}

template <typename T>
NodoSingular<T>::~NodoSingular(){}

template class NodoSingular<int>;
template class NodoSingular<Nodo*>;
template class NodoSingular<Estado*>;
