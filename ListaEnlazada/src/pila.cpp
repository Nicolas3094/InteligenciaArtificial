#include "../headers/pila.hpp"
template<typename T>
Pila<T>::Pila(){
    top=NULL;
}
template<typename T>
T Pila<T>::pop(){
    if(top==NULL){
        out("Vacio");
        return;
    }
    nodo<T>* tmp;
    tmp=top;
    top=tmp->ptr;
    delete tmp;
}
template<typename T>
void Pila<T>::push(T el, long pr){

    nodo<T>* tmp = new nodo<T>;
    tmp->info=el;
    tmp->ptr=top;
    top=tmp;

}
template<typename T>
void Pila<T>::print(){
    if(top==NULL){
        out("Vacio");
        return;
    }
    nodo<T>* tmp;

    tmp=top;
    while (tmp!=NULL)
    {
        out(tmp->info);
        out("-----");
        tmp = tmp->ptr;
    }
    tmp=nullptr;
    tmp->~nodo();
    

}

template class Pila<int>;