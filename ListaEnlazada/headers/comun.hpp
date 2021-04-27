#ifndef COMUN_H
#define COMUN_H

#include <functional> 
#include <algorithm> 
using namespace std;

template<typename T>
class EstructuraComun{
public:
    virtual void push(T)=0;
    virtual void pop(T&)=0;
    virtual bool vacia()=0;
    virtual void recorrer(const function<void(T)>&)=0;
};

#endif //COMUN_H