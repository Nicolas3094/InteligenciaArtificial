#include "../headers/Algoritmo/Solucion.hpp"

Solucion::Solucion() {}
Solucion::~Solucion() {}

list<Nodo *> Solucion::hijosNodo(Nodo &nodoActual)
{
    list<Nodo *> hj;
    Estado *Nextestado;
    if (nodoActual.estado->mov != ARRIBA &&
        (Nextestado = Tablero::MoverEstado(ABAJO, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad+1,&nodoActual,*Nextestado));
    if (nodoActual.estado->mov != ABAJO &&
        (Nextestado = Tablero::MoverEstado(ARRIBA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad+1,&nodoActual,*Nextestado));
    if (nodoActual.estado->mov != IZQUIERDA &&
        (Nextestado = Tablero::MoverEstado(DERECHA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad+1,&nodoActual,*Nextestado));
    if (nodoActual.estado->mov != DERECHA &&
        (Nextestado = Tablero::MoverEstado(IZQUIERDA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad+1,&nodoActual,*Nextestado));

    Nextestado = nullptr;
    Nextestado->~Estado();
    return hj;
}
void Solucion::BusquedaGrafo(Nodo **raiz, int &pasos, ComunStr<Nodo *> *cola)
{
    map<long long int, bool> visitados;
    Estado meta = Tablero::EstadoMeta();
    pasos = 0;
    Nodo *root = *raiz;

    cola->push(*raiz);
    visitados[Tablero::HashEstado(*root->estado)] = true;
    while (!cola->vacia())
    {

        *raiz = cola->pop();
        root = *raiz;

        if (meta == *root->estado)
        {
            root = nullptr;
            root->~Nodo();
            cola->vaciar();
            delete cola;
            return;
        }

        list<Nodo *> rama = hijosNodo(**raiz);
        for (Nodo *nodoV : rama)
        {
            long long int llave = Tablero::HashEstado(*nodoV->estado);
            if (!visitados[llave])
            {
                visitados[llave] = true;
                cola->push(nodoV);
            }
        }
        pasos++;
    }
    raiz = nullptr;
    root = nullptr;
    root->~Nodo();
    cola->vaciar();
    delete cola;
    pasos = -1;
}