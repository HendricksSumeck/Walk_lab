#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

typedef struct nodo{
    int i, j;
    struct nodo *proximo;
}Nodo;

typedef struct fila{
    Nodo *inicio;
    Nodo *fim;
    int qtd;
}Fila;

//Fila
Fila *NewFila(void);
int enfila(Fila *f, int i, int j);
int desenfila(Fila *f, int *i, int *j);
int pega_inicio(Fila *f, int *i, int *j);
void DelFila(Fila *f);
void percorrerFila(Fila *f);


#endif // FILA_H_INCLUDED
