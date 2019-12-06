#include <stdio.h>
#include <stdlib.h>

struct Cola{
	int dato;
	struct Cola *siguiente;
	struct Cola *front;
};

void IngresarElem(struct Cola **fin, int dato)
{
	struct Cola * aux = NULL;
	aux = (struct Cola *) malloc (sizeof (struct Cola));
	if (aux == NULL){
	return ;
	}
	if (*fin == NULL){
	(*fin) = aux;
	aux->dato = dato;
	(*fin)->front = aux ;
	}
	else
	{
	aux->dato = dato;
	aux->siguiente = (*fin);
	(*fin) = aux;
	}
}

void mostrarCola (struct Cola *fin)
{
 int i = 0;
	while (fin->front != fin)
	{
		if(fin->siguiente==fin->front)
		{
			break;
		}
	i++;
	printf("%d \n", fin->dato);
	fin = fin->siguiente;
	}
 if (fin->front == NULL)
	{
		printf("La cola esta vacia o no existe\n");
	}
	printf("Existen %d elementos en la cola\n", i);
}

void Colafree(struct Cola *fin)
	{
		free(fin);
		*(fin) = *(fin)-> siguiente;	
		printf("El nuevo frente es %d\n",fin-> dato);
	}
int main()
{
	struct Cola * Lista1 = NULL;
	Lista1 =(struct Cola *) malloc (sizeof (struct Cola));
	IngresarElem(&Lista1,1);
	IngresarElem(&Lista1,2);
	IngresarElem(&Lista1,3);
	IngresarElem(&Lista1,4);
	mostrarCola (Lista1);
	Colafree(Lista1);
	mostrarCola (Lista1);
	return 0;
}
