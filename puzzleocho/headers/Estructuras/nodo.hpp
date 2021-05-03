#ifndef NODO_H
#define NODO_H

#include "../Agentes/estado.hpp"

class Nodo
{
public:
    Nodo();
    Nodo(Estado &);
    Nodo(Nodo *, Estado &);
    Nodo(int, Nodo *, Estado &);
    Nodo(int, int, Nodo *, Estado &);
    ~Nodo();

    int profundidad;
    Nodo *padre;
    Estado *estado;
};
#endif //NODO_H