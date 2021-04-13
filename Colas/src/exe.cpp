#include "../headers/exe.hpp"

void executer(COLAI* cola){
    char res;
    while (1)
    {
        out("a. Insertar elemento");
        out("b. Elimina elemento");
        out("c. Imprime cola");
        out("d. Salir.");
        std::cin >> res;

        if (res == 'a')
        {
            cola->push();
        }
        else if (res == 'b')
        {
            cola->pop();
        }
        else if (res == 'c')
        {
            cola->print();
        }
        else if (res == 'd')
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