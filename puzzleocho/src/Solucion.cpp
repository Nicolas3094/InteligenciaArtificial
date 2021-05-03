#include "../headers/Algoritmo/Solucion.hpp"

Solucion::Solucion(){}
Solucion::~Solucion(){}

list<Nodo *> Solucion::hijosNodo(Nodo &nodoActual)
{
    list<Nodo *> hj;
    Estado *Nextestado;
    if (nodoActual.estado->mov != ARRIBA && (Nextestado = Tablero::MoverEstado(ABAJO, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));
    if (nodoActual.estado->mov != ABAJO && (Nextestado = Tablero::MoverEstado(ARRIBA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));
    if (nodoActual.estado->mov != IZQUIERDA && (Nextestado = Tablero::MoverEstado(DERECHA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));
    if (nodoActual.estado->mov != DERECHA && (Nextestado = Tablero::MoverEstado(IZQUIERDA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));
    Nextestado = nullptr;
    Nextestado->~Estado();
    return hj;
}