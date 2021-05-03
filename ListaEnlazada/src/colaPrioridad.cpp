#include "../headers/colaPrioridad.hpp"
template <typename T>
ColaPrioridad<T>::ColaPrioridad()
{
    frente = NULL;
}
template <typename T>
void ColaPrioridad<T>::push(T val, long prior)
{
    nodo<T> *tmp, *q;
    tmp = new nodo;
    tmp->info = val;
    tmp->prioridad = prior;

    tmp->ptr = nullptr;

    if (vacia() || prior < frente->prioridad)
    {
        tmp->ptr = frente;
        frente = tmp;
        return;
    }
    q = frente;
    while (q->ptr != nullptr && q->ptr->prioridad <= prior)
    {
        q = q->ptr;
    }
    tmp->ptr = q->ptr;
    q->ptr = tmp;
}
template <typename T>
T ColaPrioridad<T>::pop()
{
    T elemento;
    if (vacia())
    {
        out("Vacia");
        delete &elemento return elemento;
    }
    nodo<T> *tmp;
    tmp = frente;
    elemento = tmp->info;
    frente = tmp->ptr;
    tmp = nullptr;
    delete tmp;
    return elemento;
}
template <typename T>
void ColaPrioridad<T>::print()
{
    if (vacia())
    {
        out("Vacia");
        return;
    }
    nodo<T> *init, *fin;
    init = frente;
    while (init->ptr != nullptr)
    {
        cout << init->info << "," << init->prioridad << "->" << init->ptr->info << "|";
        init = init->ptr;
    }
    std::cout << init->info << "," << init->prioridad << "->"
              << "NULL";
    out("");
}
template <typename T>
bool ColaPrioridad<T>::vacia()
{
    return frente == nullptr;
}

template class ColaPrioridad<int>;