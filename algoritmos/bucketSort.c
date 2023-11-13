#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\bucketSort.h"
#include "algoritmos\bolha.h"
#include "src/ordena.h"


Diagnostico bucket(int* vetorEntrada, int n) {
    Diagnostico cont;
    Diagnostico cont2;

    cont2.comparacao = 0;
    cont2.troca = 0;

    cont.comparacao = 0;
    cont.troca = 0;

    printf("BucketSort");
    Balde baldes[n/10];

    for (int i = 0; i < nB; i++) {
        baldes[i].topo = 0;
    }

    for (int i = 0; i < n; i++) {
        int j = nB - 1;
        while (j >= 0) {
            cont.comparacao++;
            if (vetorEntrada[i] >= j * 10) {
                baldes[j].balde[baldes[j].topo] = vetorEntrada[i];
                baldes[j].topo = baldes[j].topo + 1;
                cont.troca++;
                break;
            }
            j--;
        }
    }

    int i = 0;
    for (int j = 0; j < nB; j++) {
        if (baldes[j].topo > 0) {

            cont2 = bolha(baldes[j].balde, baldes[j].topo);

            for (int k = 0; k < baldes[j].topo; k++) {
                vetorEntrada[i] = baldes[j].balde[k];
                i++;
            }
            cont.comparacao += cont2.comparacao;
            cont.troca += cont2.troca;
        }
    }

    return cont;
}