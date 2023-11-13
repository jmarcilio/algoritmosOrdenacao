#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\radixSort.h"
#include "src/ordena.h"

Diagnostico countingSort(int *vetor, int n, int exp) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    int output[n];
    int count[10] = {0};

    for (int i = 0; i < n; i++) {
        count[(vetor[i] / exp) % 10]++;
        cont.comparacao++;
    }

    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
        cont.comparacao++;
    
    }

    for (int i = n - 1; i >= 0; i--) {
        output[count[(vetor[i] / exp) % 10] - 1] = vetor[i];
        count[(vetor[i] / exp) % 10]--;
        cont.troca++;
    }

    for (int i = 0; i < n; i++) {
        vetor[i] = output[i];
    }
    return cont;
}

int encontrarMaior(int *vetor, int n) {
    int maior = vetor[0];
    for (int i = 1; i < n; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }
    return maior;
}

Diagnostico radix(int *vetor, int n) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    Diagnostico cont2;
    cont2.comparacao=0;
    cont2.troca =0;

    int maior = encontrarMaior(vetor, n);

    for (int exp = 1; maior / exp > 0; exp *= 10) {
       cont2 = countingSort(vetor, n, exp);
        cont.comparacao += cont2.comparacao;
        cont.troca += cont2.troca;
    }
    return cont;
}

