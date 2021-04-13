#ifndef nodo_h
#define nodo_h

class nodo{
        
    public:
        int info;
        int prioridad;
        nodo* ptr;
        nodo();
        ~nodo();
};
class Nodo {
       
    public:
        int info;
        Nodo* Rptr;
        Nodo* Lptr;
        Nodo();
        ~Nodo();

};

#endif