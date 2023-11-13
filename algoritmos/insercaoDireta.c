#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\insercaoDireta.h"
#include "src/ordena.h"
Diagnostico insercaoD(int* vetorEntrada, int n){
    Diagnostico cont;
    cont.comparacao=0;
    cont.troca =0;

    printf("Insercao Direta\n");
    int auxiliar;
    int j;
    for (int i=1; i<=n-1; i++){
        auxiliar=vetorEntrada[i];
        j=i-1;
        cont.comparacao++;
        while ((j>=0)&&(auxiliar<vetorEntrada[j])){
            cont.troca++;
            vetorEntrada[j+1]=vetorEntrada[j];
            j=j-1;
        }
        if (j!=(i-1)){
            vetorEntrada[j+1]=auxiliar;
        }
    }
    return cont;
}