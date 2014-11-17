#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "logger/logger.h"
#include "search.h"
#include "sort.h"

#define TAM_MAX 256

void preencherVetor(int vetor[], int tam);
void printVetor(int vetor[]);
int pesquisar(int vetor[], int num, int *compSeq, int *compBin);
void ordenar(int vetor[], int *compQuick, int *compQuickMed, int *compMerge);

int main(){
	srand(time(NULL));
	puts("Bem vindo ao Supermercado Algorítmico!");
	int opcao;
	do{
		puts("\nO que você gostaria de fazer:");
		puts("1. Participar do sorteio");
		puts("2. Calcular média de comparações dos algoritmos");
		puts("0. Sair");
		scanf("%d",&opcao);
        printf("\n");

        if(opcao == 1)
        	sorteio();
        else if(opcao == 2)
        	calcularMedia();
        else if(opcao != 0)
        	puts("Opção inválida");
	}while(opcao != 0);

	return 0;
}

void calcularMedia(){
	int vetor[TAM_MAX+1];
	int i,x,num;
	printf("Entre com um número X de vezes que os algoritmos devem ser executados:\n");
	scanf("%d",&x);

	int somaQuick=0;
	int somaQuickMed=0;
	int somaMerge=0;
	int somaSeq=0;
	int somaBin=0;

	for(i=0;i<x;i++){
		preencherVetor(vetor, TAM_MAX+1);
		ordenar(vetor,&somaQuick,&somaQuickMed,&somaMerge);
		num = (rand() % 512)+1;
		pesquisar(vetor,num,&somaSeq,&somaBin);
	}
	printf("Média de comparações do QuickSort utilizando o 1º elemento como pivô: %d\n", somaQuick/x);
	printf("Média de comparações do QuickSort utilizando a mediana como pivô: %d\n", somaQuickMed/x);
	printf("Média de comparações do MergeSort: %d\n", somaMerge/x);
	printf("Média de comparações da pesquisa sequencial: %d\n", somaSeq/x);
	printf("Média de comparações da pesquisa binária: %d\n", somaBin/x);
}

void sorteio(){
	int vetor[TAM_MAX+1], num;
	preencherVetor(vetor, TAM_MAX+1);
	//TODO:Imprimir vetor(quando?)
	printVetor(vetor);
	printf("Escolha um número entre 1 e 512:\n");
	scanf("%d",&num);

	int compQuick=0;
	int compQuickMed=0;
	int compMerge=0;
	ordenar(vetor,&compQuick,&compQuickMed,&compMerge);
	printf("Número comparações do QuickSort utilizando o 1º elemento como pivô: %d\n", compQuick);
	printf("Número comparações do QuickSort utilizando a mediana como pivô: %d\n", compQuickMed);
	printf("Número comparações do MergeSort: %d\n", compMerge);
    printVetor(vetor);

    int compSeq = 0;
    int compBin = 0;
	if(pesquisar(vetor, num, &compSeq, &compBin))
		printf("Parabéns! Você ganhou o sorteio!\n");
	else
		printf("Infelizmente seu número não foi encontrado.\n");

	printf("Número comparações da pesquisa sequencial: %d\n", compSeq);
	printf("Número comparações da pesquisa binária: %d\n", compBin);
}

int pesquisar(int vetor[], int num, int *compSeq, int *compBin){
	return pesqSeq(vetor, num, TAM_MAX, compSeq) & pesqBin(vetor, num,1, TAM_MAX, compBin);
}

void ordenar(int vetor[], int *compQuick, int *compQuickMed, int *compMerge){
	int vetAux[TAM_MAX+1];
	//FIXME: Contagem está errada?
	mergeSort(vetor,vetAux,1,TAM_MAX, compMerge);
    
	//TODO: Vetor não deveria estar "desordenado"?
	quickSort(vetor, 1, TAM_MAX, 0, compQuick);
    quickSort(vetor, 1, TAM_MAX, 1, compQuickMed);
}

void printVetor(int vetor[]){
	int i;
	printf("[");
	for(i=1;i<TAM_MAX;i++){
		printf("%d, ", vetor[i]);
	}
	printf("%d ]\n", vetor[i]);
}

void preencherVetor(int vetor[], int tam){
	int i;
	for(i=1;i<tam;i++)
		vetor[i] = (rand() % 512)+1;
}
