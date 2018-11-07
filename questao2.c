#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

typedef struct tipoNo{
	tipoDados d;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *front, *back; 
}tipoFila;

void create(tipoFila *f){
	f->front = NULL;
	f->back = NULL;
}

void push(tipoFila *f, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->d = d;
	aux->prox = NULL;

	if(f->back == NULL)
		f->front = aux;
	else
		f->back->prox = aux;
	f->back = aux;
}

tipoDados pop(tipoFila *f){
	tipoNo *aux = f->front;
	tipoDados ret = aux->d;

	f->front = f->front->prox;
	free(aux);
	return ret;
}

int main(){
	tipoFila p;
	tipoDados d;
	int op;

	create(&p);
	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%s %s %d", d.nome, d.endereco, &d.id);
		push(&p, d);
	}
	system("clear");
	while(p.front != NULL){
		printf("%s\n%s\n%d\n\n", p.front->d.nome, p.front->d.endereco, p.front->d.id);
		pop(&p);
	}
	return 0;
}