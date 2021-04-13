#ifndef ESTADO_H
#define ESTADO_H
#include "mainh.hpp"


typedef enum Mover {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    MOVE_MAX
} Mover;

typedef struct estado
{
    Mover mov;
    int tab[ANCHURA_MAX][ALTURA_MAX];
}Estado;

class Tablero{
    public:
        Estado* actualEstado;

        Tablero();
        ~Tablero();
        void Mostrar(const Estado&);
        Estado* MoverEstado(Mover, Estado*);
        bool EstadosIguales(const Estado&,const Estado&);
        Estado* EstadoMeta();
        Estado* EstadoInicial();
        Estado* ConstruirEstado();
        Estado* posicionCero(int &, int &, Estado&);

};


#endif //ESTADO_H