#include "../headers/colaPrioridad.hpp"

ColaPrioridad::ColaPrioridad(){
    frente=NULL;
}

void ColaPrioridad::push(){
    int val, prior;
    out("Digite valor");
    std::cin>>val;
    out("Digite prioridad");
    std::cin>>prior;

    nodo *tmp,*q;
    tmp = (nodo*)new(nodo);
    
    tmp->info=val;
    tmp->prioridad=prior;

    tmp->ptr=NULL;

    if(frente==NULL || prior < frente->prioridad){
        tmp->ptr=frente;
        frente=tmp;
    }else{
        q=frente;
        while(q->ptr!=NULL && q->ptr->prioridad<=prior){
            q=q->ptr;
        }
        tmp->ptr = q->ptr;
        q->ptr=tmp;

    }
}
void ColaPrioridad::pop(){

    if(frente==NULL){
        out("Vacia");
        return;
    }
    nodo *tmp;
    tmp = frente;
    frente=tmp->ptr;
    delete tmp;
}
void ColaPrioridad::print(){
    if(frente==NULL){
        out("Vacia");
        return;
    }
    nodo *init, *fin;
    init=frente;

    while(init->ptr!=NULL){
        std::cout<<init->info<<","<< init->prioridad <<"->"<< init->ptr->info <<"|";
        init=init->ptr;
    }
    std::cout<<init->info<<","<< init->prioridad <<"->"<< "NULL";
    out("");
}