#ifndef VECTOR_P
#define VECTOR_P
#include "punto.hpp"
typedef struct Vector
{
    Punto pO, pF, direccion;
    float magnitud;

} Vector;
//const double productoPunto(const Punto &, const Punto &);
//const double magnitud(const Vector &);
//const double direccionGradosEje(Vector &, int);
Vector *crearVectorConPuntos(Punto, Punto);
void mostrarDatosVector(const Vector &);
#endif