#include "../headers/Estructuras/nodo.hpp"

Nodo::~Nodo() {}

Nodo::Nodo() : profundidad(0) {
    padre=nullptr;
}
Nodo::Nodo(Estado &edo) : profundidad(0)
{
    estado = &edo;
    padre = nullptr;
}
Nodo::Nodo(Nodo *padre, Estado &edo) : profundidad(0)
{
    estado = &edo;
    this->padre = padre;
}
Nodo::Nodo(int prof, Nodo *padre, Estado &edo) : profundidad(prof) {
    this->padre=padre;
    estado=&edo;
}
