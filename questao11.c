#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

void mergeSort(tipoDados vet[], int inicio, int fim){
	if(fim <= inicio)
		return;
	int i, j, med, cont;
	tipoDados *res = (tipoDados *) malloc(sizeof(tipoDados) * (fim-inicio+1));
	med = (inicio + fim) / 2;
	mergeSort(vet, inicio, med);
	mergeSort(vet, med+1, fim);

	i = inicio, j = med+1, cont=0;
	while(i <= med && j <= fim){
		if(strcmp(vet[i].nome, vet[j].nome) < 0){
			res[cont] = vet[i];
			i++;
		}
		else{
			res[cont] = vet[j];
			j++;
		}
		cont++;
	}

	while(i <= med){
		res[cont] = vet[i];
		i++;
		cont++;
	}
	while(j <= fim){
		res[cont] = vet[j];
		j++;
		cont++;
	}
	j=0;
	for(i=inicio; i<=fim; i++){
		vet[i] = res[j];
		j++;
	}
	free(res);
}

int main(){
	int N, i;
	tipoDados vet[100];
	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%s", vet[i].nome);
	mergeSort(vet, 0, N-1);
	for(i=0; i<N; i++)
		printf("%s\n", vet[i].nome);
	return 0;
}