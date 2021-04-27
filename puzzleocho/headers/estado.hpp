#ifndef ESTADO_H
#define ESTADO_H
#include "mainh.hpp"

typedef enum Mover {
    ARRIBA,
    ABAJO,
    IZQUIERDA,
    DERECHA,
    MAX
} Accion;

class Estado{
    public:
        Accion mov;
        int tab[ANCHURA_MAX][ALTURA_MAX];
        int cero[2];
        Estado();
        Estado(Accion);
        ~Estado();

        void operator=(const Estado& ) ;
        bool operator==(const Estado& ) const;
        bool operator!=(const Estado& ) const;
};
#endif //ESTADO_H