#include "../headers/estado.hpp"

Tablero::Tablero(){}
Tablero::~Tablero(){}
void Tablero::Mostrar(const Estado& estado){
    cout<<"\n" << " ____________"<<endl;
    for(int i = 0; i<ANCHURA_MAX; i++){
        std::cout<<"| ";
        for(int j = 0; j<ALTURA_MAX; j++){
            std::cout<< estado.tab[i][j]<<" ";
            std::cout<<"| ";
        }
        std::cout<<std::endl;
        std::cout << " ____________"<<std::endl;
    }
}
Estado* Tablero::MoverEstado(Mover mov, Estado* estado){
    int fila,col, post;
    Estado* nuevoEstado;
    nuevoEstado = posicionCero(fila,col, *estado);
    if(mov==UP && fila>0){
        nuevoEstado->mov=UP;
        nuevoEstado->tab[fila-1][col]=0;
        nuevoEstado->tab[fila][col]=estado->tab[fila-1][col];
    }else if(mov==DOWN && fila<2){
        nuevoEstado->mov=DOWN;
        nuevoEstado->tab[fila+1][col]=0;
        nuevoEstado->tab[fila][col]=estado->tab[fila+1][col];
    }else if(mov==LEFT && col>0){
        nuevoEstado->mov=LEFT;
        nuevoEstado->tab[fila][col-1]=0;
        nuevoEstado->tab[fila][col]=estado->tab[fila][col-1];
    }else if(mov==RIGHT && col<2){
        nuevoEstado->mov=RIGHT;
        nuevoEstado->tab[fila][col+1]=0;
        nuevoEstado->tab[fila][col]=estado->tab[fila][col+1];
    }
    if(EstadosIguales(*nuevoEstado, *EstadoMeta())){
        nuevoEstado->mov=MOVE_MAX;
    }
    if(EstadosIguales(*estado, *nuevoEstado)){
        delete nuevoEstado;
        return nullptr;
    }
    return nuevoEstado;    
}
bool Tablero::EstadosIguales(const Estado& ed1,const Estado& ed2){
    for(int i=0; i<3;i++){
        for(int j=0; j<3; j++){
            if(ed1.tab[i][j]!=ed2.tab[i][j]){
                return false;
            }
        }
    }
    return true;
}
Estado* Tablero::EstadoMeta(){
    Estado* init = (Estado*)new(Estado);
    int w=-1;
    for(int i = 0; i<3 ; i++){
        for(int j=0; j<3; j++){
            init->tab[i][j] = ++w;
        }
    }
    init->mov=MOVE_MAX;
    return init;
}
Estado* Tablero::EstadoInicial(){
    Estado* init = (Estado*)new(Estado);

    vector<int> arr = {0,1,2,3,4,5,6,7,8};
    std::random_device rd;
    std::mt19937 g(rd());

    shuffle (arr.begin(), arr.end(), g);

    for(int i=0,k = 0; i < 3;i++){
        for(int j =0 ; j<3; j++, ++k){
            init->tab[i][j]= arr.at(k);
        }
    }
    init->mov=MOVE_MAX;
    actualEstado=init;
    return init;

}
Estado* Tablero::posicionCero(int & x, int & y, Estado& estado){
    Estado* est=(Estado*)new(Estado);
    est->mov=estado.mov;
     for(int i = 0; i<ANCHURA_MAX; i++){
        for(int j = 0; j<ALTURA_MAX; j++){
            est->tab[i][j]=estado.tab[i][j];
            if(estado.tab[i][j]==0){
                x=i;
                y=j;
            }
        }
    }
    return est;
}

