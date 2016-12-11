#include "jogostdio.h"
#include <stdio.h>
#include <stdlib.h> 

void jogada()
{//jogada player vs. player ou player vs. computador
	srand(time(NULL));
	inM();
	l=0;
	p=9;
	while(l<=9)
    {
        jogador();
        checar();
        p--;
	}
}
