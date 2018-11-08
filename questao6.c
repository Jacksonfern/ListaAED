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
	tipoNo *prim; 
}tipoLista;

void push(tipoLista *l, tipoDados d){
	tipoNo *aux;

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->d = d;
	aux->prox = l->prim;
	l->prim = aux;
}

void removeN(tipoLista *l, int pos){
	tipoNo *ant;
	tipoNo *atual = l->prim;
	int i=1;

	if(pos<1)
		return;

	ant = atual;
	while(i < pos && atual){
		ant = atual;
		atual = atual->prox;
		i++;
	}
	if(atual){
		ant->prox = atual->prox;
		if(pos==1)
			l->prim = atual->prox;
		free(atual);
	}
}

void pop(tipoLista *l){
	tipoNo *aux = l->prim;
	l->prim = l->prim->prox;
	free(aux);
}

int main(){
	tipoLista l;
	tipoDados d;
	int op, pos;
	l.prim = NULL;

	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%s %s %d", d.nome, d.endereco, &d.id);
		push(&l, d);
	}
	scanf("%d", &pos);
	removeN(&l, pos);
	system("clear");
	while(l.prim != NULL){
		printf("%s\n%s\n%d\n\n", l.prim->d.nome, l.prim->d.endereco, l.prim->d.id);
		pop(&l);
	}
	return 0;
}

/*void removeN(tipoLista *l, int pos){
	tipoNo *ant;
	tipoNo *atual = l->prim;
	int i=1;

	if(pos<1)
		return;
	
	ant = atual;
	while(i < pos && atual){
		ant = atual;
		atual = atual->prox;
		i++;
	}
	if(atual){
		ant->prox = atual->prox;
		if(pos==1)
			l->prim = atual->prox;
		free(atual);
	}
}*/