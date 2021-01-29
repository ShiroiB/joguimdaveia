#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void limparTela()
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


typedef struct
 {
 	
   char nome[30];
   char prof[30];
   double nota1;
   double nota2;
   double media;
   int codigo;
   int semestre;
   int ano;
   int cred;
   	
}Tdisciplina;


typedef struct
{
  Tdisciplina v[100];
  int qtd; 
} Tdisciplinas;

typedef struct
{
   Tdisciplina v[100];
   int qtd;
   double cred2;
} This;


void lerString(char var[], int limite)
{
    setbuf(stdin, NULL);
	int tam;
    fgets( var, limite, stdin );
	tam=strlen(var);
    if (var[tam-1] == '\n')
        var[tam-1] = '\0';
    setbuf(stdin, NULL);
}

int achar(Tdisciplinas  l, int codigo)
{
   int i=0;
   int achou =0;
   while (achou==0 && i<l.qtd)
      if (l.v[i].codigo==codigo)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

int achar2 (This  l, int codigo)
{
   int i=0;
   int achou =0;
   while (achou==0 && i<l.qtd)
      if (l.v[i].codigo==codigo)
         achou = 1;
      else
         i++;
   return achou?i:-1;
}

void ler(Tdisciplina *a)	
{
   
   printf("Entre com o codigo: ");
   scanf("%d", &(*a).codigo);
   printf("Entre com o nome da materia:");
   lerString((*a).nome, 30);
   printf("Entre com o nome do prof:");
   lerString((*a).prof, 30);
   printf("Entre com o credito:");
   scanf("%d",&(*a).cred);
   printf("Entre com o semestre:");
   scanf("%d",&(*a).semestre);
   printf("Entre com o ano: ");
   scanf("%d", &(*a).ano);
   printf("Entre com a primeira nota:");
   scanf("%lf", &(*a).nota1);
   printf("Entre com a segunda nota:");
   scanf("%lf", &(*a).nota2); 
   (*a).media = ((*a).nota1+(*a).nota2 )/2;
   printf("finalizado\n");
}


void mostrar (Tdisciplinas a, int codigo)
{
	int i = achar(a, codigo);
    if (i> -1){
    	printf("nome:%s  professor:%s  codigo:%d\n", a.v[i].nome,a.v[i].prof, a.v[i].codigo);
		printf("ano:%d       semestre:%d\n",a.v[i].ano,a.v[i].semestre);
		printf("nota1: %.2lf nota2:%lf\n",a.v[i].nota1,a.v[i].nota2 );
		printf("media:%.2lf\n", a.v[i].media);
	}

}

void inicializar(Tdisciplinas *a)
{
   (*a).qtd=0;
}

void inicializar2(This *a)
{
    (*a).qtd=0;
}

void add(Tdisciplinas *l, Tdisciplina a)
{
   (*l).v[(*l).qtd] = a;
   (*l).qtd++;
}

void inserir(This *l, Tdisciplinas a, int codigo)
{
	int p=achar(a, codigo);
    if (p>-1)
    {
        (*l).v[(*l).qtd]=a.v[p];
        (*l).qtd++;
    }
}
double cren(This *l)
{
    int i;
    double total=0;
    (*l).cred2=0;
    for (i=0;i<(*l).qtd;i++)
    {
       (*l).cred2=((*l).v[i].media*(*l).v[i].cred);
        total+=(*l).v[i].cred;
    }
    (*l).cred2/=total;
}

void remover(This *l,Tdisciplinas * a, int codigo)
{
	int p = achar(*a, codigo);
	int d;
    if ( p > -1 )
    {
        (*a).v[p] = (*a).v[ (*a).qtd-1 ];
        (*a).qtd--;
        printf("Removida com sucesso\n"); 
    }   
    else printf("Nao foi possivel realizar a tarefa\n");
    d = achar2(*l, codigo);
    if ( d > -1 )
    {
        (*l).v[p] = (*l).v[ (*l).qtd-1 ];
        (*l).qtd--;
    }  
}

void alterar(Tdisciplinas *l, Tdisciplina a,int codigo)
{
	
	int p = achar(*l, codigo);
    if ( p != -1 )
        (*l).v[p] =a;	
}
int existe(Tdisciplinas a, int codigo)
{
   return achar(a, codigo)!=-1;
}

void listard(Tdisciplinas a)
{
	int i;
	if(a.qtd!=0) {
		for (i = 0 ; i < a.qtd ; i++ )
		{
		printf("-------disciplina %d-------\n", i+1);
		printf("codigo:%d\n", a.v[i].codigo);
		printf("nome:%s      professor:%s\n", a.v[i].nome, a.v[i].prof);
        printf("ano:%d       semestre:%d\n", a.v[i].semestre, a.v[i].ano);
        printf("nota1:%.2lf  nota2:%.2lf\n", a.v[i].nota1, a.v[i].nota2);
        printf("media: %.2lf\n", a.v[i].media);
        printf("credito: %d\n",a.v[i].cred);
        printf("---------------------------\n");
	    }	
	}
	else printf(".........Vazio........\n");
}


void listarh(This a)
{
	int i;
	if(a.qtd!=0) {
		for (i = 0 ; i < a.qtd ; i++ )
		{
		printf("-------disciplina %d------\n", i+1);
		printf("codigo:%d\n", a.v[i].codigo);
		printf("nome:%s \n", a.v[i].nome);
        printf("ano:%d       semestre:%d\n", a.v[i].semestre, a.v[i].ano);
       // printf("nota1:%.2lf  nota2:%.2lf\n", a.v[i].nota1, a.v[i].nota2);
        printf("media: %.2lf\n", a.v[i].media);
        printf("--------------------------\n");
	    }
	printf("Coeficiente de Rendimento:%.2lf\n",a.cred2);
	printf("--------------------------\n");		
	}
	else printf(".........Vazio........\n");
}


int menu()
{
	int r=0;
	printf("----------------*Historico escolar*------------------\n");
	printf("1-inserir uma disciplina\n");
	printf("2-inserir disciplina no historico\n");
	printf("3-listar  historico\n");
	printf("4-listar  disciplinas\n");
	printf("5-Mostrar disciplina\n");
	printf("6-Alterar disciplina\n");
	printf("7-Remover disciplina\n");
	printf("8- Sair\n");
	printf("digite sua opcao:");
	scanf("%d",&r);
	return r;
}


int main()
{
	Tdisciplina a;
	Tdisciplinas d;
    This l;
    inicializar(&d); 
	inicializar2(&l);
    int k, codi, y=0;
    while (!y)
	{
		switch(menu())
		{
			case 1:
				ler(&a);
				add(&d, a);
				printf("concluida com sucesso\n");
				break;
				
			case 2:
				printf("digite o codigo da materia por favor:");
				scanf("%d", &codi);
				if(existe(d, codi)){
					inserir(&l, d, codi);
				    cren(&l);
			        printf("concluida com sucesso\n");	
				}
				else printf("Nao foi possivel inserir a disciplina\n");
				break;
			case 3:
				listarh(l);
				break;
				
			case 4:
				listard(d);
				break;
				
			case 5:
				printf("digite o codigo da materia por favor:");
				scanf("%d", &codi);
				if(existe(d, codi)){
				mostrar(d,codi);
				printf("concluida com sucesso\n");
			    }
			    else printf("Nao encontrado\n");
				break;
			case 6:
				printf("digite o codigo da materia por favor:");
				scanf("%d", &codi);
				if(existe(d, codi)){
					ler(&a);
			        alterar(&d,a,codi);
				    printf("concluida com sucesso\n");	
				}
				else printf("Nao encontrado\n");	
				break;
			case 7:
				printf("digite o codigo da materia por favor:");
				scanf("%d", &codi);
				cren(&l);
				remover(&l, &d, codi);
				break;
			case 8:
				printf("finalizando\n");
				y=1;
				break;			
			default: 
			    printf("tente novamente \n");
			    break;      
		}
		printf("....................\n");
		pausar();
		limparTela();
		
	}
	return 0;
}
