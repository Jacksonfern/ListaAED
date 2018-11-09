#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	tipoDados dados;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *prim; 
}tipoLista;

void push(tipoLista *l, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dados = d;
	aux->prox = l->prim;
	l->prim = aux;
}

int copiaLista(tipoLista *l1, tipoDados vet[]){
	tipoNo *aux;
	int cont = 0;

	while(l1->prim){
		aux = l1->prim;
		vet[cont] = aux->dados;
		cont++;
		l1->prim = l1->prim->prox;
		free(aux);
	}
	return cont;
}

int main(){
	tipoLista l;
	int op, pos, i;
	tipoDados d, vet[100];
	l.prim = NULL;

	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%d", &d.id);
		push(&l, d);
	}
	pos = copiaLista(&l, vet);
	for(i=0; i<pos; i++)
		printf("%d\n", vet[i].id);
	return 0;
}