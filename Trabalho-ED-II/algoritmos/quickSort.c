#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\quickSort.h"
#include "src/ordena.h"

Diagnostico particao(int esquerda, int direita, int* i, int* j, int *vetor) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    int pivo = vetor[(esquerda + direita) / 2];
    *i = esquerda;
    *j = direita;
    
    while (*i <= *j) {
        while (vetor[*i] < pivo && *i < direita) {
            (*i)++;
            cont.comparacao++;
        }
        while (vetor[*j] > pivo && *j > esquerda) {
            (*j)--;
            cont.comparacao++;
        }
        if (*i <= *j) {
            int temp = vetor[*i];
            vetor[*i] = vetor[*j];
            vetor[*j] = temp;
            (*i)++;
            (*j)--;
            cont.troca++;
        }
    }
    return cont;

}

Diagnostico ordena(int *vetor, int esquerda, int direita) {
    Diagnostico cont;
    cont.comparacao = 0;
    cont.troca = 0;

    Diagnostico cont2;
    cont2.comparacao = 0;
    cont2.troca = 0;

    if (esquerda < direita) {
        int i = esquerda, j = direita;
        cont2 = particao(esquerda, direita, &i, &j, vetor);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;

        cont2 = ordena(vetor, esquerda, j);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;

        cont2 = ordena(vetor, i, direita);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;
    }
    return cont;
}

Diagnostico quick(int *vetor, int tamanho) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    printf("Quick Sort");
    cont = ordena(vetor, 0, tamanho - 1);
    return cont;
}