#include "../headers/exe.hpp"

void exe()
{
    int r;
    while (1)
    {
        print("1. Un poblema.");
        print("2. Rendimiento para n problemas");
        print("0. Salir");
        cin >> r;
        if (r == 1)
        {
            while (1)
            {
                singular();
                print("Desea continuar: Si: 1 / No: 0");
                cin >> r;
                if (r == 1)
                {
                    continue;
                }
                break;
            }
        }
        else if (r == 2)
        {
            while (1)
            {
                rendimiento();
                print("Desea continuar: Si: 1 / No: 0");
                cin >> r;
                if (r == 1)
                {
                    continue;
                }
                break;
            }
        }
        else
        {
            break;
        }
    }

    cin.get();
}
void singular()
{
    Arbol arb;
    Estado edo;
    edo.mov=MAX;

    int resp;

    print("\n1. Manual. ");
    print("2. Aleatorio.\n");
    cin >> resp;
    if (resp == 1)
    {
        map<int, bool> repetido;

        for (int i = 0; i < ANCHURA_MAX; i++)
        {
            for (int j = 0; j < ALTURA_MAX; j++)
            {
                int value;
                cout << "[" << i << "," << j << "] = ";
                cin >> value;

                if (0 <= value && value < ANCHURA_MAX * ALTURA_MAX )
                {
                    if (!repetido[value])
                    {
                        repetido[value]=true;
                        edo.tab[i][j]=value;
                    }else{
                        print("Valor repetido");
                        j--;
                    }
                }else{
                    print("Fuera del rango [0-"<< ANCHURA_MAX * ALTURA_MAX-1 <<"].");
                    j--;
                }
            }
        }
    }else{
        edo = *Tablero::EstadoInicial();
    }
    print("\nEstado Inicial:\n");
    Tablero::Mostrar(edo);
    print("Iniciando busqueda...\n");
    arb.BFS(edo);
    if (arb.raiz == nullptr)
    {
        print("No se encontro solucion en conjunto.");
        return;
    }
    print("Solucion:");
    arb.MostarCamino(*arb.raiz);
}
void rendimiento()
{
    map<long long int, bool> visitado;
    int intentos = 0, fallos = 0, i;
    print("Numero de intentos: ");
    cin >> intentos;
    for (int j = 0; j < intentos; j++)
    {
        cout<<j<<"->";
        Arbol arb;
        Estado edo = *Tablero::EstadoInicial();
        if (!visitado[Tablero::HashEstado(edo)])
        {
            arb.BFS(*Tablero::EstadoInicial());
            if (arb.raiz == nullptr)
            {
                fallos++;
            }
            visitado[Tablero::HashEstado(edo)] = true;
        }
        else
        {
            j--;
        }
    }
    cout<<"|\n";
    print("Soluciones encontradas: " << intentos - fallos);
    print("Soluciones no encontradas: " << fallos);
    print("Rendimiento: " << (1.0 - ((long double)fallos) / ((long double)intentos)) * 100 << "%");
}