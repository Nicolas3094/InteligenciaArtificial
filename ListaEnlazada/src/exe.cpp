#include "../headers/exe.hpp"
void exePila(EstructuraComun<int>* estructura)
{
    char opt;
    int choice, prior;
    while(1)
    {
        //The menu options are listed below
        cout <<"\n1.PUSH\n";
        cout <<"2.POP\n";
        cout <<"3.DISPLAY\n";
        cout <<"4.EXIT\n";
        cout <<"\nEnter your choice : ";
        cin >> choice;

        if( choice==1){
            out("Digite valor");
            cin>>choice;
            out("Digite prioridad: ");
            cin>>prior;
            estructura->push(choice,prior);
        }
         else if( choice==2){
            int elemento;
            elemento = estructura->pop();
            out("Se ha liberado: "<<elemento);
         }
         else if( choice==3){
            estructura->print(); //display function is called
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