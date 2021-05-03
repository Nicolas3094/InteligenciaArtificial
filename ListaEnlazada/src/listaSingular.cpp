#include "../headers/listaSingular.hpp"

template<typename T>
ListaSingular<T>::ListaSingular(){}

template<typename T>
void ListaSingular<T>::Create_List(T valor){

    nodo *q, *tmp;
    //Crear un nodo con el operador new
    tmp = new nodo(valor);

    //Si la lista esta vacia
    if(inicio==NULL){
        inicio=tmp;

    }else{//Se añade elemento al final de la lista
        
        //Empieza un 'recorrido', iniciando en elnodo inicio o cabeza
        q=inicio;

        while(q->ptr!=NULL){
            //mientras q no esta al final de la lista, que es cuando apunta nodo a NULL
            //q es igual al apuntador del actual nodo (empezando en inicio)
            q = q->ptr;

        }
        // q (que es igual al nodo fianl) tiene el nodo apuntando a ultimo valor
        q->ptr=tmp;        
    }

}

template<typename T>
void ListaSingular<T>::AddAtBeg(T data){
    if(inicio==NULL){
        out("Lista vacia");
        return;
    }
    nodo *tmp;
    tmp = new nodo(data, inicio);
    inicio=tmp;


}

template<typename T>
void ListaSingular<T>::AddAfter(int posicion,T valor){
     if(inicio==NULL){
        out("Lista vacia");
        return;
    }
    nodo *tmp,*q;
    q=inicio;
    for(int i =0; i<posicion-1; i++){
        q=q->ptr;
        if(q->ptr==NULL){
            out("Posicion fuera");
            return;
        }
    }
    tmp=new nodo;
    tmp->info=valor;
    tmp->ptr=q->ptr;
    q->ptr=tmp;
    

}

template<typename T>
void ListaSingular<T>::Delete(){
    if(inicio==NULL){
        out("Lista vacia");
        return;
    }
    int pos;
    out("Digite el elemento a eliminar");
    std::cin>>pos;
    nodo *q, *tmp;

    if(pos==1 ){
        tmp=inicio;
        inicio= tmp->ptr;
        delete tmp;
        return;
    }else if(pos<=0){
        out("No existe dicha posicion");
        return;
    }

    q=Search(pos-1);
    if(q==NULL){
        return;
    }
    if(q->ptr->ptr!= NULL){
        tmp = q->ptr;
        q->ptr=tmp->ptr;
        delete tmp;
    }else{
        tmp=q->ptr;
        q->ptr=NULL;
        delete tmp;
    }    

}

template<typename T>
int ListaSingular<T>::Count(){
    if(inicio==NULL){
        out("Lista vacia");
        return 0;
    }
    nodo* q;
    q=inicio;
    int i=1;
    while (q->ptr!= NULL)
    {
        i++;
        q=q->ptr;
    }
    return i;
    
}
template<typename T>
nodo<T>* ListaSingular<T>::Search(int posicion){
    if(inicio==NULL){
        out("Lista vacia");
        return NULL;
    }
    nodo *tmp,*q;
    q=inicio;
    for(int i =0; i<posicion-1; i++){
        q=q->ptr;
        if(q->ptr==NULL){
            out("Posicion fuera");
            return NULL;
        }
    }
    return q;

}
template<typename T>
void ListaSingular<T>::Display(){
    nodo* q;
    if(inicio == NULL){
        out("Lista vacia");
        return;
    }
    q=inicio;
    std::cout<<"\n\nLista es: ";
    std::cout<<" | ";
    while(q!=NULL){
        std::cout<<q->info<<" | ";
        q=q->ptr;
    }
    out("");
    
}

template<typename T>
void ListaSingular<T>::Reverse(){
    if(inicio==NULL){
        out("Lista vacia");
        return;
    }
    nodo *s,*tmp,*q;
    q=inicio;
    tmp = inicio->ptr;
    s= tmp->ptr;
    
    q->ptr=NULL;
    tmp->ptr=q;

    while(s!=NULL){
        q=tmp;
        tmp=s;
        s=s->ptr;
        tmp->ptr=q;   
    }
    inicio=tmp;

}