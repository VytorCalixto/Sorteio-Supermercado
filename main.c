#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger/logger.h"

#define TAM_MAX 256

void preencherVetor(int vetor[], int tam);
int pesqSeq(int vetor[], int valor);
void printVetor(int vetor[]);
void mergeSort(int vetor[], int vetAux[], int esq, int dir);

int main(){
	puts("Bem vindo ao Supermercado Algorítmico!");

	int vetor[TAM_MAX+1], vetAux[TAM_MAX+1];
	preencherVetor(vetor, TAM_MAX+1);
	mergeSort(vetor,vetAux,1,TAM_MAX);
	printVetor(vetor);
	
	int num;
	printf("Escolha um número entre 1 e 512:\n");
	scanf("%d",&num);

	if(pesqSeq(vetor, num))
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

int pesqSeq(int vetor[], int valor){
	int posicao = TAM_MAX;
	vetor[0] = valor;
	while(vetor[posicao] != valor)
		posicao--;
	return posicao;
}

void mergeSort(int vetor[], int vetAux[], int esq, int dir){
	int i,j,k,meio;
	if(dir > esq){
		meio = (dir+esq)/2;
		mergeSort(vetor, vetAux, esq, meio);
		mergeSort(vetor, vetAux, meio+1, dir);
		for(i=meio+1;i>esq;i--)
			vetAux[i-1]=vetor[i-1];
		for(j=meio;j<dir;j++)
			vetAux[dir+meio-j]=vetor[j+1];
		for(k=esq;k<=dir;k++)
			vetor[k]=(vetAux[i]<vetAux[j]) ? vetAux[i++]:vetAux[j--];
	}
}

