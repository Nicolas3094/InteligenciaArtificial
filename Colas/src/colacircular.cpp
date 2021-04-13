#include "../headers/colacircular.hpp"

ColaCircular::ColaCircular()
{
    frente = -1;
    cola = -1;
}
void ColaCircular::push()
{
    if ((cola + 1 == frente && cola + 1 != LIMITE - 1) || (frente == 0 && cola == LIMITE - 1))
    {
        out("Cola llena");
        return;
    }
    if (frente == -1 && cola == -1)
    {
        frente = 0;
        cola = -1;
    }
    if (frente == -1)
    {
        frente = cola;
    }else{
        cola = cola==LIMITE-1?0:cola+1;
    }

    int el;
    out("Inserta elemento:");
    std::cin >> el;
    colaArray[cola] = el;
}

void ColaCircular::pop()
{
    if (frente == -1)
    {
        out("Cola vacia");
        return;
    }

    int el;
    el = colaArray[frente];
    out("Se ha eliminado: " << el);
    if(frente == cola){
        frente=-1;
    }else{
        frente = frente == LIMITE-1 ? 0: frente+1;
    }
}
void ColaCircular::print()
{
    if (frente == -1)
    {
        out("Cola vacia");
        return;
    }
    if(frente <= cola){
        for (int i = frente; i <= cola; i++)
        {
            std::cout<<"|pos: " << i << "; val: " << colaArray[i];
        }
    }else{
        for(int i=frente; i<=LIMITE-1;i++){
            std::cout<<"|pos: " << i << "; val: " << colaArray[i];
        }
        for(int i = 0; i<=cola; i++){
            std::cout<<"|pos: " << i << "; val: " << colaArray[i];
        }
    }
    std::cout<<"|\n";
    
}