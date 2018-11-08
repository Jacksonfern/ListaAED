#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	char nome[51];
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *prim; 
}tipoFila;

void push(tipoFila *l, char nome[]){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	strcpy(aux->nome, nome);
	aux->prox = l->prim;
	l->prim = aux;
}

void mostraFilaInversa(tipoFila f){
	if(f.prim == NULL)
		return;
	char *res = f.prim->nome;
	f.prim = f.prim->prox;
	mostraFilaInversa(f);
	printf("%s\n", res);
}

int main(){
	tipoFila l;
	tipoDados d;
	int op, pos;
	char nome[51];
	l.prim = NULL;

	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%s", nome);
		push(&l, nome);
	}
	mostraFilaInversa(l);
	return 0;
}

/*void mostraFilaInversa(tipoFila f){
	if(f.prim == NULL)
		return;
	char *res = f.prim->nome;
	f.prim = f.prim->prox;
	mostraFilaInversa(f);
	printf("%s\n", res);
}*/