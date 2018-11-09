#include <stdio.h>
#include <stdlib.h>

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

int somaValoresLista(tipoLista l){
	int cont=0;
	while(l.prim){
		cont+=l.prim->dado;
		l.prim = l.prim->prox;
	}
	return cont;
}

int main(){
	int op, d;
	tipoLista l;

	l.prim = NULL;
	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%d", &d);
		push(&l, d);
	}
	printf("%d\n", somaValoresLista(l));
	return 0;
}