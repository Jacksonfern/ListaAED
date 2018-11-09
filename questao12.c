#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

void quickSort(tipoDados vet[], int inicio, int fim){
	int esq, dir;
	tipoDados pivot, aux;

	if(fim <= inicio)
		return;
	else{
		esq = inicio;
		dir = fim;
		pivot = vet[inicio];
		while(esq < dir){
			while(vet[esq].id < pivot.id)
				esq++;
			while(vet[dir].id > pivot.id)
				dir--;

			if(esq<=dir){
				aux = vet[esq];
				vet[esq] = vet[dir];
				vet[dir] = aux;
				esq++;
				dir--;
			}
		}
		quickSort(vet, inicio, dir);
		quickSort(vet, esq, fim);
	}
}

int main(){
	int N, i;
	tipoDados vet[100];
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%d", &vet[i].id);
	quickSort(vet, 0, N-1);
	for(i=0; i<N; i++)
		printf("%d\n", vet[i].id);
	return 0;
}