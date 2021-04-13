#include "../headers/cola.hpp"

Cola::Cola(){
    frente = -1;
    cola = -1;
}
void Cola::push() {
    if(cola == LIMITE-1){
        out("Cola sobresaturada");
        return;
    }
    if(frente==-1){
        frente = 0;
    }
    int el;
    out("Inserte elemento: ");
    std::cin >> el;
    colaArray[++cola]=el;
}

void Cola::pop(){
    if(cola < frente || frente == -1){
        out("Cola debajo del flujo");
        return;
    }
    int el;
    el = colaArray[frente++];
    out("Elemento eliminado: "<< el);
}
void Cola::print(){
    if(frente == -1 || frente > cola){
        out("Cola vacia");
        return;
    }
    int i;
    for(i = frente; i<= cola; i++){
        out("["<<i<<":"<<colaArray[i]<<"]");
    }
}
