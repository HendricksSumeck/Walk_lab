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

//Labirinto
void mapear_labirinto();
int** aloca_matriz(int linhas, int colunas);
void inundacao(int X, int **lab, int x, int y, int ei,int ej, int fi, int fj);
void caminha (int X, int **lab, int x, int y, int fi, int fj, int i, int j);
void declara_matriz(FILE *lab, int *x, int *y);

//Emprimir labirinto
void print_matriz(int **lab, int linhas, int colunas);
void print_labirinto(int X);
void print_caminho(int **lab, int linhas, int colunas);
void print_inuncacao(int **lab, int linhas, int colunas, int cont);
#endif // FILA_H_INCLUDED
