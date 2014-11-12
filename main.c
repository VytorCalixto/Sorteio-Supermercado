#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger/logger.h"
#include "search.h"
#include "sort.h"

#define TAM_MAX 256

void preencherVetor(int vetor[], int tam);
void printVetor(int vetor[]);

int main(){
	puts("Bem vindo ao Supermercado Algorítmico!");

	int vetor[TAM_MAX+1], vetAux[TAM_MAX+1];
	preencherVetor(vetor, TAM_MAX+1);
    int compMerge = 0;
	mergeSort(vetor,vetAux,1,TAM_MAX, &compMerge);
	printVetor(vetor);
	
	int num;
	printf("Escolha um número entre 1 e 512:\n");
	scanf("%d",&num);

    int compSeq = 0;
	if(pesqSeq(vetor, num, &compSeq, TAM_MAX))
		printf("Parabéns! Você ganhou o sorteio!\n");
	else
		printf("Infelizmente seu número não foi encontrado.\n");

	return 0;
}

void printVetor(int vetor[]){
	int i;
	printf("[");
	for(i=1;i<TAM_MAX+1;i++){
		printf("%d, ", vetor[i]);
	}
	printf("]\n");
}

void preencherVetor(int vetor[], int tam){
	int i;
	srand(time(NULL));
	for(i=1;i<tam;i++)
		vetor[i] = (rand() % 512)+1;
}
