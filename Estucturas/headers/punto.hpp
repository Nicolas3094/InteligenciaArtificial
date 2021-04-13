#ifndef PUNTO_P
#define PUNTO_P
#include <iostream>
#include <math.h>
#include <string>
#define print(x) std::cout << x << std::endl;
#define PI 3.14159265358979323846

typedef union Punto
{
    double ei[3];
} Punto;
const double distanciaDosPuntos(const Punto &, const Punto &);

#endif //PUNTO_P