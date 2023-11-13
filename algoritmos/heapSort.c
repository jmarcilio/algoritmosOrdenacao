#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\heapSort.h"
#include "src/ordena.h"

Diagnostico criaHeap(int *vetor, int inicio, int final) {
    Diagnostico cont;
    cont.comparacao = 0;
    cont.troca = 0;

    int auxiliar = vetor[inicio];
    int j = inicio * 2 + 1;

    while (j <= final) {
        if (j < final && vetor[j] < vetor[j + 1]) {
            j++;
            cont.comparacao++;
        }
        if (auxiliar < vetor[j]) {
            vetor[inicio] = vetor[j];
            inicio = j;
            j = 2 * inicio + 1;
            cont.troca++;
        } else {
            j = final + 1;
            cont.comparacao++;
        }
    }
    vetor[inicio] = auxiliar;
    return cont;
}

Diagnostico heap(int *vetor, int tamanho) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    Diagnostico cont2;
    cont2.comparacao=0;
    cont2.troca=0;

    for (int i = (tamanho - 1) / 2; i >= 0; i--) {
        cont.comparacao++;
        cont2 = criaHeap(vetor, i, tamanho - 1);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;
    }

    for (int i = tamanho - 1; i >= 1; i--) {
        int auxiliar = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = auxiliar;
        cont.troca++;
        cont2 = criaHeap(vetor, 0, i - 1);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;
    }

    return cont;
}
