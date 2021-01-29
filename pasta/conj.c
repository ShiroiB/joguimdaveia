#include <stdio.h>
#include <stdlib.h>
#define max 100


typedef struct
{
	double vetor[max], copy[max];
	int quant, qtd;


}conj;

void limpar()
{
    #ifdef __unix__
        system("clear");
    #elif _WIN32
        system("cls");
    #elif _WIN64
        system("cls");
    #endif
}


int loop(int x)
{
    int denovo;
	while(1){
	    printf("Opcao invalida\n");
	    printf("Digite novamente: ");
		scanf("%d", &denovo);
		
		if((0<denovo) && (denovo<100)) break;	
	}
    return denovo;
}

int pop (const void *x, const void *y)
{
   const double *A = x, *B = y;
   return (*A > *B) - (*A < *B);
}

void mostrar (conj a)
{
	int i,k;
	if(a.qtd==0)printf("vazio");
	else
	{
	printf("(");
		for(i=0;i<a.qtd;i++)
		{
		if(i+1>=a.qtd)
		{
			printf("%0.2lf", a.copy[i]);	
			break;
		}
		else printf("%0.2lf,", a.copy[i]);	
		
		}
			
	printf(")");
	}
			   
	printf("\n");	
}  


void remover(conj *a)
{
	int i,j=0;
	qsort((*a).vetor,(*a).quant, sizeof(double), pop);
	for(i=0;i<(*a).quant-1;i++)
	{
		if((*a).vetor[i]!=(*a).vetor[i+1])
		{
			(*a).copy[j]=(*a).vetor[i];
			j++;
		}	
	}
	(*a).copy[j]=(*a).vetor[(*a).quant-1];
	(*a).qtd=j+1;
	
	
}


void ler(conj *a)
{
	int i;
	printf("Digite a quantidade de numeros para o conjunto:");
	scanf("%d", &(*a).quant);
	if((*a).quant>100 || (*a).quant<0)(*a).quant=loop((*a).quant);
	printf("Os numeros, por favor:\n");
	for(i=0;i<(*a).quant; i++)
		scanf("%lf", &(*a).vetor[i]); 	
	remover(a);
	
	
}
int existe(double x, conj c)
{
   int i;
   	for(i=0;i<c.qtd;i++)
	   {
	   	if(c.copy[i]==x) return -1;
	   }
   		
   	return 1;  
	
}


void uniao(conj a, conj b, conj *c)
{
	int i;
	double j;
	for(i=0;i<a.qtd;i++)
	   (*c).copy[i]=a.copy[i];
	(*c).qtd=a.qtd;
	for(i=0;i<b.qtd;i++)
	{
		j=b.copy[i];
		if(existe(j,*c)!=-1)
		{
			(*c).copy[(*c).qtd]=b.copy[i];
			(*c).qtd++;
		}
		qsort((*c).copy,(*c).qtd, sizeof(double), pop);
		j=0;
	}
	printf("\n");
	printf("uniao AUB: ");
	mostrar(*c);
}
void inter(conj a, conj b, conj *d)
{
	int i;
	double j;
	(*d).qtd=0;
	for(i=0;i<a.qtd;i++)
	{
		j=a.copy[i];
		if(existe(j,b)==-1)
		{
			(*d).copy[(*d).qtd]=a.copy[i];
			(*d).qtd++;
		}
	}
	printf("\n");
	printf("interseccao A B: ");
	mostrar(*d);
	
}

void dif(conj a, conj b, conj *e)
{
	int i;
	double j;
	(*e).qtd=0;
	for(i=0;i<a.qtd;i++)
	{
		j=a.copy[i];
		if(existe(j,b)==1)
		{
			(*e).copy[(*e).qtd]=a.copy[i];
			(*e).qtd++;
		}
	}
	printf("\n");
	printf("diferenca A-B: ");	
	mostrar(*e);
	
}
void t(conj*a,conj *b)
{
	printf("Conjuntos Numericos\n");
    printf("***Conjunto A***\n");
	ler(a);
	printf("***Conjunto B***\n");
	ler(b); 
	limpar();
	
	
}

void ex(conj a, conj b, conj *c,conj *d,conj *e)
{
	
	printf("***OPERACOES DOS CONJUNTO ****\n");
	printf("Conjunto de A:");
	mostrar(a);
	printf("Conjunto de B:");	
	mostrar(b);
	uniao(a,b,c);
	inter(a,b,d);
	dif(a,b,e);
	
}	       
int main ()
{
	conj a,b,c,d,e;
	t(&a,&b);      
	ex(a,b,&c,&d,&e);
	return 0;
}
