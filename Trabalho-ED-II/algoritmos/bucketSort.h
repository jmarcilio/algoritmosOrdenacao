#ifndef BUCKET_H
#define BUCKET_H
#define nB 100
#include "src/ordena.h"

typedef struct {
    int topo;
    int balde[100];
} Balde;

    Diagnostico bucket(int* vetorEntrada, int n);

#endif //BUCKET_H