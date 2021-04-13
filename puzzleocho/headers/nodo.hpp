#ifndef NODO_H
#define NODO_H
#include "estado.hpp"
#include "cola.hpp"


typedef struct Nodo{
    int costo;
    int profundidad;
    Nodo* padre;
    Estado* estado;
}Nodo;

class Arbol{
    private:
        Nodo* vertice;
        Tablero* tab;
    public:
        Arbol(Tablero&);
        Nodo* crearNodo(int, int, Nodo*, Estado*);
        std::list<Nodo*> hijosNodo(Nodo*);
        void MostarCamino(Nodo*);
        void BFS(Estado&);
};


#endif //NODO_H