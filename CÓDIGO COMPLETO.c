#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>

//VARIมVEIS GLOBAIS
char Matriz[3][3];
char O='O', X='X';
int a,i,j,l=NULL,opcao=NULL,p=NULL,qtd_reg=NULL;

//FUNวีES
void configtela();
void menu();
void tabuleiro();
void inM();
void jogador();
void jogada();
void checar();
void creditos();
void ranking();

typedef struct
{
    char nome[80];
    int pontos;
} ranking_struct;

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
		    
		    case 3://MOSTRA RANKING
		    	system("cls||clear");
				ranking();
		    	break;
		    
			case 4://MOSTRA CRษDITOS
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

void configtela()//fun็ใo que configura o tamanho da tela e do buffer
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

void menu()
{//menu
	printf("\xCEอออออออออออออออออออออออออออ\xCE\n\xBA\tJOGO DA VELHA       \xBA\n\xBA                           \xBA\n\xCEMENU                       \xBA\n\xCE[1]-JOGAR                  \xBA\n\xCE[2]-JOGAR CONTRA COMPUTADOR\xBA\n\xCE[3]-RANKING                \xBA\n\xCE[4]-CREDITOS               \xBA\n\xCE[0]-SAIR                   \xBA\n\xCEอออออออออออออออออออออออออออ\xCE");
	printf("\nOPCAO: ");
	scanf("%d", &opcao);//usuแrio escolhe op็ใo entre 0 e 4
}

void inM()
{//inicializa matriz
	for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            Matriz[i][j]=' ';
}

void tabuleiro()
{//inicializa tabuleiro
	for(i=0;i<3;i++)//mostra tabuleiro
        {
            printf("\t     %c \xBA %c \xBA %c\n",Matriz[i][0],Matriz[i][1],Matriz[i][2]);
            if(i<2)
            {
                printf("\t    อออ\xCEอออ\xCEอออ\n");
            }
        }
}

void jogador()
{//jogadores player vs. player ou player vs. computador
	tabuleiro();
	if(l%2)
	{
		if(opcao==1)//player 2 joga
		{
			printf("PLAYER 2\nLINHA: ");
			scanf("%d",&i);
		    printf("COLUNA: ");
		    scanf("%d",&j);
		    i--;
		    j--;
		    system("cls");
		}
		else if(opcao==2)//computador joga
		{
			srand(time(NULL));
			i=rand()%3;
    		j=rand()%3;
    		system("cls");
		}
	}
    else //player 1 joga
	{
		printf("PLAYER 1\nLINHA: ");
		scanf("%d",&i);
	    printf("COLUNA: ");
	    scanf("%d",&j);
	    i--;
	    j--;
	    system("cls");
	}

    if(Matriz[i][j]==' ')//se a posi็ใo estiver vazia e preenchida com X ou O dependendo do jogador
    {
        if(l%2)Matriz[i][j]=O;
        else Matriz[i][j]=X;
        l++;
    }
    
	else
    {
    	if(opcao==1)//if se a posi็ใo que o jogador 1 escolheu estiver ocupada ou nใo exisitir
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
    		if(l%2)//if se a posi็ใo que o computador escolheu estiver ocupada
    		{
    			srand(time(NULL));
				jogador();
			}
			else//se a posi็ใo que o jogador 2 escolheu estiver ocupada ou nใo exisitir
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

void creditos()
{//creditos
	system("cls");
	printf("\xBA CRIADO PELA EQUIPE OLDSOFT\xBA\n\xBA                           \xBA\n");
	printf("\xCE LINCOLN D'OLIVEIRA        \xBA\n\xCE VINICIUS RICARDO          \xBA\n\xCE JOSE PACHECO              \xBA\n\xCE MARCOS PAULO              \xBA\n\xCE JAILSON FREITAS           \xBA\n\xCE MARCONE BANDEIRA          \xBA\n");
	printf("\xCEอออออออออออออออออออออออออออ\xCE");
	printf("\n\nDigite qualquer tecla \npara retornar ao menu...");
	getch();
	system("cls");
}

void ranking()
{//ranking
	FILE* arq = fopen("ranking.txt", "rb");//abre arquivo no modo leitura binแrio
	ranking_struct data , add, *ler=NULL;
	int i, qtd_reg=0;
	
	if(opcao==1||opcao==2)
	{
		FILE* salvar = fopen("ranking.txt", "a+b");//abre arquivo no modo edi็ใo e leitura binแrio
		printf("DIGITE SEU NOME: ");
	    scanf("%s", &(data.nome));
	    data.pontos=p;
		fwrite(&data, sizeof(ranking_struct), 1, salvar);//salva struct dentro do arquivo
		fclose(salvar);
	
	}
	
	if(arq!=NULL)//if se o arquivo ้ diferente de NULL, ou seja se arquivo existe
	{
		if(opcao==3)
		{
			system("cls");
			
			fseek(arq,sizeof(ranking_struct),SEEK_SET);//vai pro inicio do arquivo
			
			while(!feof(arq))//checa quantas structs tem no arquivo
			{
				fread(&add, sizeof(ranking_struct), 1, arq);
				++qtd_reg;
			}
			
			printf("\tRANKING\nอออออออออออออออออออออออออออออ\n");
			
			ler=(ranking_struct*)malloc(sizeof(ranking_struct)*qtd_reg);//aloca็ใo dinโmica do ranking
			rewind(arq);
	
			for(i=0;i<qtd_reg;i++)//mostra o ranking
			{
				fread(ler+i, sizeof(ranking_struct) , 1, arq);//l๊ as structs dentro do arquivo
				printf("%s - %d pontos\n", ler[i].nome,ler[i].pontos+1 );
		    	
			}
			
			printf("\nDigite qualquer tecla \npara retornar ao menu...");
			getch();
			system("cls");
		}
	}
	
	if(arq==NULL)//if se o arquivo ้ NULL, ou seja se arquivo nใo existe
	{
		if(opcao==3)//mensagem caso o usuแrio escolha a op็ใo 3 e nใo exista ranking
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
