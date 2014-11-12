#include "sort.h"

void mergeSort(int vetor[], int vetAux[], int esq, int dir, int *nComp){
    int i,j,k,meio;
	if(dir > esq){
		meio = (dir+esq)/2;
		mergeSort(vetor, vetAux, esq, meio, nComp);
		mergeSort(vetor, vetAux, meio+1, dir, nComp);
		for(i=meio+1;i>esq;i--)
			vetAux[i-1]=vetor[i-1];
		for(j=meio;j<dir;j++)
			vetAux[dir+meio-j]=vetor[j+1];
		for(k=esq;k<=dir;k++)
	        vetor[k]= (vetAux[i] < vetAux[j]) ? vetAux[i++] : vetAux[j--];
    }
}

void quickSort(int vetor[], int esq, int dir, int tipoParticao, int *nComp){
   //TODO: quickSort 
}

void particao(int vetor[], int esq, int dir, int *posPivo, int *nComp){
    //TODO: particao
}
