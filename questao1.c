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
	tipoNo *top; 
}tipoPilha;

void create(tipoPilha *p){
	p->top = NULL;
}

void push(tipoPilha *p, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->d = d;
	aux->prox = p->top;
	p->top = aux;
}

tipoDados pop(tipoPilha *p){
	tipoNo *aux = p->top;
	tipoDados ret = aux->d;

	p->top = aux->prox;
	free(aux);
	return ret;
}

int main(){
	tipoPilha p;
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
	while(p.top != NULL){
		printf("%s\n%s\n%d\n\n", p.top->d.nome, p.top->d.endereco, p.top->d.id);
		pop(&p);
	}
	return 0;
}