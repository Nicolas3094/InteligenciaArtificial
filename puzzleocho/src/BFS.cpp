#include "../headers/Algoritmo/BFS.hpp"

BFS::BFS() {}

BFS::~BFS() {}

void BFS::Resolver(Nodo **raiz, int &pasos)
{
    BusquedaGrafo(raiz, pasos, new Cola<Nodo*>);
}