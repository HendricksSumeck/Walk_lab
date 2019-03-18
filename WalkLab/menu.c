#include "incluir.h"
#include <conio.h>
#include <windows.h>

int menu()
{

    FILE *wk;
    char a;
    char state;

    system("cls");
    wk = fopen("img\\walklab.txt","r");
    while(fscanf(wk,"%c",&a) != EOF){
        printf("%c",a);
    }
    state = getch();
    if(state == '1'){return 1;}
    if(state == '2'){return 2;}
    if(state == '3'){return 3;}
    if(state == '4'){return 4;}
    system("cls");

}
