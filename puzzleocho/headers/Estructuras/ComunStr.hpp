#ifndef COMUNSTR_H
#define COMUNSTR_H

template<typename T>
class ComunStr
{
public:
    virtual void push(T)=0;
    virtual T pop()=0;
    virtual bool vacia()=0;
    virtual void vaciar()=0;
    
};

#endif