#ifndef COMUN_H
#define COMUN_H

template<typename T>
class EstructuraComun{
public:
    virtual void push(T,long)=0;
    virtual T pop()=0;
    virtual void print()=0;
    virtual bool vacia()=0;
};

#endif //COMUN_H