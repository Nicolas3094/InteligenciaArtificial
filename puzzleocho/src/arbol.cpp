#include "../headers/Estructuras/arbol.hpp"

Arbol::Arbol() : pasos(0){ raiz = new Nodo; }
Arbol::Arbol(Nodo *pdr) : pasos(0){ raiz = pdr; }
Arbol::~Arbol()
{
    raiz = raiz != nullptr ? nullptr : raiz;
    raiz->~Nodo();
}
void Arbol::MostarCamino(Nodo &nodo)
{
    if (&nodo == nullptr)
    {
        print("No hay camino en este conjunto.");
        print("Pasos: " << pasos);
        return;
    }
    Nodo *tmp;
    tmp = &nodo;
    while (tmp != nullptr)
    {
        Tablero::Mostrar(*tmp->estado);
        tmp = tmp->padre;
    }
    tmp = nullptr;
    tmp->~Nodo();
    print("Profundidad: " << nodo.profundidad);
    print("Pasos: " << pasos);
}
void Arbol::EncontrarSolucion(Algoritmo<Nodo*> *alg, Estado &problema)
{
    raiz->estado = &problema;
    raiz->profundidad = 0;
    raiz->padre = nullptr;
    alg->Resolver(&raiz, pasos);
    alg = nullptr;
    delete alg;
}
