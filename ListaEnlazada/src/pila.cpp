#include "../headers/pila.hpp"

Pila::Pila(){
    top=NULL;
}
void Pila::pop(){
    if(top==NULL){
        out("Vacio");
        return;
    }
    nodo* tmp;
    tmp=top;
    top=tmp->ptr;
    delete tmp;
}
void Pila::push(){
    
    int el;
    out("Digite elemento");
    std::cin>>el;
    nodo* q,*tmp;
    tmp = (nodo *)new(nodo);
    tmp->info=el;
    tmp->ptr=top;
    
    top=tmp;

}
void Pila::print(){
    if(top==NULL){
        out("Vacio");
        return;
    }
    nodo* tmp;

    tmp=top;
    while (tmp!=NULL)
    {
        out(tmp->info);
        out("-----");
        tmp = tmp->ptr;
    }
    

}