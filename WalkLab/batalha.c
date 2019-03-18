#include "incluir.h"

Monstro* cria_monstro(){

    int x;

    x = rand() % 4;

    if(x == 0){
        Monstro *monstro = new_monstro(2, 1);
        return monstro;
    }
    if(x == 1){
        Monstro *monstro = new_monstro(3, 2);
        return monstro;
    }
    if(x == 2){
        Monstro *monstro = new_monstro(4, 3);
        return monstro;
    }
    if(x == 3){
        Monstro *monstro = new_monstro(5, 4);
        return monstro;
    }

}

void batalha(){

    Personagem *pessoa = new_personagem();
    Monstro *monstro = cria_monstro();

    causar_dano(monstro, pessoa);
}
