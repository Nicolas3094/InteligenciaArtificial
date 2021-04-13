#include "../headers/exe.hpp"
void prob2(int i, int j){
    print("Entra");
}
void prob2(int,int);
void exePila()
{
    BST<int>* raiz= new BST<int>();
    int res;
    char val;
    Nodo<int> *pd,*hj;
    //raiz->crearArbol();
    while(1){
        print("");
        print("1. Buscar nodo");
        print("2. Buscar padre");
        print("3. Eliminar Nodo");
        print("4. Agregar nodo");
        print("5. Mostrar.");
        print("");
        cin>>res;
        if(res==1){
            print("Ingrese el valor del nodo");
            cin>>res;
            raiz->buscarNodo(res, &hj, &pd);
            if(hj==nullptr){
                print("No existe");
            }else{
                print("Encontrado");
            }
        }else if(res==2){
            print("Ingrese el valor del nodo");
            cin>>res;
            raiz->buscarNodo(res, &hj, &pd);
            if(hj==nullptr){
                print("No existe");
            }else{
                print("Valor del padre: "<<pd->info);
            }
        }else if(res==3){

        }else if(res == 4){
            print("Agregue nodo");
            cin>>res;
            raiz->insertarNodo(res);
            raiz->display(raiz->Raiz,1);
        }
        else if(res==5){
            raiz->display(raiz->Raiz,1);
        }
        else{
            break;
        }

    }
    

    raiz->crearArbol();
    raiz->insertarNodo(81);
    pd= raiz->encontrarPadre(81);
    if(pd!=nullptr){
        print("Encuentra");
        print(pd->info);
        print(pd->Izq->info);
    }
   
    

    raiz->~BST();
}
