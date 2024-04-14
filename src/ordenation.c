#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef int key;


void testeAlgoritmo(key *array, int length, char *algorithm) {
    printf("%s: {", algorithm);
    //teste do algoritmo
    for(int i = 0; i < length; i++)
        printf(" %d ", array[i]);
    printf("}\n");
    //desaloca o vetor de cópia
}

void insertionSort(key dataB[], int length) {

    // copia o vetor
    key *randArr = (key *) malloc(length * sizeof(key));
    for(int i = 0; i < length; i++)
        randArr[i] = dataB[i];

    int j = 0;
    for(int i = 1; i < length; i++) {
        key aux = randArr[i];
        for(j = i -1; j>= 0 && randArr[j] > aux; j--)
            randArr[j + 1] = randArr[j];
        randArr[j + 1] = aux;
    }
    
    testeAlgoritmo(randArr, length, "Insertion Sort");
    //desaloca o vetor de cópia
    free(randArr);
}

void selectionSort(key dataB[], int length) {

    // copia o vetor
    key *randArr = (key *) malloc(length * sizeof(key));
    for(int i = 0; i < length; i++)
        randArr[i] = dataB[i];


    int min;
    for(int i = 0; i < length; i++) {
        min = i;
        for(int j = i + 1; j < length; j++) {
            if(randArr[j] < randArr[min])
                min = j;
        }
        if(min != i) {
            key aux = randArr[i];
            randArr[i] = randArr[min];
            randArr[min] = aux;
        }
    }

    testeAlgoritmo(randArr, length, "Selection Sort");
    //desaloca o vetor de cópia
    free(randArr);
}


void bubbleSort(key dataB[], int length) {

    // copia o vetor
    key *randArr = (key *) malloc(length * sizeof(key));
    for(int i = 0; i < length; i++)
        randArr[i] = dataB[i];


    bool inorder;
    do {
        inorder = true;
        for(int i = 0; i < length - 1; i++) {
            if(randArr[i] > randArr[i + 1]) {
                key aux = randArr[i];
                randArr[i] = randArr[i + 1];
                randArr[i + 1] = aux;
                inorder = false;
            }
        }
    } while(!inorder);

    testeAlgoritmo(randArr, length, "Bubble Sort");
    //desaloca o vetor de cópia
    free(randArr);
}

void merge(key *randArr, int begin, int mid, int end) {
    key *tempArray;
    bool endh1, endh2; 
    endh1 = endh2 = false;
    int h1, h2, length;
    length = end - begin + 1;
    h1 = begin; 
    h2 = mid + 1;
    tempArray = (key *) malloc(length * sizeof(key));
    if (tempArray) {
        for (int i = 0; i < length; i++) {
            if (!endh1 && !endh2) {
                if (randArr[h1] < randArr[h2])
                    tempArray[i] = randArr[h1++];
                else
                    tempArray[i] = randArr[h2++];

                if (h1 > mid)
                    endh1 = true;
                if (h2 > end)
                    endh2 = true;
            } 
            else {
                if (!endh1)
                    tempArray[i] = randArr[h1++];
                else
                    tempArray[i] = randArr[h2++];
            }
        }
        for (int i = 0, k = begin; i < length; i++, k++)
            randArr[k] = tempArray[i];
        free(tempArray);
    }
}

void recursiveMergeCalls(key *randArr, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        recursiveMergeCalls(randArr, begin, mid);
        recursiveMergeCalls(randArr, mid + 1, end);
        merge(randArr, begin, mid, end);
    }

}
void mergeSort(key dataB[], int length, int begin, int end) {

    // copia o vetor
    key *randArr = (key *) malloc(length * sizeof(key));
    for(int i = 0; i < length; i++)
        randArr[i] = dataB[i];

    recursiveMergeCalls(randArr, begin, end);
    testeAlgoritmo(randArr, length, "Merge Sort");
    //desaloca o vetor de cópia
    free(randArr);
}
