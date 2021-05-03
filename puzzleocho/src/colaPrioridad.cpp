#include "../headers/Estructuras/colaPrioridad.hpp"
template <typename T, typename K>
ColaPrioridad<T,K>::ColaPrioridad()
{
    frente = nullptr;
}

template <typename T, typename K>
T ColaPrioridad<T,K>::pop()
{
    T value;
    if (vacia())
    {
        delete &value;
        return value;
    }
    value = frente->valor;
    NodoPrioridad<T> *tmp;
    tmp = frente;
    frente = tmp->ptr;
    tmp=nullptr;
    delete tmp;
    return value;
}
template <typename T, typename K>
void ColaPrioridad<T,K>::push(T valor, long prior)
{

    NodoPrioridad<T> *tmp, *q;

    tmp = new NodoPrioridad<T>(prior, valor);

    if ( vacia() || prior < frente->prioridad)
    {
        tmp->ptr = frente;
        frente = tmp;
    }
    else
    {
        q = frente;
        while (q->ptr != nullptr && q->ptr->prioridad <= prior)
        {
            q = q->ptr;
        }
        tmp->ptr = q->ptr;
        q->ptr = tmp;
    }
}
template <typename T, typename K>
bool ColaPrioridad<T,K>::vacia()
{
    return frente == nullptr;
}
template <typename T, typename K>
void ColaPrioridad<T,K>::vaciar()
{
    while (!vacia())
    {
        pop();
    }
}
template <typename T, typename K>
void ColaPrioridad<T,K>::imprimir()
{
    NodoPrioridad<T> *tmp;
    tmp = frente;
    while (tmp != nullptr)
    {
        cout << " |v: " << tmp->valor << "| P: " << tmp->prioridad << "| -> ";
        tmp = tmp->ptr;
    }
    print("null");
}


template class ColaPrioridad<Nodo*, As>;
