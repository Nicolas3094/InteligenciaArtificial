#include "../headers/Algoritmo/As.hpp"

As::As() {}

As::~As() {}

void As::Resolver(Nodo **raiz, int &pasos)
{
    BusquedaGrafo(
        raiz, 
        pasos,
        new ColaPrioridad<Nodo*>([this](Nodo* nd)->long{return CostoTotal(*nd);})
    );
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
    long medida = 0;

    for (int i = 0, k = 0; i < ALTURA_MAX; i++)
    {

        for (int j = 0; j < ANCHURA_MAX; j++, k++)
        {

            if (nodoActual->estado->tab[i][j] != k )
            {
                int fila = int(nodoActual->estado->tab[i][j] / 3);

                int columna = nodoActual->estado->tab[i][j] % 3;

                medida += abs(fila - i) + abs(columna - j);
            }
        }
    }
    
    return medida;
}