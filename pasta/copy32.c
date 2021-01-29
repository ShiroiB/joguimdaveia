#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void limpar()
{
   #ifdef _WIN32
   system("cls");
   #else
   system("clear");
   #endif
}

void pausar()
{
   #ifdef _WIN32
    system("pause");
   #else
    //system("read -n1 -r -p \"Press any key to continue...\" key");
    printf("Press any key to continue...\n");
    getchar();
   #endif    
}


void comecar(char a[][3] )
{
	int i,j;
	for(i=0;i<3;i++)	
	  for(j=0;j<3;j++)
	  {
	  	a[i][j]=' ';
	  }
	    
	
}

void mostrar(char a[][3])
{
	printf("          coluna 1   coluna 2   coluna 3\n");
	printf("linha 1:    %c     |  %c        |%c\n",a[0][0],a[0][1],a[0][2]);
	printf("          ---------------------------\n");
	printf("linha 2:    %c     |  %c        |%c\n",a[1][0],a[1][1],a[1][2]);
	printf("          ---------------------------\n");
	printf("linha 3:    %c     |  %c        |%c\n",a[2][0],a[2][1],a[2][2]);
	printf("\n");
	
}


void lernome(char var[], int tam)
{
    setbuf(stdin, NULL);
	int t;
    fgets( var, tam, stdin );
	t=strlen(var);
    if (var[t-1] == '\n')
        var[t-1] = '\0';
    setbuf(stdin, NULL);
}
int comp(char a[][3])
{
	if(a[0][0]=='X' && a[0][1]=='X' && a[0][2]=='X')return 1;
	if(a[1][0]=='X' && a[1][1]=='X' && a[1][2]=='X')return 1;
	if(a[2][0]=='X' && a[2][1]=='X' && a[2][2]=='X')return 1;
	if(a[0][0]=='X' && a[1][0]=='X' && a[2][0]=='X')return 1;
	if(a[0][1]=='X' && a[1][1]=='X' && a[2][1]=='X')return 1;
	if(a[0][2]=='X' && a[1][2]=='X' && a[2][2]=='X')return 1;
	if(a[0][0]=='X' && a[1][1]=='X' && a[2][2]=='X')return 1;
	if(a[0][2]=='X' && a[1][1]=='X' && a[2][0]=='X')return 1;
	
    if(a[0][0]=='O' && a[0][1]=='O' && a[0][2]=='O')return 1;
	if(a[1][0]=='O' && a[1][1]=='O' && a[1][2]=='O')return 1;
	if(a[2][0]=='O' && a[2][1]=='O' && a[2][2]=='O')return 1;
	if(a[0][0]=='O' && a[1][0]=='O' && a[2][0]=='O')return 1;
	if(a[0][1]=='O' && a[1][1]=='O' && a[2][1]=='O')return 1;
	if(a[0][2]=='O' && a[1][2]=='O' && a[2][2]=='O')return 1;
	if(a[0][0]=='O' && a[1][1]=='O' && a[2][2]=='O')return 1;
	if(a[0][2]=='O' && a[1][1]=='O' && a[2][0]=='O')return 1;  	
	
}
void nome(char no[20],char no2[20])
{
	printf("*******JOGO DA VELHA*******\n");
	printf("digite o nome do player 1:\n");
	lernome(no,20);
	printf("digite o nome do player 2:\n");
	lernome(no2,20);
	
}

void jogo2(char no[20],char no2[20], char b[][3],int x)
{
	int i,j,contador=0,p=0;
	while(p<10)
	{
		printf("partida %d\n", x);
	    mostrar(b);
	    if(contador%2==0)printf("player  %s eh a sua vez!!!\n", no);	
		else printf("player %s eh a sua vez!!!\n", no2);	
		printf("digite a posicao\n");
		printf("linha:");
		scanf("%d", &i);
		printf("coluna:");
		scanf("%d", &j);
		if(b[i-1][j-1] == ' ')
		{
			
			if(x==1){
			if(contador%2==0)b[i-1][j-1]='X';
		    else b[i-1][j-1]='O';
			}
			if(x==2){
			if(contador%2==0)b[i-1][j-1]='O';
		    else b[i-1][j-1]='X';
			}
			contador++;
			p++;
		    limpar();
		    if(comp(b)==1)
		    {
		    if(p%2==1)
                {
                printf("player %s ganhou!!!!!\n",no);
			   	mostrar(b);
			   	pausar();
			    break;
                }
			if(p%2==0)
				{
			   	printf("player %s ganhou!!!!!\n",no2);
			   	mostrar(b);
			   	pausar();
			    break;
			    }
	        } 
		}
		if(contador==9)
	    {
		printf("***deu velha***\n");
		break;
		}
		else limpar();
		
	}	
}

int loop(int x)
{
    int denovo;
	while(1){
	    printf("Opcao invalida\n");
	    printf("Digite novamente: ");
		scanf("%d", &denovo);
		
		if((0<denovo) && (denovo<=100)) break;	
	}
    return denovo;
}
void exibir(char no[20],char no2[20])
{
	
	printf("Players o que desejam ser:\n");
	printf("1-player %s -> X\n", no);
	printf("  player %s -> O\n", no2);
	printf("-------------------\n");
	printf("2-player %s -> O\n", no);
	printf("  player %s -> X\n", no2);
	printf("0-sair\n");
}

void escolha (char no[20],char no2[20],char b[][3])
{
	int c,d,cont=1;
	nome(no,no2);
	printf("desejam fazer quantas partidas?\n");	
	scanf("%d", &d);
	if(d<0)d=loop(d);
	limpar();
	while(1)
		{
		printf("partida:%d\n", cont);
		exibir(no,no2);
		printf("opcao:");
		scanf("%d", &c)	;
		if(c==2 || c==1)
		{
			limpar();
			comecar(b);
			jogo2(no,no2,b,c);
			cont++;
		}	
		if(c==0)
		{
		 printf("finalizado o jogo\n");	
		 break;
		}
		if(cont-1==d)
		{
		  printf("finalizado o jogo\n");
		  break;	
		}
	    else limpar();
	    
		
	}

}

int main()
{
	char b[3][3],no[20],no2[20];
	escolha(no,no2,b);
	return 0;
}

