#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\selectionSort.h"
#include "src/ordena.h"

Diagnostico selection(int *vetor, int n) {
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            cont.comparacao++;
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        if (i != menor) {
            cont.troca++;
            int auxiliar = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = auxiliar;
        }
    }
   return cont; 
}
