#include "../headers/nodo.hpp"

Nodo::~Nodo(){}

Nodo::Nodo(): costo(0), profundidad(0) , padre(nullptr){}
Nodo::Nodo(Estado& edo): costo(0), profundidad(0) {
    estado=&edo;
    padre =  nullptr;
}
Nodo::Nodo(Nodo* padre, Estado& edo): costo(0), profundidad(0){
     estado=&edo;
     this->padre = padre;
}
Nodo::Nodo(int prof,Nodo* padre, Estado& edo): costo(0),profundidad(prof),padre(padre), estado(&edo){}
Nodo::Nodo(int costo, int prof,Nodo* padre, Estado& edo): costo(costo),profundidad(prof),padre(padre), estado(&edo){}
