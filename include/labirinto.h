#ifndef LABIRINTO_H_INCLUDED
#define LABIRINTO_H_INCLUDED

#include <stdio.h>

void mapear_labirinto(int numero);
int** aloca_matriz(int linhas, int colunas);
void inundacao(int X, int **lab, int x, int y, int ei,int ej, int fi, int fj);
void caminha (int X, int **lab, int x, int y, int fi, int fj, int i, int j);
void declara_matriz(FILE *lab, int *x, int *y);

//Emprimir labirinto
void print_matriz(int **lab, int linhas, int colunas);
void print_labirinto(int X);
void print_caminho(int **lab, int linhas, int colunas);
void print_inuncacao(int **lab, int linhas, int colunas, int cont);

#endif // LABIRINTO_H_INCLUDED
