#include "../headers/strpila.hpp"

void push(NODO *ptr)
{
    if (ptr->top == LIMITE - 1)
    {
        std::cout << "Pila llena" << std::endl;
        return;
    }
    std::cout << "Inserta elemento " << std::endl;
    int elemento;
    std::cin >> elemento;
    ptr->pila[++ptr->top] = elemento;
}
void pop(NODO *ptr)
{
    std::cout << "Elemento quitado" << std::endl;
    if (ptr->top == -1)
    {
        std::cout << "Pila vacia" << std::endl;
        return;
    }
    int elemento;
    elemento = ptr->pila[ptr->top--];
    std::cout <<"Elemento borrado "<< elemento << std::endl;
}
void printPila(NODO *ptr)
{
    for(int i = ptr->top; i >= 0; i--){
       std::cout <<"posicion: "<<i <<"; valor: "<<ptr->pila[i]<< std::endl;
    }
}
void exe(){
    char res;
    NODO ndo;
    NODO* ptr;
    ptr = &ndo;
    ptr->top=-1;
    do{
        push(ptr);
        printPila(ptr);
        std::cout <<"Desea continuar"<< std::endl;
        std::cin>>res;
    }while(res=='y');
    do{
        std::cout <<"Borrar top"<< std::endl;
        std::cin>>res;
        if(res!='y'){
            break;
        }
        pop(ptr);
        printPila(ptr);
    }while(res=='y');
}