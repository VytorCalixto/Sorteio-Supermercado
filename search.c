#include "search.h"

int pesqSeq(int vetor[], int valor, int *nComp, int tamVetor){
    int posicao = tamVetor;
    vetor[0] = valor;
    while(vetor[posicao] != valor)
        posicao--;
    return posicao;
}
