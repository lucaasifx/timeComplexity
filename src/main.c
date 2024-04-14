#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "ordenation.h"


int main(){
    int n, i, *vet=NULL, comp, acoes;

    while(scanf("%d", &n) != EOF){

        vet=(int*)realloc(vet, n*sizeof(int));
        if(!vet){
            printf("\n<< ERRO >>\n");
            exit(1);
        }

        for(int i = 0; i < n; i++)
            scanf("%d", &i[vet]);

        comp = acoes = 0;
        //funcao de ordenacao com parametro pra contagem de acoes/comparacoes
        

        printf("\ninput \"%04d.txt\" \n", 
        "|comparacoes: %d\n ",
        "|acoes: %d\n", n, comp, acoes);

    }
}