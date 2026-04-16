#include "incluir.h"
#define monstro 2147483644
#define caminho 2147483645
#define livre 2147483646
#define parede 2147483647

#ifdef _WIN32
#define PRINT_BLOCK() printf("%c", 219)
#define PRINT_PATH() printf("%c", 254)
#else
#define PRINT_BLOCK() printf("█")
#define PRINT_PATH() printf("█")
#endif

#define BLUE "\x1B[94m"
#define RESET "\x1b[0m"
#define RED "\x1b[91m"
#define WHITE "\x1b[37m"

void mapear_labirinto(int numero) {

  FILE *lab1, *lab2, *lab3;
  int **labirinto;
  char f;
  // Auxiliares
  int i = 0, j = 0;
  // Tamanho labirinto
  int x = 0, y = 0;
  // Cordenadas inicio
  int xE, yE;
  // Cordenas fim
  int xF, yF;

  lab1 = escolha_labirinto(numero);
  lab2 = escolha_labirinto(numero);

  declara_matriz(lab1, &x, &y);
  // Tamanho matriz
  labirinto = aloca_matriz(x, y);

  while (fscanf(lab2, "%c", &f) != EOF) {
    if (f == '\n') {
      j = 0;
      i++;
    }
    if (f != '\n') {
      labirinto[i][j] = f;
      if (f == 'E') {
        xE = i;
        yE = j;
      }
      if (f == 'F') {
        xF = i;
        yF = j;
      }
      if (f == '#') {
        labirinto[i][j] = parede;
      } else
        labirinto[i][j] = livre;

      j++;
    }
  }

  for (i = 0; i < x; i++) {
    for (j = 0; j < y; j++) {
      if (i == 0 || j == 0 || i == (x - 1) || j == (y - 1)) {
        labirinto[i][j] = parede;
      }
    }
  }

  system(CLEAR_SCR);
  inundacao(numero, labirinto, x, y, xE, yE, xF, yF);
  system(CLEAR_SCR);
  caminha(numero, labirinto, x, y, xE, yE, xF, yF);
}

void declara_matriz(FILE *lab, int *x, int *y) {
  char f;
  while (fscanf(lab, "%c", &f) != EOF) {
    if (f == '\n') {
      *x += 1;
    }
    if (*x == 0) {
      *y += 1;
    }
  }
}

int **aloca_matriz(int linhas, int colunas) {

  int i;
  int **labirinto;

  labirinto = (int **)malloc(linhas * sizeof(int *));
  for (i = 0; i < linhas; i++) {
    labirinto[i] = (int *)malloc(colunas * sizeof(int));
  }

  return labirinto;
}

void print_matriz(int **lab, int linhas, int colunas) {
  int i, j;
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (lab[i][j] == parede) {

      } else if (lab[i][j] == livre) {
        printf(" ");
      }

      else
        printf(" ");
    }
    printf("\n");
  }
}

void print_labirinto(int X) {
  char f;
  FILE *lab;
  lab = escolha_labirinto(X);
  while (fscanf(lab, "%c", &f) != EOF) {
    if (f == '#')
      PRINT_BLOCK();
    else if (f == 'e') {
      printf(RED);
      PRINT_BLOCK();
      printf(RESET);
    } else if (f == 'f') {
      printf(RED);
      PRINT_BLOCK();
      printf(RESET);
    } else if (f == 'E')
      printf(" ");
    else if (f == 'F')
      printf(" ");
    else
      printf("%c", f);
  }
}

void print_caminho(int **lab, int linhas, int colunas) {
  int i, j;
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (lab[i][j] == caminho) {
#ifdef _WIN32
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                                 (COORD){j, i});
#else
        printf("\033[%d;%dH", i + 1, j + 1);
#endif
        printf(RED);
        PRINT_PATH();
        printf(RESET);
      }
    }
    fflush(stdout);
  }
  Sleep(10);
}

void print_inuncacao(int **lab, int linhas, int colunas, int cont) {
  int i, j;
  for (i = 0; i < linhas; i++) {
    for (j = 0; j < colunas; j++) {
      if (lab[i][j] <= cont) {
#ifdef _WIN32
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),
                                 (COORD){j, i});
#else
        printf("\033[%d;%dH", i + 1, j + 1);
#endif
        printf(BLUE);
        PRINT_PATH();
        printf(RESET);
      }
    }
    fflush(stdout);
  }
  Sleep(10);
}

// Motor de Inundação: Flood Fill Algorithm (Breadth-First Search)
// Propaga um mar numérico partindo de uma origem para todos os corredores,
// utilizando controle com estrutura Fila para avançar 1 nível de cada vez uniformemente.
void inundacao(int X, int **lab, int x, int y, int i, int j, int fi, int fj) {

  Fila *fila = NewFila(); // Inicializa Fila (FIFO)
  int cont = 1;
  print_labirinto(X);
  lab[i][j] = cont++;
  while (i != fi || j != fj) {
    if (lab[i + 1][j] == livre) {
      lab[i + 1][j] = cont;
      enfila(fila, i + 1, j);
    }
    if (lab[i - 1][j] == livre) {
      lab[i - 1][j] = cont;
      enfila(fila, i - 1, j);
    }
    if (lab[i][j + 1] == livre) {
      lab[i][j + 1] = cont;
      enfila(fila, i, j + 1);
    }
    if (lab[i][j - 1] == livre) {
      lab[i][j - 1] = cont;
      enfila(fila, i, j - 1);
    }
    desenfila(fila, &i, &j); // Remove a cabeça processada do fluxo da Fila
    cont++;
    print_inuncacao(lab, x, y, cont);
  }
}

// Resolução de percurso Mínimo: Backtracking Algorithm
// Parte do labirinto afogado (número maior em `fi`,`fj`), caçando os valores
// menores adjacentes até trombar na superfície `E` (origem inicial).
void caminha(int X, int **lab, int x, int y, int fi, int fj, int i, int j) {
  int cont = lab[i][j];
  lab[i][j] = caminho;
  print_labirinto(X);
  while (i != fi || j != fj) {
    cont--;
    if (lab[i + 1][j] == cont)
      i = i + 1;
    else if (lab[i - 1][j] == cont)
      i = i - 1;
    else if (lab[i][j + 1] == cont)
      j = j + 1;
    else if (lab[i][j - 1] == cont)
      j = j - 1;
    lab[i][j] = caminho;
    print_caminho(lab, x, y);
  }
  lab[i][j] = caminho;
  print_caminho(lab, x, y);
}
