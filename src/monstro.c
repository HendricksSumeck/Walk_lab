#include "incluir.h"

Monstro *new_monstro(int v, int f){

    Monstro *monstro = (Monstro *) malloc(sizeof(Monstro));

    monstro->vida = v;
    monstro->fraqueza = f;

    return monstro;
}
