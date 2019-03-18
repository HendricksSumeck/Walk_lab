#include "incluir.h"

FILE* escolha_labirinto(int X){

    FILE *lab;
    lab = (FILE*) malloc(sizeof(FILE));

    if(X == 1){
        lab = fopen("labirintos\\lb1.txt", "r");
    }
    if(X == 2){
        lab = fopen("labirintos\\lb2.txt", "r");
    }
    if(X == 3){
        lab = fopen("labirintos\\lb3.txt", "r");
    }
    if(X == 4){
        lab = fopen("labirintos\\lb4.txt", "r");
    }

    return lab;

}
