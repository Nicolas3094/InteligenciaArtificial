#include "../headers/Estructuras/NodoPrioridad.hpp"

template <typename T>
NodoPrioridad<T>::NodoPrioridad()
{
    ptr = nullptr;
}

template <typename T>
NodoPrioridad<T>::NodoPrioridad(long costo, T val) : prioridad(costo)
{
    ptr = nullptr;
    this->valor = val;
}
template <typename T>
NodoPrioridad<T>::NodoPrioridad(long costo, T val, NodoPrioridad<T> *pdr) : prioridad(costo)
{
    ptr = nullptr;
    this->valor = val;
    ptr = pdr;
}

template <typename T>
NodoPrioridad<T>::~NodoPrioridad() {}

template class NodoPrioridad<Nodo *>;
template class NodoPrioridad<int>;