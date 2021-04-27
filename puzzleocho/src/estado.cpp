#include "../headers/estado.hpp"
Estado::Estado(){}
Estado::Estado(Accion accion):mov(accion){}
Estado::~Estado(){}

bool Estado::operator==(const Estado& tab2 ) const{
    for(int i=0; i<ANCHURA_MAX;i++){
        for(int j=0; j<ALTURA_MAX; j++){
            if(tab[i][j]!=tab2.tab[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool Estado::operator!=(const Estado& tab2 ) const{
    return !(*this==tab2);
}
void Estado::operator=(const Estado& edo) {
    this->mov=edo.mov;
    for(int i=0; i< ANCHURA_MAX; i++){
        for(int j=0; j<ALTURA_MAX; j++){
            tab[i][j]=edo.tab[i][j];
        }
    }
    this->cero[0]=edo.cero[0];
    this->cero[1]=edo.cero[1];
}

