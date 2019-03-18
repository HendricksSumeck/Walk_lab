#include "incluir.h"

int main(){

    srand((unsigned) time(NULL));
    FILE *lab;
    int X;
    X = menu();
    mapear_labirinto(X);
    //system("cls");
}
