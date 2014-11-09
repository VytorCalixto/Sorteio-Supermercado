#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger/logger.c"

#define TAM_MAX 256

void preencherVetor(int vetor[]);
int pesqSeq(int vetor[], int valor);
void printVetor(int vetor[]);


int main(){
	puts("Bem vindo ao Supermercado Algorítmico!");

	int vetor[TAM_MAX+1];
	preencherVetor(vetor);
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

void preencherVetor(int vetor[]){
	int i;
	srand(time(NULL));
	for(i=1;i<TAM_MAX+1;i++)
		vetor[i] = (rand() % 512)+1;
}

int pesqSeq(int vetor[], int valor){
	int posicao = TAM_MAX;
	vetor[0] = valor;
	while(vetor[posicao] != valor)
		posicao--;
	return posicao;
}