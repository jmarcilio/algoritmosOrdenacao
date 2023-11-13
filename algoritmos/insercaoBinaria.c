#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\insercaoBinaria.h"
#include "src/ordena.h"

Diagnostico insercaoB(int* vetorEntrada, int n){
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    printf("InsercaoDireta\n");
    int auxiliar;
    int esq, dir;
    int meio;
    for (int i=1; i<n; i++){
        auxiliar=vetorEntrada[i];
        esq=0;
        dir=i - 1;
        while (esq<=dir){
            cont.comparacao++;
            meio = (esq+dir)/2;
            if (vetorEntrada[meio]<=auxiliar){
                esq=meio+1;
            }else
            dir=meio-1;
        }
        for (int j=i; j>esq;j--){
            cont.troca++;
            vetorEntrada[j]=vetorEntrada[j-1];
        }
        vetorEntrada[esq]=auxiliar;
    }
    return cont;

}