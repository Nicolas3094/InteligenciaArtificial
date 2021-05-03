#include "../headers/Estructuras/colaPrioridad.hpp"
template <typename T>
ColaPrioridad<T>::ColaPrioridad(function<long(T)> fn):tamano(0)
{
    this->lambda=fn;
    frente = nullptr;
}
template <typename T>
ColaPrioridad<T>::~ColaPrioridad()
{
    vaciar();
}
template <typename T>
T ColaPrioridad<T>::pop()
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

    this->tamano--;

    delete tmp;
    return value;
}
template <typename T>
void ColaPrioridad<T>::push(T valor)
{
    long prior = lambda(valor);
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
    this->tamano++;
}
template <typename T>
bool ColaPrioridad<T>::vacia()
{
    return frente == nullptr;
}
template <typename T>
void ColaPrioridad<T>::vaciar()
{
    while (!vacia())
    {
        pop();
    }
}
template <typename T>
void ColaPrioridad<T>::imprimir()
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
template <typename T>
T ColaPrioridad<T>::operator[](int index)
{
    if (index < 0 || index > tamano - 1)
        throw invalid_argument("Index out of range");
    int i = 0;
    NodoPrioridad<T> *ini;
    T tmp;
    ini = frente;
    while (ini != nullptr)
    {
        if (i == index)
        {
            tmp = frente->valor;
            break;
        }
        i++;
    }
    ini = ini == nullptr ? ini : nullptr;
    ini->~NodoPrioridad();

    return tmp;
}

template class ColaPrioridad<Nodo*>;
