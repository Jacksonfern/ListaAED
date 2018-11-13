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
		l->atual->prox = aux;
		aux = l->atual;
	}
}

tipoDados pop(tipoListaCircular *l, char chave[]){
	tipoNo *ant;
	tipoNo *aux = l->atual;

	if(aux){
		do{
			if(strcmp(aux->dado.nome, chave) == 0){
				ant->prox = aux->prox;
				free(aux);
			}
			aux = aux->prox;
		}while(aux != l->atual);
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
	printf("%s\n", aux->dado.nome);
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
	//list(p);
	printf("%s\n", p.atual->dado.nome);
	return 0;
}

