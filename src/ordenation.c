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
            (*comp)++;
            (*acessaArray) += 2;
            if(dataB[j] < dataB[min])
                min = j;
        }
        if(min != i) {
            int aux = dataB[i];
            dataB[i] = dataB[min];
            dataB[min] = aux;
            (*acessaArray) += 4;
        }
        (*comp)++;
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

void merge(int *dataB, int begin, int mid, int end, int *comp, int *acoes) {
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
                
                *(comp)++; //compraracao
                if (dataB[h1] < dataB[h2])
                    tempArray[i] = dataB[h1++];
                else
                    tempArray[i] = dataB[h2++];
                *(acoes) += 4; //quatro interacoes com vetores dentro da condicional


                if (h1 > mid)
                    endh1 = true;
                if (h2 > end)
                    endh2 = true;
                //Não sei se considero esse trecho, so verifica se um dos subvetores terminou
                //Não compara elementos de vetores, que é o que importa eu acho
            } 
            else {
                
                if (!endh1)
                    tempArray[i] = dataB[h1++];
                else
                    tempArray[i] = dataB[h2++];
                *(acoes) += 4; //quatro interacoes com vetores dentro da condicional
            }
        }
        for (int i = 0, k = begin; i < length; i++, k++){
            dataB[k] = tempArray[i];
            *(acoes) += 2; //duas interacoes com vetores
        }
        free(tempArray);
    }
}

void recursiveMergeCalls(int *dataB, int begin, int end, int *comp, int *acoes) {
    *(comp)++;
    if (begin < end) {
        int mid = (begin + end) / 2;
        recursiveMergeCalls(dataB, begin, mid, comp, acoes);
        recursiveMergeCalls(dataB, mid + 1, end, comp, acoes);
        merge(dataB, begin, mid, end, comp, acoes);
    }

}

void mergeSort(int dataB[], int length, int begin, int end, int *comp, int *acoes) {

    recursiveMergeCalls(dataB, begin, end, comp, acoes);
    testeAlgoritmo(dataB, length, "Merge Sort");
    //desaloca o vetor de cópia
    free(dataB);
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

void quickSort(int dataB[], int length, int begin, int end, int *comp, int *acessaArray) {
    int pivot = dataB[begin];
    int left = begin, right = end;
    while(left <= right) {
        while(dataB[left] < pivot)
            left++;
        while(dataB[right] > pivot)
            right--;
        if(left <= right) {
            int aux = dataB[left];
            dataB[left] = dataB[right];
            dataB[right] = aux;
            left++;
            right--;
        }
    }
    if(begin < right)
        quickSort(dataB, length, begin, right);
    if(left < end)
        quickSort(dataB, length, left, end);
}
