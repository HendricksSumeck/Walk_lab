#ifndef PERSONAGEM_H_INCLUDED
#define PERSONAGEM_H_INCLUDED

typedef struct personagem{

    Fila *mochila;

} Personagem;

Personagem *new_personagem();
int causar_dano(Monstro *m, Personagem *p);

#endif // PERSONAGEM_H_INCLUDED
