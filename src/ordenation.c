#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>


void displayArray(int dataB[], int length) {
    printf("Array: { ");
    for(int i = 0; i < length; i++) {
        if(!(i % 10)  && i)
            puts("");
        i != length -1 ? printf("%d, ", dataB[i]) : printf("%d ", dataB[i]); 
    }
    printf("}\n");
}

void insertionSort(int dataB[], int length, unsigned long int *comp, unsigned long int *acessaArray) {
    int j = 0;
    for(int i = 1; i < length; i++) {
        int aux = dataB[i]; //+1 ac
        for(j = i -1; j >= 0 && dataB[j] > aux; j--) { //+1 comp; +1 ac
            (*comp)++;
            dataB[j + 1] = dataB[j]; //+2 ac
            (*acessaArray) += 3;
        }
        dataB[j + 1] = aux; //+1 ac
        (*acessaArray) += 2;
    }
}

void selectionSort(int dataB[], int length, unsigned long int *comp, unsigned long int *acessaArray) {

    int min;
    for(int i = 0; i < length; i++) {
        min = i;
        for(int j = i + 1; j < length; j++) {

            (*comp)++;
            (*acessaArray) += 2;
            if(dataB[j] < dataB[min]) //+1 comp; +2 acessos
                min = j;
        }
        if(min != i) {
            int aux = dataB[i];
            dataB[i] = dataB[min];
            dataB[min] = aux;
            (*acessaArray) += 4;
        }
    }
}

void bubbleSort(int dataB[], int length, unsigned long int *comp, unsigned long int *acessaArray) {
    bool inorder;
    do {
        inorder = true;
        for(int i = 0; i < length - 1; i++) {
            (*comp)++;
            if(dataB[i] > dataB[i + 1]) { //+1 comp; +2 acessos
                int aux = dataB[i]; //+1 ac
                dataB[i] = dataB[i + 1]; //+2 ac
                dataB[i + 1] = aux; //+1 ac
                (*acessaArray) += 6;
                inorder = false;
            }
            (*acessaArray) += 2;
        }
    } while(!inorder);
}

void quickSort(int dataB[], int length, int begin, int end, unsigned long int *comp, unsigned long int *acessaArray) {
    int pivot = dataB[begin]; //+1 ac
    (*acessaArray)++;
    int left = begin, right = end;
    while(left <= right) {
        while(true) {
            (*comp)++;
            (*acessaArray)++;
            if(dataB[left] < pivot) //+1 comp; +1 ac
                left++;
            else
                break;
        }
        while(true) {
            (*comp)++;
            (*acessaArray)++;
            if(dataB[right] < pivot) //+1 comp; +1 ac
                right--;
            else
                break;
        }
        if(left <= right) {
            int aux = dataB[left]; //+1 ac
            dataB[left] = dataB[right]; //+2 ac
            dataB[right] = aux; //+1 ac
            left++;
            right--;
            (*acessaArray) += 4;
        }
    }
    if(begin < right)
        quickSort(dataB, length, begin, right, comp, acessaArray);
    if(left < end)
        quickSort(dataB, length, left, end, comp, acessaArray);
}

void merge(int dataB[], int begin, int mid, int end, unsigned long int *comp, unsigned long int *acessaArray) {
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
                *(acessaArray) += 4; //quatro interacoes com vetores dentro da condicional


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
                *(acessaArray) += 2; //quatro interacoes com vetores dentro da condicional
            }
        }
        for (int i = 0, k = begin; i < length; i++, k++){
            dataB[k] = tempArray[i];
            *(acessaArray) += 2; //duas interacoes com vetores
        }
        free(tempArray);
    }
}

void recursiveMergeCalls(int dataB[], int begin, int end, unsigned long int *comp, unsigned long int *acessaArray) {
    (*comp)++;
    if (begin < end) {
        int mid = (begin + end) / 2;
        recursiveMergeCalls(dataB, begin, mid, comp, acessaArray);
        recursiveMergeCalls(dataB, mid + 1, end, comp, acessaArray);
        merge(dataB, begin, mid, end, comp, acessaArray);
    }

}

void mergeSort(int dataB[], int begin, int end, unsigned long int *comp, unsigned long int *acessaArray) {
    recursiveMergeCalls(dataB, begin, end, comp, acessaArray);
}


void maxHeapify(int dataB[], const int length, unsigned long int *comp, unsigned long int *acessaArray){
    /*
        dataB: vetor que deverá ser ordenado
        length: tamanho do dataBor
    */
    int root, leaf, aux;
    /*
        root:   indice da raiz
        leaf:   indice da folha
        aux: auxiliar
    */            

    for(leaf = length; leaf; leaf--){
        //calculo para a raiz da folha
            root = (leaf-1)/2;
        //teste entre a raiz e sua folha
            (*comp)++;
            (*acessaArray) += 2;
            if(dataB[root] < dataB[leaf]){ //+1 comp; +2 ac
                aux = dataB[leaf]; //+1 ac
                dataB[leaf] = dataB[root]; // +2 ac
                dataB[root] = aux; // +1 ac

                (*acessaArray) += 4;
            }    
    }
}

void heapSort(int dataB[], int length, unsigned long int *comp, unsigned long int *acessaArray){
    int aux;

    while((--length) > 0){ 
        //max_heapify nao se envolve com algo alem do limite dado
            maxHeapify(dataB, length, comp, acessaArray);
        //trocando o primeiro com o n-ésimo elemento
            aux = dataB[length]; //+1 ac
            dataB[length] = dataB[0]; //+2 ac
            dataB[0] = aux; //+1 ac
            (*acessaArray) += 4; 
    }
}

