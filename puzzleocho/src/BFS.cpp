#include "../headers/Algoritmo/BFS.hpp"

BFS::BFS() {}

BFS::~BFS() {}

void BFS::Resolver(Nodo **raiz, int &pasos)
{

    map<long long int, bool> visitados;

    Cola<Nodo *> cola;

    Estado meta = Tablero::EstadoMeta();

    pasos = 0;

    cola.push(*raiz);

    Nodo *root = *raiz;

    visitados[Tablero::HashEstado(*root->estado)] = true;

    while (!cola.vacia())
    {

        *raiz = cola.pop();
        root = *raiz;

        if (meta == *root->estado)
        {
            root = nullptr;
            root->~Nodo();
            return;
        }

        list<Nodo *> rama = hijosNodo(**raiz);
        for (Nodo *nodoV : rama)
        {
            long long int llave = Tablero::HashEstado(*nodoV->estado);
            if (!visitados[llave])
            {
                visitados[llave] = true;
                cola.push(nodoV);
            }
        }
        pasos++;
    }
    raiz = nullptr;
    root = nullptr;
    root->~Nodo();
    pasos = -1;
}