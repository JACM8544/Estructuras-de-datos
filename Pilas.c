#include<stdio.h>
#include<stdlib.h>
struct Pila
{
	int*dato;
	int bot;
	int top;
};
struct Pila crearpila(int n)
{
	struct Pila pila;
	pila.dato = (int*)malloc((sizeof(int))*(2*n));
	pila.top = 0;
	pila.bot = (2*n)-1;
	return pila;
}
struct Pila copiarpila(struct Pila *pila)
{
	int i;	
	struct Pila auxpila;	
	auxpila.dato=(int*)malloc(sizeof(int)*((pila->bot)*2));
	auxpila.top = 0;
	auxpila.bot = pila->bot;
	for(i=0;i<=(pila->bot);i++)
	{
		auxpila.dato[i]=(pila->dato[i]);
	}
	return auxpila;
}
struct Pila agregarpila(struct Pila *pila, int dato)
{	
	pila->dato[pila->top] = dato;
	pila->top = pila->top+1;
	if(pila->top==pila->bot)
	{
		int i;
		struct Pila auxpila;
		copiarpila(pila);
		*pila = crearpila((pila->bot)+1);
		for(i=0;i<=pila->bot;i++)
		{
			(pila->dato)[i] = auxpila.dato[i];
		}
		
	}
	return *pila;
}
struct Pila eliminarpila(struct Pila *pila)
{
	free(pila->dato);
	pila->bot = 0;
	pila->top = 0;
	printf("Se elimino la pila\n");
	return *pila;
}
void mostrarpila(struct Pila pila)
{
	int i;
	for(i=0;i<(pila.top);i++)
	{
		printf("%d\n",pila.dato[i]);
	}
	if(pila.top!=0)
	{	
	printf("El tamaño de la pila es de %d (de 0 a %d)\n",pila.bot+1,pila.bot);
	printf("y top esta en %d\n",pila.top);
	}
	else
	{printf("No existe una pila que mostrar\n");}
}
struct Pila intercalarpilas(struct Pila *pila,struct Pila *pila2)
{
	struct Pila pila3;
	pila3 = crearpila(((pila->bot)+(pila2->bot))*2);
	
}
int main()
{
	struct Pila pila;
	struct Pila pila2;
	int n=2;
	int i;
	pila = crearpila(n);
	pila2 = crearpila(n);
	for(i=0;i<=128;i++)
	{
		agregarpila(&pila, i);
		agregarpila(&pila2, i);
	}
	mostrarpila(pila);
	eliminarpila(&pila);
	mostrarpila(pila);
	mostrarpila(pila2);
	return 0;
}
