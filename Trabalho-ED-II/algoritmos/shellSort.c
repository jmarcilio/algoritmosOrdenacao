#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\shellSort.h"
#include "src/ordena.h"
Diagnostico shell(int* vetorEntrada, int n){
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    printf("Shell Sort");
    int auxiliar;
    int h=1;
    int j;
    while (h<n){
        h = 3 * h + 1;
    }
    while (h>0){
        for (int i=h;i<n;i++){
            auxiliar=vetorEntrada[i];
            j=i;
            cont.comparacao++;
            while ((j>=h)&&(auxiliar<vetorEntrada[j-h])){
                vetorEntrada[j]=vetorEntrada[j-h];
                j=j-h;
                cont.troca++;
            }
            vetorEntrada[j]=auxiliar;
        }
        h=h/3;
    }
    return cont;
}