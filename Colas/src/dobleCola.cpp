#include "../headers/dobleCola.hpp"

DobleCola::DobleCola()
{
    frente = -1;
    cola = -1;
}

void DobleCola::push()
{
    out(" ");
    if (cola + 1 == frente || (frente == 0 && cola == LIMITE - 1))
    {
        out("Cola llena");
        return;
    }
    char res;
    out("a. Push Front");
    out("b. Push End");
    std::cin >> res;
    if (res == 'a')
    {
        pushLeft();
    }
    else if (res == 'b')
    {
        pushRight();
    }
    out(" ");
}
void DobleCola::pop()
{
    out(" ");
     if (frente == -1)
    {
        out("Cola vacia");
        return;
    }
    char res;
    out("a. Pop Front");
    out("b. Pop End");
    std::cin >> res;
    if (res =='a')
    {
        popLeft();
    }
    else if (res == 'b')
    {
        popRight();
    }
    out(" ");
}
void DobleCola::print()
{
    if (frente == -1)
    {
        out("Cola vacia");
        return;
    }
    if (frente <= cola)
    {
        for (int i = frente; i <= cola; i++)
        {
            std::cout << "|pos: " << i << "; val: " << colaArray[i];
        }
    }
    else
    {
        for (int i = frente; i <= LIMITE - 1; i++)
        {
            std::cout << "|pos: " << i << "; val: " << colaArray[i];
        }
        for (int i = 0; i <= cola; i++)
        {
            std::cout << "|pos: " << i << "; val: " << colaArray[i];
        }
    }
    std::cout << "|\n";
}
void DobleCola::pushLeft()
{
  //  out("Lfrentei: " << frente << " colai: " << cola);

    if (frente == -1 && cola == -1)
    {
        frente = -1;
        cola = 0;
    }
    if (frente == -1)
    {
        frente = cola;
    }
    else
    {
        frente = frente == 0 ? LIMITE - 1 : frente - 1;
    }
    int el;
    out("Inserta elemento:");
    std::cin >> el;
    colaArray[frente] = el;
 //   out("frentef: " << frente << " colaf: " << cola);
}
void DobleCola::pushRight()
{
   // out("Rfrentei: " << frente << " colai: " << cola);

    if (frente == -1 && cola == -1)
    {
        frente = 0;
        cola = -1;
    }
    if (frente == -1)
    {
        frente = cola;
    }
    else
    {
        cola = cola == LIMITE - 1 ? 0 : cola + 1;
    }
    int el;
    out("Inserta elemento:");
    std::cin >> el;
    colaArray[cola] = el;
 //   out("frentf: " << frente << " colaf: " << cola);
}
void DobleCola::popLeft()
{
    int el;
    el = colaArray[frente];
    out("Se ha eliminado: " << el);
    if (frente == cola)
    {
        frente = -1;
    }
    else
    {
        frente = frente == LIMITE - 1 ? 0 : frente + 1;
    }
}
void DobleCola::popRight()
{
    int el;
    el = colaArray[cola];
    out("Se ha eliminado: " << el);
    if (frente == cola)
    {
        frente = -1;
    }
    else
    {
        cola = cola == 0 ? LIMITE-1 : cola-1;
    }
}