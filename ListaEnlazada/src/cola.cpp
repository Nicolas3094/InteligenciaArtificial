#include "../headers/cola.hpp"

Cola::Cola(){
    frente=NULL;
    cola=NULL;
}

void Cola::push(){
    int val;
    out("Digite valor");
    std::cin>>val;
    nodo *tmp;
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
void Cola::pop(){

    if(frente==NULL){
        out("Vacia");
        return;
    }
    nodo *tmp;
    tmp = frente;
    frente=tmp->ptr;
    tmp=nullptr;
    delete tmp;
}
void Cola::print(){
    if(frente==NULL){
        out("Vacia");
        return;
    }
    nodo *init, *fin;
    init=frente;
    while(init!=NULL){
        out(init->info<<"|");
        init=init->ptr;
    }
}