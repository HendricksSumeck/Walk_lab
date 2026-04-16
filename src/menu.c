#include "incluir.h"
#ifdef _WIN32
#include <windows.h>
#endif

int menu()
{

    FILE *wk;
    char a;
    char state;

    while(1) {
        system(CLEAR_SCR);
        wk = fopen("img/walklab.txt","r");
        if(wk == NULL) {
            printf("Erro ao abrir img/walklab.txt\n");
            exit(1);
        }
        while(fscanf(wk,"%c",&a) != EOF){
            printf("%c",a);
        }
        fclose(wk);

        state = getch();
        if(state == '1'){return 1;}
        if(state == '2'){return 2;}
        if(state == '3'){return 3;}
        if(state == '4'){return 4;}
        if(state == '5'){return 5;}
        if(state == '6'){return 6;}
        if(state == '7'){return 7;}
        if(state == '8'){return 8;}
    }
    return 0;
}
