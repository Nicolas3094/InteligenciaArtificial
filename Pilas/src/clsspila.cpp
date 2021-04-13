#include "../headers/clsspila.hpp"

PILA::PILA(){
    top=-1;
}

void PILA::push(){
    if(top== LIMITE-1){
        out("Se ha alcanzado el maximo");
        return;
    }
    int elemento;

    out("Inserte pila:");

    std::cin>>elemento;
    pila[++top]=elemento;
}
void PILA::pop(){
    if(top == -1){
        out("Pila vacia");
        return;
    }
    int elemento;
    pila[top--]=elemento;
    out("elemento eliminado: "<<elemento);
        
}
void PILA::print(){
    for(int i = top ; i>=0; i--){
        out(i<<"|"<<pila[i]);
    }
}

void exe2(){
    char res;
    PILA ptr;
    do{
        ptr.push();
        ptr.print();
        std::cout <<"Desea continuar"<< std::endl;
        std::cin>>res;
    }while(res=='y');
    do{
        std::cout <<"Borrar top"<< std::endl;
        std::cin>>res;
        if(res!='y'){
            break;
        }
        ptr.pop();
        ptr.print();
    }while(res=='y');
}