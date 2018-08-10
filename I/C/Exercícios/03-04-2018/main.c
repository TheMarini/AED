#include <stdlib.h> //standard library
#include <stdio.h>  //standard input
#include <locale.h> //language library
#include <string.h> //string library
#include <time.h>   //time library

void pular();

void main()
{
    setlocale(LC_ALL, "Portuguese"); // declarar lingua

    int i, j, min, max;

    printf("Digite o valor mínimo: ");
    scanf("%d", &min);

    printf("Digite o valor máximo: ");
    scanf("%d", &max);

    pular(1);

    for (i = 0; i < max; i++){
        //colunas
        for (j = 1; j <= 2; j++){
            printf("%d", (min + i));
        }
        pular(1);
    }
}

void pular(int qtd_linhas){
    int i;
    for (i = 1; i <= qtd_linhas; i++){
        printf("\n");
    }
}


