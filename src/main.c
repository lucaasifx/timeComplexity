#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ordenation.h"


int main(){
    int n, *vet=NULL, comp, acessaArray;

    while(scanf("%d", &n) != EOF){

        vet = (int*) malloc(n * sizeof(int));
        if(!vet){
            printf("\n<< ERRO >>\n");
            exit(1);
        }

        for(int i = 0; i < n; i++)
            scanf("%d", &vet[i]);

        comp = acessaArray = 0;
        //funcao de ordenacao com parametro pra contagem de acoes/comparacoes
        //insertionSort(vet, n, &comp, &acessaArray);
        // bubbleSort(vet, n, &comp, &acessaArray);
        //selectionSort(vet, n, &comp, &acessaArray);
        heapSort(vet, n, &comp, &acessaArray);


        printf("\ninput \"%04d.txt\" \n", n);
        printf("|Comparacoes: %d\n", comp);
        printf("|Acesso ao vetor: %d\n", acessaArray);
        free(vet);
    }
}