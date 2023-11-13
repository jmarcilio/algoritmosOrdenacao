#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\mergeSort.h"
#include "src/ordena.h"
Diagnostico intercalar(int *vetor, int inicio, int meio, int fim) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    int i = inicio, j = meio + 1 , k = 0;
    int tmp[fim - inicio + 1];

    while (i <= meio || j <= fim) {
        if (i == meio + 1 || (j <= fim && vetor[j] < vetor[i])) {
            tmp[k++] = vetor[j++];
            cont.comparacao++;
        } else {
            tmp[k++] = vetor[i++];
            cont.comparacao++;
        }
    }

    for (int i = inicio; i <= fim; i++) {
        vetor[i] = tmp[i - inicio];
        cont.troca++;
    }
    return cont;
}

Diagnostico merge(int *vetor, int inicio, int fim) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    Diagnostico cont2;
    cont2.comparacao=0;
    cont2.troca =0;


    if (inicio < fim) {
        cont.comparacao++;
        int meio = (inicio + fim) / 2;
        cont2 = merge(vetor, inicio, meio);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;

        cont2 = merge(vetor, meio + 1, fim);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;

        cont2 = intercalar(vetor, inicio, meio, fim);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;
    }
    return cont;
}
