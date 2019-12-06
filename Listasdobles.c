#include<stdlib.h>
#include<stdio.h>

struct Listadoble
{
	int dato;
	struct Listadoble *siguiente;
	struct Listadoble *anterior;
};

void insertarListadoble (struct Listadoble **lista, int n)
{
	struct Listadoble *aux = NULL;
	aux = (struct Listadoble *) malloc (sizeof (struct Listadoble));
	if (*lista==NULL)
	{
		aux->siguiente = (*lista);
		aux->anterior = NULL;
		aux->dato = n;
		(*lista)->anterior = aux;
		(*lista) = aux;
	

	}
	else
	{
		aux->siguiente = (*lista);
		aux->anterior = NULL;
		aux->dato = n;
		(*lista) = aux;		
	
	}
}

void mostrarListadoble (struct Listadoble *lista)
{
	while (lista)
	{
		printf ("|%d|\n", lista->dato);
		lista = lista->siguiente;
	}
}

void mostrarListadoble_back (struct Listadoble *lista)
{
	if (lista->siguiente!=NULL)
	{
		lista = lista->siguiente;
	}
	while (lista!=NULL)
	{
		printf ("|%d|\n", lista->dato);
		lista = lista->anterior;
	}
}
int main()
{
	struct Listadoble *Lista1 = NULL;
	Lista1 = (struct Listadoble *) malloc (sizeof (struct Listadoble));
	insertarListadoble (&Lista1, 10);
	insertarListadoble (&Lista1, 11);
	insertarListadoble (&Lista1, 12);
	mostrarListadoble (Lista1);
	mostrarListadoble_back (Lista1);
return 0;
}
