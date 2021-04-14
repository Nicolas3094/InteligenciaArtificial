#include "../headers/exe.hpp"

void exePila(){
    Tablero tab;
    Arbol* arb = new Arbol(tab);
    Estado* estadoInicial = tab.EstadoInicial();
    print("Estado Inicial: ");
    tab.Mostrar(*estadoInicial);
    print("Iniciar con busqueda.");
    cin.get();
    
    arb->BFS(*estadoInicial);

    delete arb;
}
