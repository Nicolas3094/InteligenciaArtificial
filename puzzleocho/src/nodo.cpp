#include "../headers/nodo.hpp"

Nodo *Arbol::crearNodo(int prof, int cost, Nodo *padre, Estado *estado)
{
    Nodo *nd = (Nodo *)new (Nodo);
    nd->profundidad = prof;
    nd->costo = cost;
    nd->padre = padre;
    nd->estado = estado;
    return nd;
}

list<Nodo *> Arbol::hijosNodo(Nodo *nodoActual)
{
    Estado *Nextestado;
    Nodo *hijo;
    list<Nodo *> hj;
    Tablero tabl;

    if (nodoActual->estado->mov != UP && (Nextestado = tabl.MoverEstado(DOWN, nodoActual->estado)) != nullptr)
    {
        hijo = crearNodo(nodoActual->profundidad + 1, nodoActual->costo + 1, nodoActual, Nextestado);
        hj.push_back(hijo);
    }
    if (nodoActual->estado->mov != DOWN && (Nextestado = tabl.MoverEstado(UP, nodoActual->estado)) != nullptr)
    {
        hijo = crearNodo(nodoActual->profundidad + 1, nodoActual->costo + 1, nodoActual, Nextestado);
        hj.push_back(hijo);
    }
    if (nodoActual->estado->mov != LEFT && (Nextestado = tabl.MoverEstado(RIGHT, nodoActual->estado)) != nullptr)
    {
        hijo = crearNodo(nodoActual->profundidad + 1, nodoActual->costo + 1, nodoActual, Nextestado);
        hj.push_back(hijo);
    }
    if (nodoActual->estado->mov != RIGHT && (Nextestado = tabl.MoverEstado(LEFT, nodoActual->estado)) != nullptr)
    {
        hijo = crearNodo(nodoActual->profundidad + 1, nodoActual->costo + 1, nodoActual, Nextestado);
        hj.push_back(hijo);
    }
    return hj;
}
Arbol::Arbol(Tablero &tab)
{
    tab = tab;
    vertice = nullptr;
}

void Arbol::BFS(Estado &problema)
{
    Cola<Nodo *> *cola = new Cola<Nodo *>();

    map<Nodo *, bool> visited;
    Nodo *inicial;
    inicial = crearNodo(1, 1, nullptr, &problema);
    cola->push(inicial);
    visited.insert(pair<Nodo *, bool>(inicial, false));

    list<Nodo *> hj;

    while (!cola->vacia())
    {
        
        cola->pop(vertice);
        visited[vertice] = true;

        if (tab->EstadosIguales(*tab->EstadoMeta(), *vertice->estado))
        {
            print("Resultado final");
            tab->Mostrar(*vertice->estado);
            cola->~Cola();
            return;
        }
        tab->Mostrar(*vertice->estado);

        hj = hijosNodo(vertice);
        for (auto elment : hj)
        {
            bool inMap = false;
            for (auto &visit : visited)
            {
                if (tab->EstadosIguales(*elment->estado, *visit.first->estado))
                {
                    inMap = true;
                    break;
                }
            }
            if (!inMap)
            {
                cola->push(elment);
                visited.insert(pair<Nodo *, bool>(elment, false));
            }
        }

        if (!hj.empty())
            hj.clear();
    }
    print("Se vacio");
}
void Arbol::MostarCamino(Nodo *nodo)
{
}
