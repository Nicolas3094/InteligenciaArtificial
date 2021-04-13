#ifndef BST_H
#define BST_H
#include "arbol.hpp"
#include "virtualArbol.hpp"

template<typename T>
class BST: public Arbol<T>, VArbol<T>{
        
    public:
        Nodo<T>* Raiz;   
        BST();
        ~BST();

        void crearArbol();
        void eliminarNodo(T);
        void insertarNodo(T);
        void buscarNodo(T, Nodo<T>**, Nodo<T>**);
        Nodo<T>* encontrarPadre(T);
        Nodo<T>* crearNodo(T);
        void display(Nodo<T>* , int );
};


#endif //BST_H