#include <stdio.h>
#include <string.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

void insertionSort(tipoDados vet[], int inicio, int fim){
	int i, j;
	tipoDados pivot;

	for(i=inicio; i<=fim; i++){
		pivot = vet[i];
		j = i-1;
		while(j>=inicio && strcmp(pivot.nome, vet[j].nome) < 0){
			vet[j+1] = vet[j];
			j--;
		}
		vet[j+1] = pivot;
	}
}

void quickSort(tipoDados vet[], int inicio, int fim){
	int esq, dir;
	tipoDados pivot, aux;

	if(fim - inicio < 9)
		insertionSort(vet, inicio, fim);
	else{
		esq = inicio;
		dir = fim;
		pivot = vet[inicio];
		while(esq < dir){
			while(strcmp(vet[esq].nome, pivot.nome) < 0)
				esq++;
			while(strcmp(vet[dir].nome, pivot.nome) > 0)
				dir--;

			if(esq<=dir){
				aux = vet[esq];
				vet[esq] = vet[dir];
				vet[dir] = aux;
			}
		}
		quickSort(vet, inicio, dir);
		quickSort(vet, dir+1, fim);
	}
}

int main(){
	int N, i;
	tipoDados vet[100];
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%s", vet[i].nome);
	quickSort(vet, 0, N-1);
	for(i=0; i<N; i++)
		printf("%s\n", vet[i].nome);
	return 0;
}