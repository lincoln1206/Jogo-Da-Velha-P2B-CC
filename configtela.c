#include "jogostdio.h"
#include <stdlib.h>
#include <stdlib.h> 
#include<windows.h>

void configtela()//função q configura o tamanho da tela e do buffer
{
COORD outbuff;
outbuff.X = 150; // tem que ser 1 maior que o tamanho X
outbuff.Y = 55; // tem que ser 1 maior que o tamanho Y
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleScreenBufferSize(hConsole, outbuff);
Sleep(130);
SMALL_RECT windowSize = {0, 0, 28, 18}; 
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
} 
