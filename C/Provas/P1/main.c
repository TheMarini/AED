#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

int opcao;

//MAIN
void main()
{
    setlocale(LC_ALL, "Portuguese");

    do{
        header();
        menu();

        do{
            key();
        }while(opcao != '2' && opcao != '3' && opcao != 27);

        system("cls");

        getQuestao();

        system("pause");

    }while (opcao != 27);
}

//HEADER
void header(){
    system("cls");
    printf("\n --- PROVA ---\n\n");
    printf(" | Aluno: Bruno Marini\n");
    printf(" | Matrícula: 634883\n\n");
    printf(" | Aperte ESC para sair |");
    pular(2);

}

//PULAR LINHA
void pular(int qtd_linhas){
    int i;
    for ( i = qtd_linhas; i > 0; i-- )
    {
        printf("\n");
    }
}

//MENU
void menu(){
    printf(" 2. Questão 02 (10 pontos)\n");
    printf(" 3. Questão 03 (15 pontos)\n");
}

//TECLA PRESSIONADA
void key(){
    opcao = getch();

    if (opcao == 27){
        exit(EXIT_SUCCESS);
    }
}

//PEGAR QUESTÃO
 void getQuestao(){
    int numero;
    switch(opcao){
        case '2':
           printf("Digite quantos litros foram vendidos: ");

           int litro, tipo;
           float total, desconto;

           scanf("%d", &litro);

           printf("\nQual o tipo de combustivel? (A - Álcool | G - Gasolina)\n");
           do{
              tipo = getch();
           }while(tipo != 'A' && tipo != 'a' && tipo != 'G' && tipo != 'g');

           switch (tipo){
              case 'A':
              case 'a':
                total = (3.20 * litro);
                if (litro <= 15){
                    desconto = total * 0.03;
                }
                else{
                    desconto = total * 0.05;
                }
                total -= desconto;
              break;

              case 'G':
              case 'g':
                total = (4.50 * litro);
                if (litro <= 20){
                    desconto = total * 0.04;
                }
                else{
                    desconto = total * 0.06;
                }
                total -= desconto;
              break;
           }

           pular(1);
           printf(" | TOTAL: R$%f", total);
           pular(1);
        break;

        case '3':
            do{
                printf("Digite um nº entre 3 e 10: ");
                scanf("%d", &numero);
                pular(1);
            }while (numero < 3 || numero > 10);

            int tabuada, i;
            for (tabuada = 1; tabuada <= numero; tabuada++){
                printf("TABUADA DO %d", tabuada);
                pular(1);
                for (i = 1; i <= 10; i++){
                    printf("%d", tabuada);
                    printf(" x %d", i);
                    printf(" = ");
                    printf("%d", tabuada * i);
                    pular(1);
                }
                pular(1);
            }
        break;
    }
    pular (1);
}

