#include "../headers/Estructuras/cola.hpp"

template <typename T>
Cola<T>::~Cola()
{
    while (frente != nullptr)
    {
        pop();
    }
}

template <typename T>
bool Cola<T>::vacia()
{
    return frente == nullptr;
}

template <typename T>
Cola<T>::Cola() : tamano(0)
{
    cola, frente = nullptr;
}
template <typename T>
void Cola<T>::push(T valor)
{
    NodoSingular<T> *tmp = new NodoSingular<T>(valor);

    if (frente == nullptr)
        frente = tmp;

    if (cola != nullptr)
        cola->ptr = tmp;

    cola = tmp;
    tamano++;

    tmp = nullptr;
    tmp->~NodoSingular();
}

template <typename T>
T Cola<T>::pop()
{
    T valTemp;

    if (frente == nullptr)
    {
        delete &valTemp;
        return valTemp;
    }
    NodoSingular<T> *tmp;
    valTemp = frente->valor;
    tmp = frente;
    frente = tmp->ptr;
    tamano--;
    tmp = nullptr;
    tmp->~NodoSingular();

    return valTemp;
}
template <typename T>
void Cola<T>::recorrer(const function<void(T, bool &)> &fn, bool romper)
{
    if (frente == nullptr)
        return;

    NodoSingular<T> *ini, *fin;
    ini = frente;
    romper = false;
    while (ini != nullptr && !romper)
    {
        fn(ini->valor, romper);
        ini = ini->ptr;
    }
    ini->~NodoSingular();
    fin->~NodoSingular();
}

template <typename T>
T Cola<T>::operator[](int index)
{
    if (index < 0 || index > tamano - 1)
        throw invalid_argument("Index out of range");
    int i = 0;
    NodoSingular<T> *ini;
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
    ini->~NodoSingular();

    return tmp;
}

template class Cola<Nodo *>;
template class Cola<int>;
