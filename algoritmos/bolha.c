#include <stdio.h>
#include <stdlib.h>
#include "algoritmos\bolha.h"
#include "src\ordena.h"

Diagnostico bolha(int* vetorEntrada, int n)
{
    Diagnostico contador;
    contador.comparacao=0;
    contador.troca =0;
    printf("Bolha\n");
    int auxiliar;
    for (int i=n-1; i>0; i--){
        
        for (int j=0; j<i;j++){
            contador.comparacao++;
           if(vetorEntrada[j]>vetorEntrada[j+1]){
                auxiliar=vetorEntrada[j];
                vetorEntrada[j]=vetorEntrada[j+1];
                vetorEntrada[j+1]=auxiliar;
                contador.troca++;
           }
        }
    }
    printf("\n-------------- Ordenado com sucesso --------------\n");
    return contador;
}