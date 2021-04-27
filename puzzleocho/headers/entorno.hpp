#ifndef ENTORNO_H
#define ENTORNO_H
#include "estado.hpp"

class Tablero{

    
    public:
        static const Estado EstadoMeta();
        Tablero();
        ~Tablero();
        static void Mostrar(const Estado&);
        static Estado* MoverEstado(Accion, Estado&);
        static bool EstadosIguales(const Estado&,const Estado&);
        
        static Estado* EstadoInicial();
        static void posicionCero(int &, int &, Estado&, Estado&);

        static long long int HashEstado(Estado&);
};

#endif //ENTORNO_H