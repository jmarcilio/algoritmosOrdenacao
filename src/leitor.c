#include <stdlib.h>
#include <stdio.h>
#include "src/leitor.h"
//funcao para ler um arquivo e retornar um vetor com os numeros lidos nesse arquivo
int* leiaArquivo(char nArquivo[], int* numerosLidos, int n){
    printf("Estou aqui 2\n");
    //cria ponteiro para arquivo e abre um arquivo
    FILE *arq;
    arq = fopen(nArquivo, "r");
    //checa se foi possivel abrir o arquivo
    if (arq == NULL) {
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    } else printf("Arquivo aberto\n");
    //armazena no vetor cada linha lida
    for (int i=0;i<n;i++){
        fscanf(arq, "%d", &numerosLidos[i]);
    }

    return numerosLidos;
}