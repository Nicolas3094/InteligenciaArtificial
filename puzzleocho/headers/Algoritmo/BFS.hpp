#ifndef BFS_H
#define BFS_H
#include "Solucion.hpp"
#include "../Estructuras/cola.hpp"

class BFS : public Solucion {
public:
    BFS();
    ~BFS();
    void Resolver(Nodo**, int&);
};
#endif