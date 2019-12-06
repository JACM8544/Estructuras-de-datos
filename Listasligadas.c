#include <stdio.h>
#include <stdlib.h>

struct LSE{
 int dato;
 struct LSE *siguiente;
};

void IngresarElem(struct LSE **cab, int dato){
 struct LSE * aux = NULL;
 aux = (struct LSE *) malloc (sizeof (struct LSE));
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

void mostrarLSE (struct LSE *cab){
 while (cab != NULL ){
  printf("%d \n", cab->dato);
  cab = cab->siguiente;
 }
}

int main(){
	struct LSE * Lista1 = NULL;
	Lista1 =(struct LSE *) malloc (sizeof (struct LSE));
	IngresarElem ( &Lista1, 1);
	IngresarElem ( &Lista1, 2);
	IngresarElem ( &Lista1, 3);
	IngresarElem ( &Lista1, 4);
	mostrarLSE (Lista1);
	return 0;
}
