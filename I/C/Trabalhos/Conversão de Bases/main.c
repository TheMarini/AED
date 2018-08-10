#include <stdio.h>  //Entrada de valores padrão do C
#include <stdlib.h> //Biblioteca padrão do C
#include <locale.h> //Biblioteca para línguas e caracteres
#include <string.h> //Biblioteca para manuseio de variáveis tipo String
#include <math.h>   //Biblioteca para cálculos matemáticos

/*  AUTORES: Arthur Teixeira, Bruno Marini, Giuliano Penido */
/*  FUNÇÃO DO SOFTWARE:  ler e converter números entre as bases decimais <-> binárias e decimais <-> octagonais, nas duas direções */

//GLOBAL VARS
//Declara as variáveis globais
int key;

//FUNCTIONS
//Declara e realiza o pré carregamento de todas as funções que serão utilizadas no decorrer do programa
void decimal_binario();
void binario_decimal();
void octal_decimal();
void decimal_octal();


//MAIN
//A função a seguir é a "main" do programa
//Ela cria um menu de interação com usuário,permitindo que ele escolha qual conversão de bases ele fará, chamando a função de conversão escolhida
void main(){
    setlocale(LC_ALL, "Portuguese");
    do {
        menu();
    }
    while (key != 27);
}

//PULAR LINHA
//Realiza o processo de pular linha de acordo com a quantidade desejada
void pular(int qtd_linhas) {
	int i;
	for (i = 1; i <= qtd_linhas; i++) {
		printf("\n");
	}
}

//MENU
//Mostra o menu e recebe a opção desejada pelo usuário
void menu(){

    printf("BEM-VINDO(A) AO CONVERSOR DE BASES");

    pular(2);
    printf("| Aperte ESC para sair\n\n");


    printf("-----------------------\n");
    printf("        MENU\n");
    printf("-----------------------\n\n");

    printf("1. DECIMAL -> BINARIO\n");
    printf("2. BINARIO -> DECIMAL\n");
    printf("3. OCTAL   -> DECIMAL\n");
    printf("4. DECIMAL -> OCTAL\n\n");

    key = getch();

    switch(key) {
        case '1':
            decimal_binario();
            break;

        case '2':
            binario_decimal();
            break;

        case '3':
            octal_decimal();
            break;

        case '4':
            decimal_octal();
            break;
    }
    pular(1);
    system("pause");
    system("cls");
}

//CONVERSÕES

//DECIMAL -> BINÁRIO
//A seguinte função realiza a conversão dos números em base decimal para a base binária
void decimal_binario() {
    printf("\n------ DECIMAL -> BINARIO ------\n");
    int total=0,valor,aux,resto=0,multiplicador=1;
    printf("\nINFORME O VALOR EM DECIMAL: ");
    scanf("%d",&valor);
    aux=valor;
    while (aux != 0) {
        resto = aux % 2;
        aux = aux / 2;
        total = total + (resto*multiplicador);
        multiplicador = multiplicador *10;
    }
    printf("\n| RESULTADO: %d = %d\n",valor,total);
}

//BINÁRIO -> DECIMAL
//A seguinte função realiza a conversão dos números em base binária para a base decimal
void binario_decimal() {
    printf("\n------ BINARIO -> DECIMAL ------\n");
    int total=0,potencia=0,algarismo=0,valor=0,aux,verifica_erro=0;
    printf("\nINFORME O VALOR EM BINARIO: ");
    scanf("%d",&valor);
    aux = valor;
    while (aux != 0) {
        algarismo = aux % 10;
        if (algarismo != 0 && algarismo != 1) {
            verifica_erro = 1;
        }
        aux = aux/10;
        total = total + (algarismo*(pow(2,potencia)));
        potencia++;
    }
    if (verifica_erro == 1){
        printf("\nO NUMERO FORNECIDO NAO ESTA NA BASE 2\n");
    }
    else {
    printf("\n| RESULTADO: %d = %d\n",valor,total);
    }
}

//OCTAL -> DECIMAL
//A seguinte função realiza a conversão dos números em base binária para a base decimal
void octal_decimal() {
    printf("\n------ OCTAL -> DECIMAL ------\n");
    int total=0,potencia=0,algarismo=0,valor=0,aux,verifica_erro=0;
    printf("\nINFORME O VALOR EM OCTAL: ");
    scanf("%d",&valor);
    aux = valor;
    while (aux != 0) {
        algarismo = aux % 10;
        if (algarismo >=0 && algarismo <= 8){
            verifica_erro = 1;
        }
        aux = aux/10;
        total = total + (algarismo*(pow(8,potencia)));
        potencia++;
    }
    if (verifica_erro == 1){
        printf("\nO NUMERO FORNECIDO NAO ESTA NA BASE 8\n");
    }
    else {
    printf("\n| RESULTADO: %d = %d\n",valor,total);
    }
}

//DECIMAL -> OCTAL
//A seguinte função realiza a conversão dos números em base decimal para a base octal
void decimal_octal() {
    printf("\n------ DECIMAL -> OCTAL ------\n");
    int total=0,valor,aux,resto=0,multiplicador=1;
    printf("\nINFORME O VALOR EM DECIMAL: ");
    scanf("%d",&valor);
    aux=valor;
    while (aux != 0) {
        resto = aux % 8;
        aux = aux / 8;
        total = total + (resto*multiplicador);
        multiplicador = multiplicador *10;
    }
    printf("\n| RESULTADO: %d = %d\n",valor,total);
}
