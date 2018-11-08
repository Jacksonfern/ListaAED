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
	tipoNo *atual;
}tipoListaCircular;

void create(tipoListaCircular *l){
	l->atual = NULL;
}

void push(tipoListaCircular *l, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->d = d;

	if(l->atual == NULL){
		l->atual = aux;
		aux->prox = aux;
	}
	else{
		aux->prox = l->atual->prox;
		l->atual->prox = aux;
	}
}

int contaElementos(tipoListaCircular l, int K){
	tipoNo *aux = l.atual;
	int res=0;

	if(aux==NULL)
		return 0;
	do{
		if(aux->d.id == K)
			res++;
		aux = aux->prox;
	}while(aux!=l.atual);

	return res;
}

int main(){
	tipoListaCircular l;
	tipoDados d;
	int op, k;

	create(&l);
	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%s %s %d", d.nome, d.endereco, &d.id);
		push(&l, d);
	}
	scanf("%d", &k);
	printf("%d\n", contaElementos(l, k));
	return 0;
}

/*int contaElementos(tipoListaCircular l, int K){
	tipoNo *aux = l.atual;
	int res=0;

	if(aux==NULL)
		return 0;
	do{
		if(aux->d.id == K)
			res++;
		aux = aux->prox;
	}while(aux!=l.atual);

	return res;
}*/