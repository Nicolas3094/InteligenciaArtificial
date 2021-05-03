#include "../headers/Algoritmo/As.hpp"

As::As() {}

As::~As() {}

void As::Resolver(Nodo **raiz, int &pasos)
{

    map<long long int, bool> visitados;

    ColaPrioridad<Nodo*, As> cola;
    
    
    Estado meta = Tablero::EstadoMeta();

    pasos = 0;

    cola.push(*raiz, CostoTotal(**raiz));

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

                cola.push(nodoV, CostoTotal(*nodoV));
            }
        }
        pasos++;
    }
    raiz = nullptr;

    root = nullptr;

    root->~Nodo();

    pasos = -1;
}

long As::CostoAlcance(Nodo &nd)
{
    return nd.profundidad;
}
long As::CostoObjetivo(Nodo &nd)
{
    return Heuristica(&nd);
}
long As::CostoTotal(Nodo &nd)
{
    return (CostoAlcance(nd) + CostoObjetivo(nd));
}

long As::Heuristica(Nodo *nodoActual)
{

    Estado meta, estadoActual;

    meta = Tablero::EstadoMeta();

    estadoActual = *nodoActual->estado;

    long medida = 0;

    for (int i = 0; i < ALTURA_MAX; i++)
    {

        for (int j = 0; j < ANCHURA_MAX; j++)
        {

            if (estadoActual.tab[i][j] != meta.tab[i][j])
            {

                int columna = estadoActual.tab[i][j] % 3;

                for (int fila = 0; fila < ALTURA_MAX; fila++)
                {

                    if (meta.tab[fila][columna] == estadoActual.tab[i][j])
                    {

                        medida += abs(fila - i) + abs(columna - j);

                        break;
                    }
                }
            }
        }
    }
    return medida;
}