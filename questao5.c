#include <stdio.h>
#include <stdlib.h>

typedef struct tipoNo{
	int dado;
	struct tipoNo *prox;
}tipoNo;

typedef struct{
	tipoNo *top;
}tipoPilha;

void create(tipoPilha *p){
	p->top = NULL;
}

void pushVector(tipoPilha *p, int vet[], int K){
	tipoNo *aux;
	int i;

	for(i=0; i<K; i++){
		aux = (tipoNo *) malloc(sizeof(tipoNo));
		aux->dado = vet[i];
		aux->prox = p->top;
		p->top = aux;
	}
}

void pop(tipoPilha *p){
	tipoNo *aux = p->top;
	p->top = aux->prox;
	free(aux);
}

int main(){
	tipoPilha p;
	int d, N, i, vet[100];
	int op;

	create(&p);
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%d", &vet[i]);
	pushVector(&p, vet, N);
	system("clear");
	while(p.top != NULL){
		printf("Elemento - %d\n", p.top->dado);
		pop(&p);
	}
	return 0;
}

/*void pushVector(tipoPilha *p, int vet[], int K){
	tipoNo *aux;
	int i;

	for(i=0; i<K; i++){
		aux = (tipoNo *) malloc(sizeof(tipoNo));
		aux->dado = vet[i];
		aux->prox = p->top;
		p->top = aux;
	}
}*/