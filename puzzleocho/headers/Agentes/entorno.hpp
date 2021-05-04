#ifndef ENTORNO_H
#define ENTORNO_H
#include "estado.hpp"

class Tablero{
    public:
        static const Estado EstadoMeta();
        static void Mostrar(const Estado&);
        static Estado* MoverEstado(Accion, Estado&);
        static Estado* EstadoInicial();
        static long long int HashEstado(Estado&);
};

#endif //ENTORNO_H