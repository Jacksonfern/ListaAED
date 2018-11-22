#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	tipoDados dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *atual; 
}tipoListaCircular;

void create(tipoListaCircular *l){
	l->atual = NULL;
}

void push(tipoListaCircular *l, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dado = d;
	if(l->atual == NULL){
		l->atual = aux;
		aux->prox = aux;
	}
	else{
		aux->prox = l->atual->prox;
		l->atual->prox = aux;
	}
}

tipoDados pop(tipoListaCircular *l){
	tipoNo *aux, *atual = l->atual;

	while(aux->prox != l->atual)
		aux = aux->prox;
	if(aux == l->atual){
		l->atual = NULL;
		free(aux);
	}
	else{
		aux->prox = l->atual->prox;
		free(l->atual);
		l->atual = l->atual->prox;
	}
}

void update(tipoListaCircular *l){
	l->atual = l->atual->prox;
}

void list(tipoListaCircular l){
	tipoNo *aux = l.atual;

	if(aux){
		do{
			printf("%s\n", aux->dado.nome);
			aux = aux->prox;
		}while(aux != l.atual);
	}
	while(l.atual){
		printf("%s %s %d\n", l.atual->dado.nome, l.atual->dado.endereco, l.atual->dado.id);
		pop(&l);
	}
}

int main(){
	tipoListaCircular p;
	tipoDados d;
	int op;

	create(&p);
	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%s %s %d", d.nome, d.endereco, &d.id);
		push(&p, d);
	}
	list(p);
	return 0;
}

