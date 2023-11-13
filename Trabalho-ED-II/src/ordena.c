#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <profileapi.h>
#include "algoritmos\bolha.h"
#include "algoritmos\insercaoDireta.h"
#include "algoritmos\insercaoBinaria.h"
#include "algoritmos\shellSort.h"
#include "algoritmos\bucketSort.h"
#include "algoritmos\heapSort.h"
#include "algoritmos\mergeSort.h"
#include "algoritmos\quickSort.h"
#include "algoritmos\radixSort.h"
#include "algoritmos\selectionSort.h"
#include "src/leitor.h"
#include "src/ordena.h"



int main(int argc, char **argv){
//Declaração de variáveis
    int n = atoi(argv[2]);
    int numerosLidos[n];
    char nomeArquivo[100];
    double tempoTotal2;
    LARGE_INTEGER tempoI, tempoF, frequencia;
    Diagnostico cont;
    
/*--Verifica se o programa tem a quantidade de variáveis certas para iniciar--*/
    if (argc<4){
       printf("São esperados 3 argumentos para a execução desse programa\nchar "
           "tipoDeGeracao\nint n");
      printf("\nEncerrando");
      exit(1);
    }

    /*--Cgamada a função que lê um arquivo e armazena os numeros lidos em um vetor--*/
    leiaArquivo(argv[3], numerosLidos, n);


    printf("Ordena\n");
    //define o algoritmo a ser usado
    //função para medir performance
    QueryPerformanceFrequency(&frequencia);
    QueryPerformanceCounter(&tempoI);

    if (!strcmp(argv[1], "bolha")){
      cont = bolha(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "insercaoD")){
      cont = insercaoD(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "insercaoB")){
      cont = insercaoB(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "shell")){
      cont = shell(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "bucket")){
      cont = bucket(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "heap")){
      cont = heap(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "merge")){
      cont = merge(numerosLidos, 0, n);
    }
    else if (!strcmp(argv[1], "quick")){
      cont = quick(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "radix")){
      cont = radix(numerosLidos, n);
    }
    else if (!strcmp(argv[1], "selection")){
      cont = selection(numerosLidos, n);
    }
    else
    exit(1);
    QueryPerformanceCounter(&tempoF);
    tempoTotal2 =  ((double)(tempoF.QuadPart-tempoI.QuadPart)*1000)/frequencia.QuadPart;
    

/*————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*/
  sprintf(nomeArquivo, "numerosOrdenados/saida_%s-%d.txt", argv[1], n);
  printf("Criando Arquivo\n");
  FILE *arq;
  arq = fopen(nomeArquivo, "w");

  if (arq == NULL) {
    printf("Nao foi possivel criar o arquivo");
    return -1;
  }
  fprintf(arq, "Tempo de Execução: \t%5.4f ms\n", tempoTotal2);
  fprintf(arq, "Comparações: \t%d\n"
                "Trocas:\t\t\t%d\n", cont.comparacao, cont.troca);
  for (int i = 0; i < n; i++){
      fprintf(arq, "%d", numerosLidos[i]);
      if (i < n-1)
          fprintf(arq, "\n");
  }
  fclose(arq);
/*——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————*/
    return 0;
}