#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	int dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *prim; 
}tipoLista;

void push(tipoLista *l, int d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dado = d;
	aux->prox = l->prim;
	l->prim = aux;
}

int simetrica(tipoLista l){
	tipoNo *i, *j;
	i = l.prim;

	while(i){
		j = l.prim->prox;
		while(j){
			if(i->dado == j->dado)
				break;
			j = j->prox;
		}
		if(j==NULL)
	}
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