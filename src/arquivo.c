#include "incluir.h"

FILE* escolha_labirinto(int X){

    if(X == 1){
        return fopen("labirintos/lb1.txt", "r");
    }
    if(X == 2){
        return fopen("labirintos/lb2.txt", "r");
    }
    if(X == 3){
        return fopen("labirintos/lb3.txt", "r");
    }
    if(X == 4){
        return fopen("labirintos/lb4.txt", "r");
    }
    if(X == 5){
        return fopen("labirintos/lb5.txt", "r");
    }
    if(X == 6){
        return fopen("labirintos/lb6.txt", "r");
    }
    if(X == 7){
        return fopen("labirintos/lb7.txt", "r");
    }
    if(X == 8){
        return fopen("labirintos/lb8.txt", "r");
    }

    return NULL;
}
