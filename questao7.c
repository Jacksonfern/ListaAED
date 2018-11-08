#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	int d;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *prim; 
}tipoLista;

void push(tipoLista *l, int d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->d = d;
	aux->prox = l->prim;
	l->prim = aux;
}

int simetrica(tipoLista l){
	tipoNo *aux = l.prim;
	tipoNo *mid;
	int i=0, cont=0;

	while(aux){
		cont++;
		aux=aux->prox;
	}
	mid = l.prim;
	while(i<cont/2){
		mid=mid->prox;
		i++;
	}
	return mid->d;
}

int main(){
	tipoLista l;
	int d;
	int op, pos;
	l.prim = NULL;

	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%d", &d);
		push(&l, d);
	}
	printf("%d\n", simetrica(l));
	return 0;
}