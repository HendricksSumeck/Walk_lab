#include "incluir.h"


Fila *NewFila(void){
    Fila *f = (Fila *) malloc (sizeof(Fila));
    f->fim = NULL;
    f->inicio = NULL;
    f->qtd = 0;
    return f;
}

int enfila(Fila *f, int i, int j){
    Nodo *novo = (Nodo *) malloc (sizeof(Nodo));
    if(novo == NULL)
        return 0;
    novo->i = i;
    novo->j = j;
    novo->proximo = NULL;
    if(f->inicio == NULL)
        f->inicio = novo;
    else
        f->fim->proximo = novo;
    f->fim = novo;
    f->qtd++;
    return 1;
}

int desenfila(Fila *f, int *i, int *j){
    if(f->inicio == NULL)
        return 0;
    Nodo *tmp = f->inicio;
    *i = tmp->i;
    *j = tmp->j;
    f->inicio = f->inicio->proximo;
    if(f->inicio == NULL)
        f->fim = NULL;
    f->qtd--;
    free(tmp);
    return 1;
}

int pega_inicio(Fila *f, int *i, int *j){
    if(f->inicio == NULL)
        return 0;
    *i = f->inicio->i;
    *j = f->inicio->j;
    return 1;
}

void DelFila(Fila *f){
    int i, j;
    while(desenfila(f, &i, &j) != 0);
    free(f);
}

void percorrerFila(Fila *f){

    Nodo *a;

    for(a = f->inicio; a != NULL; a = a->proximo){
        printf("%d, %d\n", a->i, a->j);
    }

}
