#include<stdio.h>
#include<stdlib.h>
struct Lista
{
	int*dato;
	int fin;
	int actual;
};
struct Lista crearlista(int n)
{
	struct Lista lista;
	lista.dato = (int*)malloc((sizeof(int))*(2*n));
	lista.actual = 0;
	lista.fin = (2*n)-1;
	return lista;
}
struct Lista copiarlista(struct Lista *lista)
{
	int i;	
	struct Lista auxlista;	
	auxlista.dato=(int*)malloc(sizeof(int)*((lista->fin)*2));
	auxlista.actual = 0;
	auxlista.fin = lista->fin;
	for(i=0;i<=(lista->fin);i++)
	{
		auxlista.dato[i]=(lista->dato[i]);
	}
	return auxlista;
}
struct Lista agregarlista(struct Lista *lista, int dato)
{	
	lista->dato[lista->actual] = dato;
	lista->actual = lista->actual+1;
	if(lista->actual==lista->fin)
	{
		int i;
		struct Lista auxlista;
		copiarlista(lista);
		*lista = crearlista((lista->fin)+1);
		for(i=0;i<=lista->fin;i++)
		{
			(lista->dato)[i] = auxlista.dato[i];
		}
		
	}
	return *lista;
}
struct Lista eliminarlista(struct Lista *lista)
{
	free(lista->dato);
	lista->fin = 0;
	lista->actual = 0;
	printf("Se elimino la lista\n");
	return *lista;
}
void mostrarlista(struct Lista lista)
{
	int i;
	for(i=0;i<(lista.actual);i++)
	{
		printf("%d\n",lista.dato[i]);
	}
	if(lista.actual!=0)
	{	
	printf("El tamaño de la lista es de %d (de 0 a %d)\n",lista.fin+1,lista.fin);
	printf("y actual esta en %d\n",lista.actual);
	}
	else
	{printf("No existe una lista que mostrar\n");}
}
struct Lista intercalarlistas(struct Lista *lista,struct Lista *lista2)
{
	struct Lista lista3;
	lista3 = crearlista(((lista->fin)+(lista2->fin))*2);
	
}
int main()
{
	struct Lista lista;
	struct Lista lista2;
	int n=2;
	int i;
	lista = crearlista(n);
	lista2 = crearlista(n);
	for(i=0;i<=128;i++)
	{
		agregarlista(&lista, i);
		agregarlista(&lista2, i);
	}
	mostrarlista(lista);
	eliminarlista(&lista);
	mostrarlista(lista);
	mostrarlista(lista2);
	return 0;
}
