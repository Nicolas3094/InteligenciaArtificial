#include "../headers/cola.hpp"
template<typename T>
Cola<T>::Cola(){
    this->frente=nullptr;
    this->cola=nullptr;
}
template<typename T>
void Cola<T>::push(T val, long gast =0){
    int val;
    out("Digite valor");
    std::cin>>val;
    nodo<T> *tmp;
    tmp = new nodo();
    tmp->info=val;
    tmp->ptr=NULL;

    if(frente==NULL){
        frente=tmp;
    }
    if(cola!=NULL){
        cola->ptr=tmp;
    }
    cola=tmp;    
}
template<typename T>
T Cola<T>::pop(){
    T value;
    if(frente==NULL){
        out("Vacia");
        delete &value;
        return value;
    }
    nodo<T> *tmp;
    value = frente->info;

    tmp = frente;
    frente=tmp->ptr;
    tmp=nullptr;
    tmp->~nodo();

    return value;
}
template<typename T>
void Cola<T>::print(){
    if(frente==nullptr){
        out("Vacia");
        return;
    }
    nodo<T> *init, *fin;
    init=frente;
    while(init!=NULL){
        out(init->info<<"|");
        init=init->ptr;
    }
}
template<typename T>
bool Cola<T>::vacia(){
    return frente == nullptr
}
template class Cola<int>;