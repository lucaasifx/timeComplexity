#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ordenation.h"
#define quant 6
typedef int key;


int main(int argc, char *argv[]) {
    srand(time(NULL));    


    int length;
    // //geração dos valores
    // for(int i = 0; i < 5; i++) {
    //     scanf("%d", &length);
    //     printf("%d\n", length);
    //     length /= 100;
    //     for(int j = 0; j < length; j++) {
    //         for(int t = 0; t < 100; t++) {
    //             key k = rand();
    //             printf("%d ", k);
    //         }
    //         puts("");
    //     }
    //     puts("\n");
    // }


    for(int i = 0; i < quant; i++) {
        scanf("%d", &length);
        key *dataB = (key *) malloc(length * sizeof(key));
        if(!dataB) {
            puts("Allocation error!");
            exit(1);
        }
        printf("Array: {");
        for(int j = 0; j < length; j++) {
            scanf("%d", &dataB[j]);
            printf(" %d ", dataB[j]);
        }
        printf("}\n");
        insertionSort(dataB, length);
        selectionSort(dataB, length);
        bubbleSort(dataB, length);
        mergeSort(dataB, length, 0, length -1);
        free(dataB);
    }
    return 0;
}