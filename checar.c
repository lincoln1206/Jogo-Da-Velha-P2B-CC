#include "jogostdio.h"
#include <stdio.h>
#include <stdlib.h> 

void checar()
{//checar quem venceu ou se deu empate

	if((Matriz[0][0]==O && Matriz[0][1]==O && Matriz[0][2]==O)||
       (Matriz[1][0]==O && Matriz[1][1]==O && Matriz[1][2]==O)||
       (Matriz[2][0]==O && Matriz[2][1]==O && Matriz[2][2]==O)||
       (Matriz[0][0]==O && Matriz[1][0]==O && Matriz[2][0]==O)||
       (Matriz[0][1]==O && Matriz[1][1]==O && Matriz[2][1]==O)||
       (Matriz[0][2]==O && Matriz[1][2]==O && Matriz[2][2]==O)||
       (Matriz[0][0]==O && Matriz[1][1]==O && Matriz[2][2]==O)||
       (Matriz[0][2]==O && Matriz[1][1]==O && Matriz[2][0]==O))
    {//VERIFICA SE O PLAYER 2 OU COMPUTADOR GANHOU 
        system("cls");
        tabuleiro();
		if(opcao==1)
		{
			printf("\n\n-->Jogador 2 venceu!\n\n");
			ranking();
		}
		else if(opcao==2)printf("\n\n-->Computador venceu!\n\n");
        l=10;
    }
    if((Matriz[0][0]==X && Matriz[0][1]==X && Matriz[0][2]==X)||
       (Matriz[1][0]==X && Matriz[1][1]==X && Matriz[1][2]==X)||
       (Matriz[2][0]==X && Matriz[2][1]==X && Matriz[2][2]==X)||
       (Matriz[0][0]==X && Matriz[1][0]==X && Matriz[2][0]==X)||
       (Matriz[0][1]==X && Matriz[1][1]==X && Matriz[2][1]==X)||
       (Matriz[0][2]==X && Matriz[1][2]==X && Matriz[2][2]==X)||
       (Matriz[0][0]==X && Matriz[1][1]==X && Matriz[2][2]==X)||
       (Matriz[0][2]==X && Matriz[1][1]==X && Matriz[2][0]==X))
    {//VERIFICA SE O PLAYER 1 GANHOU
        system("cls");
        tabuleiro();
		printf("\n\n-->Jogador 1 venceu!\n\n");
        l=10;
        ranking();
    }

    if(l==9)
    {//VERIFICA SE DEU VELHA
        system("cls");
        tabuleiro();
		printf("\n\n-->PARTIDA EMPATADA!\n\n");
        l=10;
    }
	
}

