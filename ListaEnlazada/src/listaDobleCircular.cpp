#include "../headers/listaDobleCircular.hpp"
ListaDobleCircular::ListaDobleCircular() {}
void ListaDobleCircular::Create_List(int valor)
{

    Nodo *q, *tmp;
    tmp = new Nodo();
    tmp->info = valor;

    tmp->Lptr = NULL;
    tmp->Rptr = inicio;

    if (inicio == NULL)
    {
        inicio = tmp;
        inicio->Lptr = inicio;
        inicio->Rptr = inicio;
        return;
    }

    q = inicio;

    while (q->Rptr != inicio)
    {
        q = q->Rptr;
    }
    q->Rptr = tmp;
    tmp->Lptr = q;
    inicio->Lptr = tmp;
}
void ListaDobleCircular::AddAtBeg(int data)
{
    if (inicio == NULL)
    {
        out("Lista vacia");
        return;
    }
    Nodo *tmp, *q;

    tmp = new Nodo();
    tmp->info = data;

    tmp->Lptr = inicio->Lptr;
    tmp->Rptr = inicio;

    std::cout << inicio->Lptr->info << "<-";
    std::cout << inicio->info;
    std::cout << "->" << inicio->Rptr->info;

    out("");
    if (inicio->Rptr == inicio)
    {
        inicio->Rptr = tmp;
    }
    else
    {
        q = inicio;
        while (q->Rptr != inicio)
        {
            q = q->Rptr;
        }
        q->Rptr = tmp;
    }
    inicio->Lptr = tmp;

    inicio = tmp;

    std::cout << inicio->Lptr->info << "<-";
    std::cout << inicio->info;
    std::cout << "->" << inicio->Rptr->info << "|";

    std::cout << inicio->Rptr->Lptr->info << "<-";
    std::cout << inicio->Rptr->info;
    std::cout << "->" << inicio->Rptr->Rptr->info;
}
void ListaDobleCircular::AddAfter(int posicion, int valor)
{
    if (inicio == NULL)
    {
        out("Lista vacia");
        return;
    }

    Nodo *tmp, *q;
    q = inicio;
    for (int i = 0; i < posicion - 1; i++)
    {
        q = q->Rptr;
        if (q->Rptr == NULL)
        {
            out("Posicion fuera");
            return;
        }
    }
    tmp = new Nodo();
    tmp->info = valor;
    if (q->Rptr == inicio)
    {
        inicio->Lptr = tmp;
    }

    tmp->Rptr = q->Rptr;
    tmp->Lptr = q;
    q->Rptr = tmp;
}
void ListaDobleCircular::Delete()
{
    if (inicio == NULL)
    {
        out("Lista vacia");
        return;
    }
    int pos;
    out("Digite el valor eliminar");
    std::cin >> pos;
    Nodo *q, *tmp;
    if (inicio->Rptr == inicio && inicio->info == pos)
    {
        tmp = inicio;
        inicio = NULL;
        delete tmp;
        return;
    }
    q = inicio;
    if (q->Rptr != inicio)
    {
        while (q->Rptr != inicio)
        {
            if (q->info == pos)
            {
                if (q == inicio)
                {
                    tmp = q->Rptr;
                    tmp->Lptr = q->Lptr;

                    inicio->Lptr->Rptr = tmp;
                    inicio = tmp;
                    delete q;
                    return;
                }
                else
                {
                    tmp = q->Rptr;
                    tmp->Lptr = q->Lptr;
                    q->Lptr->Rptr = tmp;
                    delete q;
                    return;
                }
            }
            q = q->Rptr;
        }
        if (q->info != pos)
        {
            out("No hay dicho valor");
            return;
        }
        tmp = q->Lptr;
        tmp->Rptr = inicio;
        inicio->Lptr = tmp;
        delete q;
    }
}

Nodo *ListaDobleCircular::Search(int posicion)
{
    if (inicio == NULL)
    {
        out("Lista vacia");
        return NULL;
    }
    Nodo *q;
    q = inicio;
    for (int i = 0; i < posicion - 1; i++)
    {
        q = q->Rptr;
        if (q->Rptr == NULL)
        {
            out("Posicion fuera");
            return NULL;
        }
    }
    return q;
}
void ListaDobleCircular::Display()
{
    Nodo *q;
    if (inicio == NULL)
    {
        out("Lista vacia");
        return;
    }
    q = inicio;
    std::cout << "\n\nLista es: ";
    while (q->Rptr != inicio)
    {
        std::cout << q->Lptr->info << "<-";
        std::cout << q->info;
        std::cout << "->" << q->Rptr->info << " | ";
        q = q->Rptr;
    }
    std::cout << q->Lptr->info << "<-";
    std::cout << q->info;
    std::cout << "->" << q->Rptr->info;
    out("");
}
