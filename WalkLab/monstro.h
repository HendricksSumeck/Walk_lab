#ifndef MONSTRO_H_INCLUDED
#define MONSTRO_H_INCLUDED

typedef struct monstro{

    int vida;
    int fraqueza;

} Monstro;

Monstro *new_monstro(int v, int f);

#endif // MONSTRO_H_INCLUDED
