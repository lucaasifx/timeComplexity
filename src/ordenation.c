#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void insertionSort(int dataB[], int length, int *comp, int *acessaArray) {
    int j = 0;
    for(int i = 1; i < length; i++) {
        int aux = dataB[i];
        for(j = i -1; j >= 0 && dataB[j] > aux; j--) {
            (*comp)++;
            dataB[j + 1] = dataB[j];
            (*acessaArray) += 3;
        }
        dataB[j + 1] = aux;
        (*acessaArray) += 2;
    }
}

void selectionSort(int dataB[], int length, int *comp, int *acessaArray) {

    int min;
    for(int i = 0; i < length; i++) {
        min = i;
        for(int j = i + 1; j < length; j++) {
            if(dataB[j] < dataB[min])
                min = j;
        }
        if(min != i) {
            int aux = dataB[i];
            dataB[i] = dataB[min];
            dataB[min] = aux;
        }
    }
}


void bubbleSort(int dataB[], int length, int *comp, int *acessaArray) {
    bool inorder;
    do {
        inorder = true;
        for(int i = 0; i < length - 1; i++) {
            (*comp)++;
            if(dataB[i] > dataB[i + 1]) {
                int aux = dataB[i];
                dataB[i] = dataB[i + 1];
                dataB[i + 1] = aux;
                (*acessaArray) += 4;
                inorder = false;
            }
            (*acessaArray) += 2;
        }
    } while(!inorder);
}

void merge(int *dataB, int begin, int mid, int end) {
    int *tempArray;
    bool endh1, endh2; 
    endh1 = endh2 = false;
    int h1, h2, length;
    length = end - begin + 1;
    h1 = begin; 
    h2 = mid + 1;
    tempArray = (int *) malloc(length * sizeof(int));
    if (tempArray) {
        for (int i = 0; i < length; i++) {
            if (!endh1 && !endh2) {
                if (dataB[h1] < dataB[h2])
                    tempArray[i] = dataB[h1++];
                else
                    tempArray[i] = dataB[h2++];

                if (h1 > mid)
                    endh1 = true;
                if (h2 > end)
                    endh2 = true;
            } 
            else {
                if (!endh1)
                    tempArray[i] = dataB[h1++];
                else
                    tempArray[i] = dataB[h2++];
            }
        }
        for (int i = 0, k = begin; i < length; i++, k++)
            dataB[k] = tempArray[i];
        free(tempArray);
    }
}

void recursiveMergeCalls(int *dataB, int begin, int end) {
    if (begin < end) {
        int mid = (begin + end) / 2;
        recursiveMergeCalls(dataB, begin, mid);
        recursiveMergeCalls(dataB, mid + 1, end);
        merge(dataB, begin, mid, end);
    }
}

void mergeSort(int dataB[], int length, int begin, int end) {

    recursiveMergeCalls(dataB, begin, end);
}

void maxHeapify(int *vet, const int sizeVet, int *comp, int *acessaArray){
    /*
        vet: vetor que deverá ser ordenado
        sizeVet: tamanho do vetor
    */
    int root, leaf, aux;
    /*
        root:   indice da raiz
        leaf:   indice da folha
        aux: auxiliar
    */
    for(leaf = sizeVet; leaf; leaf--){
        (*comp)++;

        root = (leaf-1)/2; (*acessaArray)++;
        //teste entre a raiz e sua folha
        if(vet[root] < vet[leaf]){
            (*comp)++;

            aux = vet[leaf];
            vet[leaf] = vet[root];
            vet[root] = aux;

            (*acessaArray)+=3;
        }    
    }
}

void heapSort(int *vet, int sizeVet, int *comp, int *acessaArray){
    int aux;

    for(sizeVet--; sizeVet; sizeVet--){ 
            (*comp)++;       
        //max_heapify nao se envolve com algo alem do limite dado
            maxHeapify(vet, sizeVet, comp, acessaArray);
        //trocando o primeiro com o sizeVetimo elemento
            aux = vet[sizeVet];
            vet[sizeVet] = vet[0];
            vet[0] = aux;

            (*acessaArray)+=3;
    }

    // *comp += sizeVet-1;
}