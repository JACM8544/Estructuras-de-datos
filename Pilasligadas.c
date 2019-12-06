#include <stdio.h>
#include <stdlib.h>

struct Pila{
	int dato;
	struct Pila *siguiente;
};

void IngresarElem(struct Pila **cab, int dato)
{
	struct Pila * aux = NULL;
	aux = (struct Pila *) malloc (sizeof (struct Pila));
	if (aux == NULL){
	return ;
	}
	if (*cab == NULL){
	(*cab) = aux;
	(*cab)-> siguiente = NULL;
	aux->dato = dato;
	}
	else{
	aux->dato = dato;
	aux->siguiente = (*cab);
	(*cab) = aux;
	}
}

void mostrarPila (struct Pila *cab)
{
 int i = 0;
	while (cab != NULL)
	{
		if(cab->siguiente==NULL)
		{
			break;
		}
	i++;
	printf("%d \n", cab->dato);
	cab = cab->siguiente;
	}
 if (cab == NULL)
	{
		printf("La pila esta vacia o no existe\n");
	}
	printf("Existen %d elementos en la pila\n", i);
}

void Pilapop(struct Pila *cab)
	{
		free(cab);
		*(cab) = *(cab)-> siguiente;	
		printf("La nueva cabecera es %d\n",cab-> dato);
	}
int main()
{
	struct Pila * Lista1 = NULL;
	Lista1 =(struct Pila *) malloc (sizeof (struct Pila));
	IngresarElem(&Lista1,1);
	IngresarElem(&Lista1,2);
	IngresarElem(&Lista1,3);
	IngresarElem(&Lista1,4);
	mostrarPila (Lista1);
	Pilapop(Lista1);
	mostrarPila (Lista1);
	return 0;
}
