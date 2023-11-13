#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

int aleatorio(int n);
int crescente(int n);
int decrescente(int n);

int main(int argc, char **argv) {
  //verifica se o numero de argumentos para a inicalizacao do programa é valida
  if (argc < 3) {
    printf("São esperados 2 argumentos para a execução desse programa\nchar "
           "tipoDeGeracao\nint n");
    printf("\nEncerrando");
    exit(1);
  }
  //converte string para inteiro
  int n = atoi(argv[2]);
  //realiza verificacao para executar a funcao de acordo com o argumento
    if (!strcmp(argv[1], "-a")){
        aleatorio(n);
        printf ("Aleatorio");
    } else if (!strcmp(argv[1], "-c")){
        crescente(n);
        printf("Crescente");
    } else if (!strcmp(argv[1], "-d")){
        decrescente(n);
        printf("Decrescente");
    }
    
  return 0;
}

//Gera numeros aleatorios
int aleatorio(int n) {
  char nomeArquivo[100];
  sprintf(nomeArquivo, "numerosGerados/EntradaAleatorio-%d.txt", n);
  FILE *arq;
  arq = fopen(nomeArquivo, "w");
  int numeroGerado;
  srand(time(NULL));

  if (arq == NULL) {
    printf("Nao foi possivel criar o arquivo");
    return -1;
  }

  for (int i = 0; i < n; i++) {
    numeroGerado = rand();
    fprintf(arq, "%d", numeroGerado);
    if (i < n - 1)
      fprintf(arq, "\n");
    else {}
  }

  fclose(arq);
  return 0;
}
//gera numeros crescentes
int crescente(int n){
  char nomeArquivo[100];
  sprintf(nomeArquivo, "numerosGerados/EntradaCrescente-%d.txt", n);
  FILE *arq;
  arq = fopen(nomeArquivo, "w");

  if (arq == NULL) {
    printf("Nao foi possivel criar o arquivo");
    return -1;
  }

  for (int i = 1; i <= n; i++){
      fprintf(arq, "%d", i);
      if (i < n)
          fprintf(arq, "\n");
      else {}
  }
  fclose(arq);
  return 0;
}
//gera numeros decrescentes
int decrescente(int n){
  char nomeArquivo[100];
  sprintf(nomeArquivo, "numerosGerados/EntradaDecrescente-%d.txt", n);
  FILE *arq;
  arq = fopen(nomeArquivo, "w");

  if (arq == NULL) {
    printf("Nao foi possivel criar o arquivo");
    return -1;
  }

  for (int i = n; i > 0; i--){
      fprintf(arq, "%d", i);
      if (i > 1)
          fprintf(arq, "\n");
      else {}
  }
  fclose(arq);
  return 0;
}