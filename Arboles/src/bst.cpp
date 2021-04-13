#include "../headers/bst.hpp"
template <typename T>
BST<T>::BST()
{
    this->Raiz = nullptr;
}
template <typename T>
BST<T>::~BST()
{
}
template <typename T>

Nodo<T> *BST<T>::encontrarPadre(T val)
{
    if (Raiz == nullptr)
    {
        print("Arbol vacio");
        return nullptr;
    }
    Nodo<T> *pdr, *hj;
    buscarNodo(val, &hj, &pdr);
    if (hj == nullptr)
    {
        print("No existe");
        return nullptr;
    }
    return pdr;
}
template <typename T>

void BST<T>::eliminarNodo(T val)
{
}
template <typename T>
void BST<T>::insertarNodo(T val)
{

    Nodo<T> *q, *hijo = nullptr, *padre = nullptr;
    buscarNodo(val, &hijo, &padre);

    if (hijo != nullptr)
    {
        print("ya esta insertado");
        return;
    }
    print("Insertando");
    q = new Nodo<T>(val);
    if (padre == nullptr)
    {
        Raiz = q;
    }
    else
    {
        if (val < padre->info)
        {
            padre->Izq = q;
        }
        else
        {
            padre->Der = q;
        }
    }
}
template <typename T>
void BST<T>::crearArbol()
{
    Raiz = new Nodo<int>(50);

    Raiz->Der = new Nodo<int>(75);
    Raiz->Der->Izq = new Nodo<int>(60);
    Raiz->Der->Izq->Der = new Nodo<int>(65);
    Raiz->Der->Izq->Izq = new Nodo<int>(55);

    Raiz->Der->Der = new Nodo<int>(80);
    Raiz->Der->Der->Der = new Nodo<int>(85);

    Raiz->Izq = new Nodo<int>(25);
    Raiz->Izq->Der = new Nodo<int>(40);
    Raiz->Izq->Der->Der = new Nodo<int>(45);
    Raiz->Izq->Der->Izq = new Nodo<int>(30);

    Raiz->Izq->Izq = new Nodo<int>(20);
    Raiz->Izq->Izq->Izq = new Nodo<int>(10);
}
template <typename T>
void BST<T>::buscarNodo(T val, Nodo<T> **hijo, Nodo<T> **padre)
{
    Nodo<T> *q, *tmp;

    if (Raiz == nullptr)
    {
        print("Arbol Vacio");
        *padre = nullptr;
        *hijo = nullptr;
        return;
    }

    if (Raiz->info == val)
    {
        *padre = nullptr;
        *hijo = Raiz;
        return;
    }

    if (val > Raiz->info)
    {
        tmp = this->Raiz->Der;
    }
    else if (val < Raiz->info)
    {
        tmp = Raiz->Izq;
    }

    q = Raiz;
    while (tmp != nullptr)
    {
        if (val == tmp->info)
        {
            *hijo = tmp;
            *padre = q;
            return;
        }
        q = tmp;
        if (val < tmp->info)
        {
            tmp = tmp->Izq;
        }
        else
        {
            tmp = tmp->Der;
        }
    }
    *hijo = nullptr;
    *padre = q;
}
template <typename T>
void BST<T>::display(Nodo<T>* ptr, int level)
{
    int i;
    if (ptr != nullptr)
    {
        display(ptr->Der, level + 1);
        cout <<'\n';
        for (i = 0; i < level; i++)
            cout <<" ";
        cout << ptr->info;
        display(ptr->Izq, level + 1);
    } /*End of if*/
} /*End of display()*/
template class BST<int>;
