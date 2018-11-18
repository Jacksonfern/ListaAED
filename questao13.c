#include <stdio.h>

typedef struct {
	char nome[20];
	char endereco[20];
	int id;
}tipoDados;

void quickSortParcial(tipoDados vet[], int inicio, int fim, int K){
	int esq, dir;
	tipoDados pivot, aux;

	if(inicio < fim && K > 0){
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
		if(K >= dir-inicio+1){
			quickSortParcial(vet, inicio, dir, dir-inicio+1);
			quickSortParcial(vet, esq, fim, K-(dir-inicio+1));
		}
		else{
			quickSortParcial(vet, inicio, dir, K);
		}
	}
}

int main(){
	int N, K, i;
	tipoDados vet[100];

	scanf("%d", &N);
	for(i=0; i<N; i++)
		scanf("%d", &vet[i].id);
	scanf("%d", &K);
	quickSortParcial(vet, 0, N-1, K);
	printf("\n");
	for(i=0; i<N; i++)
		printf("%d\n", vet[i].id);
	return 0;
}