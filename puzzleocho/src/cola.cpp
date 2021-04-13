#include "../headers/cola.hpp"

template<typename T> 
NodoCola<T>::~NodoCola(){}
template<typename T> 
NodoCola<T>::NodoCola(){}
template<typename T> 
NodoCola<T>::NodoCola(T val, NodoCola* ptr){
    this->valor=val;
    this->ptr=ptr;
}
template<typename T>
bool Cola<T>::vacia(){
    return frente==nullptr;
}

template<typename T> 
Cola<T>::~Cola(){}
template<typename T> 
Cola<T>::Cola(){
    cola=nullptr;
    frente = nullptr;
}
template<typename T> 
void Cola<T>::push(T valor){
    NodoCola<T>* tmp = new NodoCola<T>(valor, nullptr);
    if(frente==nullptr){
        frente=tmp;
    }
    if(cola!=nullptr){
        cola->ptr=tmp;
    }
    cola = tmp;
}
template<typename T> 
void Cola<T>::pop(T& val){
    if(frente==nullptr){
        return;
    }
    NodoCola<T> *tmp;
    val = frente->valor;
    tmp=frente;
    frente=tmp->ptr;
    tmp->~NodoCola();
   
}
template<typename T>
void Cola<T>::recorrer(void(*fn)(NodoCola<T>*)){
    if(frente==nullptr){
        return;
    }
    NodoCola<T> *ini, *fin;
    ini = frente;
    while (ini!=nullptr)
    {
        fn(ini);
        ini=ini->ptr;
    }
    
}
template class Cola<int>;
template class Cola<Nodo*>;

