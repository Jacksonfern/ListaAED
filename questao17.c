#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

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

/*void inserir(tipoLista	L,	int	*d)	{	
	tipoNo *aux;	

	aux->dado =	d;	
	aux->prox =	L->prim;	
	L->prim	= aux;	
}*/
void inserir(tipoLista	*L,	int	d)	{	
	tipoNo *aux;	

	aux = (tipoNo *) malloc(sizeof(tipoNo));
	aux->dado =	d;	
	aux->prox =	L->prim;	
	L->prim	= aux;	
}

int main(){
	tipoLista l;
	int d;
	int op, pos;
	l.prim = NULL;

	while(scanf("%d", &op)){
		if(op==0)
			break;
		scanf("%d", &d);
		push(&l, d);
	}
	return 0;
}