#include "jogostdio.h"
#include <stdio.h>
#include <stdlib.h> 

char Matriz[3][3];
char O='O', X='X';
int i,j,l=NULL,opcao=NULL,p=NULL,qtd_reg=NULL;

void inM()
{//inicializa matriz
	for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            Matriz[i][j]=' ';
}

void tabuleiro()
{//inicializa tabuleiro
	for(i=0;i<3;i++)
        {
            printf("\t     %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]);
            if(i<2)
            {
                printf("\t    ÍÍÍ\xCEÍÍÍ\xCEÍÍÍ\n");
            }
        }
}
