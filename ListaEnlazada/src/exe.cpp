#include "../headers/enlazada.hpp"
#include "../headers/colaPrioridad.hpp"
void exePila()
{
    char opt;
    int choice;
    ColaPrioridad So;
    while(1)
    {
        //The menu options are listed below
        std::cout <<"\n1.PUSH\n";
        std::cout <<"2.POP\n";
        std::cout <<"3.DISPLAY\n";
        std::cout <<"4.EXIT\n";
        std::cout <<"\nEnter your choice : ";
        std::cin >> choice;

        if( choice==1){
            So.push(); //push function is called
        }
         else if( choice==2){
            So.pop(); //pop function is called
         }
         else if( choice==3){
            So.print(); //display function is called
         }
         else if( choice==4){
            break;
         }
 
    } 
}

void executer(DobleEnlazada *cola)
{
    int res, nodos, el;
    while (1)
    {
        out("");
        out("1. Crear Lista");
        out("2. Agregar al principio");
        out("3. Agregar despues");
        out("4. Eliminar.");
        out("5. Mostrar.");
        out("8. Buscar.");
        out("9. Salir.");
        out("");
        std::cin >> res;

        if (res == 1)
        {
            out("Cuantos nodos: ");
            std::cin >> nodos;
            for (int i = 0; i < nodos; i++)
            {
                out("Digite el elemento: ");
                std::cin >> el;
                cola->Create_List(el);
            }
        }
        else if (res == 2)
        {
            int tamano;
            out("Valor:");
            std::cin >> tamano;
            cola->AddAtBeg(tamano);
        }
        else if (res == 3)
        {
            int pos1, pos2;
            out("Despues de:");
            std::cin >> pos1;
            out("Valor:");
            std::cin >> pos2;
            cola->AddAfter(pos1, pos2);
        }
        else if (res == 4)
        {

            cola->Delete();
        }
        else if (res == 5)
        {
            cola->Display();
        }
        else if (res == 8)
        {
            Nodo *q;
            int pos;
            out("Posicion:");
            std::cin >> pos;
            q = cola->Search(pos);
            if (q != NULL)
            {
                out(q->info);
            }
        }
        else if (res == 9)
        {
            break;
        }
        else
        {
            out("Opcion invalida");
        }
    }
    delete cola;
}