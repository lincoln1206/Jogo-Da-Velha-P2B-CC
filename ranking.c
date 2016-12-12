#include "jogostdio.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    char nome[80];
    int pontos;
} ranking_struct;
	
void ranking()
{
	FILE* arq = fopen("ranking.txt", "rb");
	ranking_struct data , add, *ler=NULL;
	int i, qtd_reg=0;
	
	if(opcao==1||opcao==2)
	{
		FILE* salvar = fopen("ranking.txt", "a+b");
		printf("DIGITE SEU NOME: ");
	    scanf("%s", &(data.nome));
	    data.pontos=p;
		fwrite(&data, sizeof(ranking_struct), 1, salvar);
		fclose(salvar);
	
	}
	
	if(arq!=NULL)
	{
		if(opcao==3)
		{
			system("cls");
			
			fseek(arq,sizeof(ranking_struct),SEEK_SET);
			
			while(!feof(arq))
			{
				fread(&add, sizeof(ranking_struct), 1, arq);
				++qtd_reg;
			}
			
			printf("\tRANKING\nอออออออออออออออออออออออออออออ\n");
			
			ler=(ranking_struct*)malloc(sizeof(ranking_struct)*qtd_reg);
			rewind(arq);
	
			for(i=0;i<qtd_reg;i++)
			{
				fread(ler+i, sizeof(ranking_struct) , 1, arq);
				printf("%s - %d pontos\n", ler[i].nome,ler[i].pontos );
		    	
			}
			
			printf("\nDigite qualquer tecla \npara retornar ao menu...");
			getch();
			system("cls");
		}
	}
	
	if(arq==NULL)
	{
		if(opcao==3)
		{
			system("cls");
			printf("NAO EXISTE RANKING AINDA!\n\n");
			printf("Digite qualquer tecla \npara retornar ao menu...");
			getch();
			system("cls");
		}
	}
	
	fclose(arq);
}
