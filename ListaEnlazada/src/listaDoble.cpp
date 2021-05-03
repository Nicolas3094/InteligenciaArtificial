#include "../headers/listaDoble.hpp"
ListaDoble::ListaDoble(){}
void ListaDoble::Create_List(int valor){

    Nodo *q, *tmp;
    tmp = new Nodo();
    tmp->info=valor;
    tmp->Lptr=nullptr;
    tmp->Rptr=nullptr;

    if(inicio==nullptr){
        inicio=tmp;
        return;
    }
    q=inicio;

    while(q->Rptr!=nullptr){
        q=q->Rptr;
    }

    q->Rptr=tmp;
    tmp->Lptr=q;


}
void ListaDoble::AddAtBeg(int data){
   if(inicio==nullptr){
        out("Lista vacia");
        return;
    }
    Nodo *tmp;
    tmp =new Nodo();
    tmp->info=data;
    tmp->Rptr=inicio;
    tmp->Lptr=nullptr;
    inicio->Lptr=tmp;
    inicio=tmp;

}
void ListaDoble::AddAfter(int posicion,int valor){
    if(inicio==nullptr){
        out("Lista vacia");
        return;
    }
    Nodo *tmp,*q;
    q=inicio;
    for(int i =0; i<posicion-1; i++){
        q=q->Rptr;
        if(q->Rptr==NULL){
            out("Posicion fuera");
            return;
        }
    }
    tmp=new Nodo();
    tmp->info=valor;
    
    tmp->Rptr=q->Rptr;
    tmp->Lptr=q;

    q->Rptr=tmp;

}
void ListaDoble::Delete(){
   if(inicio==nullptr){
        out("Lista vacia");
        return;
    }
    int pos;
    out("Digite el elemento a eliminar");
    std::cin>>pos;
    Nodo *q, *tmp;
    if(pos==1 ){
        tmp=inicio;
        inicio= tmp->Rptr;
        inicio->Lptr=nullptr;
        delete tmp;
        return;
    }else if(pos<=0){
        out("No existe dicha posicion");
        return;
    }
    q=Search(pos-1);
    if(q==nullptr){
        return;
    }
    if(q->Rptr->Rptr!= nullptr){
        tmp = q->Rptr;
        q->Rptr=tmp->Rptr;
        tmp->Rptr->Lptr=q;
        delete tmp;
    }else{
        tmp=q->Rptr;
        q->Rptr=nullptr;
        delete tmp;
    } 
}
int ListaDoble::Count(){
   if(inicio==nullptr){
        out("Lista vacia");
        return 0;
    }
    Nodo* q;
    q=inicio;
    int i=1;
    while (q->Rptr!= nullptr)
    {
        i++;
        q=q->Rptr;
    }
    return i;
    
}

Nodo* ListaDoble::Search(int posicion){
 if(inicio==nullptr){
        out("Lista vacia");
        return NULL;
    }
    Nodo *q;
    q=inicio;
    for(int i =0; i<posicion-1; i++){
        q=q->Rptr;
        if(q->Rptr==nullptr){
            out("Posicion fuera");
            return NULL;
        }
    }
    return q;
}
void ListaDoble::Display(){
   Nodo* q;
    if(inicio == nullptr){
        out("Lista vacia");
        return;
    }
    q=inicio;
    std::cout<<"\n\nLista es: ";
    while(q!=nullptr){
        if(q->Lptr==NULL){
            std::cout<<"NULL<-";
        }else{
            std::cout<<q->Lptr->info<<"<-";
        }
        std::cout<<q->info;
        if(q->Rptr==NULL){
            std::cout<<"->NULL";
        }else{
            std::cout<<"->"<<q->Rptr->info<<" || ";
        }
        q=q->Rptr;
    }
    out("");
    
}
void ListaDoble::Reverse(){
   if(inicio==nullptr){
        out("Lista vacia");
        return;
    }
    Nodo *s,*tmp,*q;
    q=inicio;
    tmp = inicio->Rptr;
    s= tmp->Rptr;
    
    q->Rptr=nullptr;
    q->Lptr=tmp;

    tmp->Rptr=q;
    tmp->Lptr=s;

    while(s!=nullptr){
        q=tmp;
        tmp=s;
        s=s->Rptr;
        tmp->Rptr=q;
        tmp->Lptr=s;   
    }
    inicio=tmp;

}