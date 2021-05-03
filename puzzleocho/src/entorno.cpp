#include "../headers/Agentes/entorno.hpp"

Tablero::~Tablero() {}
Tablero::Tablero() {}

void Tablero::Mostrar(const Estado &estado)
{
    for (int i = 0; i < ANCHURA_MAX; i++)
    {
        cout << "| ";
        for (int j = 0; j < ALTURA_MAX; j++)
        {
            cout << estado.tab[i][j] << " ";
            cout << "| ";
        }
        cout << endl;
    }
    cout << endl;
}

Estado *Tablero::MoverEstado(Accion mov, Estado &estado)
{

    int fila, col;
    Estado *nuevoEstado = new Estado();
    *nuevoEstado = estado;

    fila = estado.cero[0];
    col = estado.cero[1];

    if (mov == ARRIBA && fila > 0)
    {

        nuevoEstado->mov = ARRIBA;
        nuevoEstado->tab[fila - 1][col] = 0;
        nuevoEstado->tab[fila][col] = estado.tab[fila - 1][col];

        nuevoEstado->cero[0] = fila - 1;
        nuevoEstado->cero[1] = col;
    }
    else if (mov == ABAJO && fila < 2)
    {
        nuevoEstado->mov = ABAJO;

        nuevoEstado->tab[fila + 1][col] = 0;
        nuevoEstado->tab[fila][col] = estado.tab[fila + 1][col];

        nuevoEstado->cero[0] = fila + 1;
        nuevoEstado->cero[1] = col;
    }
    else if (mov == IZQUIERDA && col > 0)
    {
        nuevoEstado->mov = IZQUIERDA;

        nuevoEstado->tab[fila][col - 1] = 0;
        nuevoEstado->tab[fila][col] = estado.tab[fila][col - 1];

        nuevoEstado->cero[0] = fila;
        nuevoEstado->cero[1] = col - 1;
    }
    else if (mov == DERECHA && col < 2)
    {
        nuevoEstado->mov = DERECHA;

        nuevoEstado->tab[fila][col + 1] = 0;
        nuevoEstado->tab[fila][col] = estado.tab[fila][col + 1];

        nuevoEstado->cero[0] = fila;
        nuevoEstado->cero[1] = col + 1;
    }
    if (*nuevoEstado == Tablero::EstadoMeta())
    {
        nuevoEstado->mov = MAX;

        nuevoEstado->cero[0] = 0;
        nuevoEstado->cero[1] = 0;
    }
    if (estado == *nuevoEstado)
    {
        nuevoEstado = nullptr;
        delete nuevoEstado;
    }
    return nuevoEstado;
}

const Estado Tablero::EstadoMeta()
{
    Estado init;
    int w = -1;
    for (int i = 0; i < ANCHURA_MAX; i++)
    {
        for (int j = 0; j < ALTURA_MAX; j++)
        {
            init.tab[i][j] = ++w;
        }
    }
    init.cero[0] = 0;
    init.cero[1] = 0;
    init.mov = MAX;
    return init;
}

Estado *Tablero::EstadoInicial()
{
    Estado *init = new Estado;
    vector<int> arr = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    random_device rd;
    mt19937 g(rd());
    shuffle(arr.begin(), arr.end(), g);

    for (int i = 0, k = 0; i < ANCHURA_MAX; i++)
    {
        for (int j = 0; j < ALTURA_MAX; j++, ++k)
        {
            init->tab[i][j] = arr.at(k);
            if (arr.at(k) == 0)
            {
                init->cero[0] = i;
                init->cero[1] = j;
            }
        }
    }
    init->mov = MAX;
    return init;
}

long long int Tablero::HashEstado(Estado &edo)
{
    long long int res = 0;
    for (int i = 0; i < ANCHURA_MAX; i++)
    {
        for (int j = 0; j < ALTURA_MAX; j++)
        {
            res *= 10;
            res += edo.tab[i][j];
        }
    }
    return res;
}
