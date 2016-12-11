#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "jogostdio.h"
#include "creditos.c"
#include "configtela.c"
#include "matriz_tabuleiro.c"
#include "checar.c"
#include "jogada.c"
#include "jogador.c"
#include "ranking.c"

int main()
{//main
	configtela();
	do
	{
		menu();
		switch(opcao)
		{
			case 0://SAIR
				printf("\n\nSaindo...");
				break;
			
			case 1://PLAYER VS. PLAYER
				system("cls||clear");
				jogada();
		    	break;
		    
		    case 2://PLAYER VS. COMPUTADOR
		    	system("cls||clear");
		    	jogada();
		    	break;
		    
		    case 3:
		    	system("cls||clear");
				ranking();
		    	break;
		    
			case 4:
		    	system("cls||clear");
		    	creditos();
		    	break;
		    	
			default://MENSAGEM PADRAO 
		    	system("cls||clear");
		    	printf("COMANDO INVALIDO!\n");
		}
	}while(opcao);
    return(0);
}

void menu()
{//menu
	printf("\xCEอออออออออออออออออออออออออออ\xCE\n\xBA\tJOGO DA VELHA       \xBA\n\xBA                           \xBA\n\xCEMENU                       \xBA\n\xCE[1]-JOGAR                  \xBA\n\xCE[2]-JOGAR CONTRA COMPUTADOR\xBA\n\xCE[3]-RANKING                \xBA\n\xCE[4]-CREDITOS               \xBA\n\xCE[0]-SAIR                   \xBA\n\xCEอออออออออออออออออออออออออออ\xCE");
	printf("\nOPCAO: ");
	scanf("%d", &opcao);
}

