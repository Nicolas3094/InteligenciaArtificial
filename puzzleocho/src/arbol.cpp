#include "../headers/arbol.hpp"
Arbol::Arbol():pasos(0)
{
    raiz = nullptr;
    this->meta = Tablero::EstadoMeta();
}
Arbol::~Arbol()
{
    visitados.clear();

    Nodo* tmp;
    while(!cola.vacia()){
        cola.pop(tmp);
    }
    tmp=nullptr;
    tmp->~Nodo();

    raiz=raiz!=nullptr?nullptr:raiz;

    raiz->~Nodo();
}

list<Nodo*> Arbol::hijosNodo(Nodo& nodoActual)
{

    list<Nodo*> hj;
    Estado* Nextestado;

    if (nodoActual.estado->mov != ARRIBA && (Nextestado = Tablero::MoverEstado(ABAJO, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));

    if (nodoActual.estado->mov != ABAJO && (Nextestado = Tablero::MoverEstado(ARRIBA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));

    if (nodoActual.estado->mov != IZQUIERDA && (Nextestado = Tablero::MoverEstado(DERECHA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));

    if (nodoActual.estado->mov != DERECHA && (Nextestado = Tablero::MoverEstado(IZQUIERDA, *nodoActual.estado)) != nullptr)
        hj.push_back(new Nodo(nodoActual.profundidad + 1, &nodoActual, *Nextestado));
        
    Nextestado = nullptr;
    Nextestado->~Estado();

    return hj;
}

void Arbol::BFS(Estado& problema)
{
    if(raiz==nullptr)
        raiz = new Nodo(problema);

    cola.push(raiz);
    pasos++;
    visitados[Tablero::HashEstado(*raiz->estado)] = true;

    while (!cola.vacia())
    {
        cola.pop(raiz);
        if (meta == *raiz->estado)
            return;

        list<Nodo*> hj;
        hj = hijosNodo(*raiz);

        for (auto elment : hj)
        {
            long long int llave = Tablero::HashEstado(*elment->estado);
            if (!this->visitados[llave])
            {
                cola.push(elment);
                visitados[llave] = true;
                pasos++;
            }
        }
    }
    raiz = nullptr;
}
void Arbol::MostarCamino(Nodo& nodo)
{
    if (&nodo == nullptr)
    {
        print("No hay camino en este conjunto.");
        print("Pasos: "<< pasos);
        return;
    }
    Nodo* tmp;
    tmp = &nodo;
    while (tmp != nullptr)
    {
        Tablero::Mostrar(*tmp->estado);
        tmp = tmp->padre;
    }
    tmp = nullptr;
    tmp->~Nodo();
    print("Profundidad: "<< nodo.profundidad);
    print("Pasos: "<< pasos);
    
}
