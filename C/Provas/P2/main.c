#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void main()
{
    setlocale(LC_ALL, "portuguese");
    int key;
    do{
        system("cls");
        header();
        pular(1);
        menu();
        key = getch();

        switch(key){
            case '1':
                questao_01();
                break;

            case '2':
                questao_02();
                break;
        }
    }while (key != 27);
}

void header()
{
    printf("----- PROVA -----\n\n");
    printf("|| Nome: Bruno Marini\n");
    printf("|| Matrícula: 634883\n\n");
    printf("| Aperte ESC para sair | \n");
}

void menu(){
    printf("1. Questão 01\n");
    printf("2. Questão 02");
}

void pular(int qtd_linhas){
    int i;
    for (i = 1; i <= qtd_linhas; i++){
        printf("\n");
    }
}

void questao_01(){
    int key, aluno[100] = {100, 200, 250, 300}, total_alunos = 4;
    do{
        system("cls");
        header();
        printf("\n---- QUESTÃO 01 ----\n\n");
        printf("1 - Inserir novo aluno\n");
        printf("2 - Imprimir alunos\n");
        printf("3 - Sair");

        key = getch();
        switch(key){
            case '1':
                pular(1);
                int cod_aluno;
                printf("\nDigite o código do aluno novo: ");
                scanf("%d", &cod_aluno);
                setAluno(cod_aluno, total_alunos, aluno);
                total_alunos++;
                printf("\nALUNO INSERIDO COM SUCESSO!!\n\n");
                system("pause");
                break;

            case '2':
                pular(2);
                showAlunos(total_alunos, aluno);
                pular(1);
                system("pause");
                break;
        }
    }while(key != '3');
}

void setAluno(int cod_aluno, int total_alunos, int *vet){
    int i, k;

    for (i = 0; i < total_alunos; i++) {
        if (cod_aluno < vet[i]){
            for (k = total_alunos - 1; k > i; k--) {
                vet[k + 1] = vet[k];
            }
            vet[i] = cod_aluno;
            break;
        }
    }
}

void showAlunos(int total_alunos, int *vet){
    int i;
    for (i = 0; i < total_alunos; i++) {
        printf("Aluno[%d] = %d\n",i,vet[i]);
    }
}

void questao_02(){
    int key;
    do{
        system("cls");
        header();
        printf("\n---- QUESTÃO 02 ----\n\n");
        printf("0 - Voltar\n");
        printf("1 - Letra A\n");
        printf("2 - Letra B\n");
        printf("3 - Letra C\n");
        printf("4 - Letra D\n");

        key = getch();
        switch(key){
            case '1':
                pular(1);
                int **a = letra_A(12);
                free(a);
                break;

            case '2':
                break;

            case '3':
                break;

            case '4':
                break;
        }
    }while(key != '0');
}

int letra_A(int t){
    int linha, coluna, **matriz = malloc(sizeof(int)*t);;

    for (linha=0; linha<t; linha++)
    {
        matriz[linha]=malloc(sizeof(int)*t);
    }
    for (linha=0; linha<t; coluna++)
    {
        for (coluna=0; coluna<t; coluna++)
        {
            matriz[linha][coluna] = t;
        }
    }
    return matriz;
}
