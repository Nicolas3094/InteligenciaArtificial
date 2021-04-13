#include "../headers/nodo.hpp"

template <typename T>
Nodo<T>::Nodo(){
    this->Der=nullptr;
    this->Izq=nullptr;
}

template <typename T>
Nodo<T>::Nodo(T val){
    this->Der=nullptr;
    this->Izq=nullptr;
    this->info=val;
}
template <typename T>
Nodo<T>::~Nodo(){

}

template class Nodo<int>;
template class Nodo<char>;