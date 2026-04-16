#ifndef INCLUIR_H_INCLUDED
#define INCLUIR_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#define CLEAR_SCR "cls"
#else
#include <unistd.h>
#include <termios.h>
#define CLEAR_SCR "clear"
static inline void Sleep(int ms) { usleep(ms * 1000); }
static inline int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif

#include "fila.h"
#include "monstro.h"
#include "personagem.h"
#include "arquivo.h"
#include "labirinto.h"
#include "menu.h"
#include "batalha.h"

#endif // INCLUIR_H_INCLUDED
