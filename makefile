CFLAGS=-c -W -std=c99 -Wall -pedantic

all : ordena gera

gera : compilado\gera.o
	gcc -o gera compilado\gera.o

ordena : compilado\ordena.o compilado\leitor.o compilado\bolha.o compilado\insercaoDireta.o compilado\insercaoBinaria.o compilado\shellSort.o compilado\bucketSort.o compilado\heapSort.o compilado\mergeSort.o compilado\quickSort.o compilado\radixSort.o compilado\selectionSort.o
	gcc -o ordena compilado\ordena.o compilado\leitor.o compilado\bolha.o compilado\insercaoDireta.o compilado\insercaoBinaria.o compilado\shellSort.o compilado\bucketSort.o compilado\heapSort.o compilado\mergeSort.o compilado\quickSort.o compilado\radixSort.o compilado\selectionSort.o

compilado\ordena.o : src\ordena.c src\leitor.h algoritmos\bolha.h algoritmos\insercaoDireta.h algoritmos\insercaoBinaria.h algoritmos\shellSort.h algoritmos\bucketSort.h algoritmos\heapSort.h algoritmos\mergeSort.h algoritmos\quickSort.h algoritmos\radixSort.h algoritmos\selectionSort.h
	gcc -o compilado\ordena.o src\ordena.c $(CFLAGS)

compilado\gera.o : src\gera.c
	gcc -o compilado\gera.o src\gera.c $(CFLAGS)

compilado\leitor.o : src\leitor.c src\leitor.h
	gcc -o compilado\leitor.o src\leitor.c $(CFLAGS)

compilado\bolha.o : algoritmos\bolha.c algoritmos\bolha.h
	gcc -o compilado\bolha.o algoritmos\bolha.c $(CFLAGS)

compilado\insercaoBinaria.o : algoritmos\insercaoBinaria.c algoritmos\insercaoBinaria.h
	gcc -o compilado\insercaoBinaria.o algoritmos\insercaoBinaria.c $(CFLAGS)

compilado\insercaoDireta.o : algoritmos\insercaoDireta.c algoritmos\insercaoDireta.h
	gcc -o compilado\insercaoDireta.o algoritmos\insercaoDireta.c $(CFLAGS)

compilado\shellSort.o : algoritmos\shellSort.c algoritmos\shellSort.h
	gcc -o compilado\shellSort.o algoritmos\shellSort.c $(CFLAGS)

compilado\bucketSort.o : algoritmos\bucketSort.c algoritmos\bucketSort.h
	gcc -o compilado\bucketSort.o algoritmos\bucketSort.c $(CFLAGS)

compilado\heapSort.o : algoritmos\heapSort.c algoritmos\heapSort.h
	gcc -o compilado\heapSort.o algoritmos\heapSort.c $(CFLAGS)

compilado\mergeSort.o : algoritmos\mergeSort.c algoritmos\mergeSort.h
	gcc -o compilado\mergeSort.o algoritmos\mergeSort.c $(CFLAGS)

compilado\quickSort.o : algoritmos\quickSort.c algoritmos\quickSort.h
	gcc -o compilado\quickSort.o algoritmos\quickSort.c $(CFLAGS)

compilado\radixSort.o : algoritmos\radixSort.c algoritmos\radixSort.h
	gcc -o compilado\radixSort.o algoritmos\radixSort.c $(CFLAGS)

compilado\selectionSort.o : algoritmos\selectionSort.c algoritmos\selectionSort.h
	gcc -o compilado\selectionSort.o algoritmos\selectionSort.c $(CFLAGS)


clean :
	rm -r -fo -i *.o *~ ordena