#include "jogostdio.h"
#include <stdio.h>
#include <stdlib.h> 

void jogador()
{//jogadores player vs. player ou player vs. computador
	tabuleiro();
	if(l%2)
	{
		if(opcao==1)
		{
			printf("PLAYER 2\nLINHA: ");
			scanf("%d",&i);
		    printf("COLUNA: ");
		    scanf("%d",&j);
		    i--;
		    j--;
		    system("cls");
		}
		else if(opcao==2)
		{
			srand(time(NULL));
			i=rand()%3;
    		j=rand()%3;
    		system("cls");
		}
	}
    else 
	{
		printf("PLAYER 1\nLINHA: ");
		scanf("%d",&i);
	    printf("COLUNA: ");
	    scanf("%d",&j);
	    i--;
	    j--;
	    system("cls");
	}

    if(Matriz[i][j]==' ')
    {
        if(l%2)Matriz[i][j]=O;
        else Matriz[i][j]=X;
        l++;
    }
    
	else
    {
    	if(opcao==1)
		{
			system("cls");
			printf("Posicao ocupada \nou\ninexistente!");
			printf("\nENTER para continuar...");
			getch();
			system("cls");
			jogador();
		}
		else if(opcao==2)
    	{
    		if(l%2)
    		{
    			srand(time(NULL));
				jogador();
			}
			else
			{
				system("cls");
				printf("Posicao ocupada \nou\ninexistente!");
				printf("\nENTER para continuar...");
				getch();
				system("cls");
				jogador();
			}
			
		}
	}
	
}

