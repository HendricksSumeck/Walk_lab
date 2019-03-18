#include "incluir.h"

Personagem *new_personagem(){

    Personagem *p= (Personagem *) malloc(sizeof(Personagem));

    p->mochila = NewFila();
    enfila(p->mochila, 1, 1);
    enfila(p->mochila, 2, 2);
    enfila(p->mochila, 3, 3);
    enfila(p->mochila, 4, 4);

    return p;
}

int causar_dano(Monstro *m, Personagem *p){

    int i;
    Nodo *a;

    for(a = p->mochila->inicio; a != NULL; a = a->proximo){
        if(a->j == m->fraqueza){
            m->vida = m->vida - (a->i + a->j);
            if(m->vida <= 0){
                Sleep(1000);
                printf("\nMorto");
                Sleep(1000);
                return 0;
            }
        }
    }




}
