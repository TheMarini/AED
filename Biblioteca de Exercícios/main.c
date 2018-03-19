#include <stdlib.h> //standard library
#include <stdio.h>  //standard input
#include <locale.h> //language library
#include <string.h> //string library
#include <time.h>   //time library

// PRELOAD FUNCTIONS
void header();   //cabeçalho
void menu();     //menu
void opcoes();   //etapa do menu
void listar();   //listar items do menu
void getExercicio();  //pegar exercícios

void cor();  //definir a cor do programa

void pular(); //pular linha
void traco(); //traco de estilo

// GLOBAL VARS
char opc[2];

// MAIN
void main() {
	setlocale(LC_ALL, "Portuguese"); // declarar lingua

	opc[0] = '0';
	header();

    int i;
	for (i = 0; i < 7; i++){
        cor("0a");
        cor("01");
        cor("07");
	}

	do {
        menu();
        if (opc[0] != '0'){
            getExercicio();
        }
    } while (opc[0] != 27 && opc[1] != 27);
}

void cor(char codigo[2]){
    char comando[] = "color ";
    strcat(comando, codigo);

    system(comando);
}

//CABEÇALHO
void header() {
	printf("----- BIBLIOTECA DE EXERCÍCIOS -----");
	pular(2);

	printf("|| Aluno: Bruno Marini\n");
	printf("|| RA: 634883\n\n");

	printf("| Aperte Esc para sair\n");
}

//PULAR LINHA
void pular(int qtd_linhas) {
	int i;
	for (i = 1; i <= qtd_linhas; i++) {
		printf("\n");
	}
}

//MENU
void menu() {
    pular(1);

	if (opc[0] == '0'){
        opcoes(0);

        do{
            key(0);
        }
        while (opc[0] != '1' && opc[0] != '2' && opc[0] != '3' && opc[0] != '4');

        pular(1);
	}

    opcoes(1);

    if (opc[0] != '0'){
        key(1);
    }

	if (opc[1] == '0') {
		opc[0] = '0';
		system("cls");
		header();
		menu();
	}
}

//OPÇÕES DO MENU
void opcoes(int etapa) {
	if (!etapa) {
		printf("Escolha a aula: \n");
		listar("Aula ", 4, 0);
	} else {
		switch (opc[0]) {
		case '2':
			printf("Escolha o exercício: \n");
			listar("Ex. ", 5, 1);
			break;

		case '3':
			printf("Escolha o exercício: \n");
			listar("Ex. ", 4, 1);
			break;

        case '4':
			printf("Escolha o exercício: \n");
			listar("Ex. ", 2, 1);
			break;

		default:
			printf("-> Não há exercícios nessa aula!\n");
			opc[0] = '0';
			break;
		}
	}
}

//LISTAR ITEMS DO MENU
void listar(char frase[20], int limite, int voltar) {
	char i;
	if (voltar) {
		printf("  0. Voltar\n");
	}
	for (i = 1; i <= limite; i++) {
		printf("  %d", i);
		printf(". %s", frase);
		printf("0%d", i);
		pular(1);
	}
}

//TECLA APERTADA
void key(int vetor){
    opc[vetor] = getch();
    fflush(stdin);

    if (opc[vetor] == 27) {
        exit(EXIT_SUCCESS);
    }
}

//PEGAR EXERCÍCIO
void getExercicio() {
	traco(0); // traço de estilo

	int i, val[2]; // iterador e variáveis
	switch (opc[0]) {
	// AULA 02
	case '2':
		switch (opc[1]) {
		// Ex. 01
		case '1':
			printf("\nNOME DO EXERCÍCIO: Soma de 2 números\n \n");
			for (i = 1; i <= 2; i++) {
				printf(" -> Digite o ");
				printf("%d", i);
				printf("º número: ");

				scanf("%d", &val[i - 1]);
				fflush(stdin);
			}
			pular(1);
			printf("| Resultado: %d", val[0] + val[1]);
			break;

		// Ex. 02
		case '2':
			printf(
				"\nNOME DO EXERCÍCIO: Soma, multiplicação e média "
				"aritmética de 2 números\n \n");
			for (i = 1; i <= 2; i++) {
				printf(" -> Digite o ");
				printf("%d", i);
				printf("º número: ");

				scanf("%d", &val[i - 1]);
				fflush(stdin);
			}
			printf("\n| Soma: %d", val[0] + val[1]);
			printf("\n| Multiplicação: %d", val[0] * val[1]);
			printf("\n| Média Aritmética: %d", (val[0] + val[1]) / 2);
			break;

		// Ex. 03
		case '3':
			printf("\nNOME DO EXERCÍCIO: Volume de um cilindro circular\n \n");
			printf(" -> Digite a altura: ");
			scanf("%d", &val[0]);
			fflush(stdin);

			printf(" -> Digite o raio: ");
			scanf("%d", &val[1]);
			fflush(stdin);

			pular(1);
			printf("| Resultado: %f", (3.14 * (val[1] * val[1]) * val[0]));
			break;

		// Ex. 04
		case '4':
			printf("\nNOME DO EXERCÍCIO: Salário líquido do encanador\n \n");
			printf(" -> Digite o nº de dias trabalhados: ");

			int salario;

			scanf("%d", &salario);
			fflush(stdin);

			pular(1);
			printf("| Resultado: %f", ((20 * salario) - (salario * 0.08)));
			break;

		// Ex. 05
		case '5':
			printf("\nNOME DO EXERCÍCIO: Conta de lanchonete\n \n");

			float val[2];

			printf(" Hamburguer     |  R$30,00  -> ");
			scanf("%f", &val[0]);
			fflush(stdin);

			val[0] *= 30;

			printf(" Cheeseburguer  |  R$25,50  -> ");
			scanf("%f", &val[1]);
			fflush(stdin);

			val[0] += val[1] * 25.5;

			printf(" Fritas         |  R$20,50  -> ");
			scanf("%f", &val[1]);
			fflush(stdin);

			val[0] += val[1] * 20.5;

			printf(" Refrigerante   |  R$10,00  -> ");
			scanf("%f", &val[1]);
			fflush(stdin);

			val[0] += val[1] * 10;

			printf(" Milkshake      |  R$40,00  -> ");
			scanf("%f", &val[1]);
			fflush(stdin);

			val[0] += val[1] * 40;

			pular(1);
			printf("|| Total: %f", val[0]);
			break;

		default:
			printf("Esse exercíco ainda não está pronto :(");
			break;
		}
		break;

	case '3':
		switch (opc[1]) {
		// Ex. 01
		case '1':
			printf("\nNOME DO EXERCÍCIO: Maior ou Igual\n \n");

			for (i = 1; i <= 2; i++) {
				printf(" -> Digite o ");
				printf("%d", i);
				printf("º número: ");

				scanf("%d", &val[i - 1]);
				fflush(stdin);
			}

			pular(1);

			if (val[0] >= val[1]) {
				if (val[0] > val[1]) {
					printf("| O 1º número é maior");
				} else {
					printf("| Os dois números são iguais");
				}
			} else {
				printf("| O 2º número é maior");
			}
			break;

		// Ex. 02
		case '2':
			printf(
				"\nNOME DO EXERCÍCIO: Somas apenas se ambos forem positivos "
				"e informar qual é o negativo caso exista\n \n");

			for (i = 1; i <= 2; i++) {
				printf(" -> Digite o ");
				printf("%d", i);
				printf("º número: ");

				scanf("%d", &val[i - 1]);
				fflush(stdin);
			}

			pular(1);
			if (val[0] > 0 & val[1] > 0) {
				printf("| Total: %d", val[0] + val[1]);
			} else {
				if (val[0] < 0 & val[1] < 0) {
					printf("| Ambos são números negativos");
				} else {
					if (val[0] < 0) {
						printf("| O número negativo é: %d", val[0]);
					} else {
						printf("| O número negativo é: %d", val[1]);
					}
				}
			}
			break;

		// Ex. 03
		case '3':
			printf(
				"\nNOME DO EXERCÍCIO: Calcular raízes do 2º grau e informar "
				"quando não forem reais\n \n");

			printf(" || Formato: _x² + _x + _ = 0\n");
			printf(" || Exemplo: 10x² + 2x + 4 = 0\n");

			pular(1);

			int val[3];
			for (i = 1; i <= 3; i++) {
				printf(" -> Digite o ");
				printf("%d", i);
				printf("º número: ");

				scanf("%d", &val[i - 1]);
				fflush(stdin);
			}

			int res = (val[1] * val[1]) - 4 * val[0] * val[2];

			printf("\n RESULTADO");
			printf("\n | Raiz: ±√%d", res);

			if (res < 0) {
				printf("\n | A raiz NÃO é real");
			}
			break;

		// Ex. 04
		case '4':
			printf(
				"\nNOME DO EXERCÍCIO: Categoria do atleta pela faixa "
				"etária\n \n");

			char nome[20];
			int idade;

			printf("Nome: ");
			scanf("%s", &nome);
			fflush(stdin);

			printf("Idade: ");
			scanf("%d", &idade);
			fflush(stdin);

			printf("\n| Sua categoria é: ");

			if (idade >= 4 & idade <= 10) {
			  	printf("INFANTIL");
			}
			if (idade >= 11 & idade <= 15) {
				  printf("JUVENIL");
			}
			if (idade >= 16 & idade <= 20) {
					printf("JUNIOR");
			}
			if (idade >= 21 & idade <= 25) {
			 		printf("PROFISSIONAL");
			}
		break;
	}
	break;

	case '4':
        switch (opc[1]) {
            case '1':
            printf("\nNOME DO EXERCÍCIO: Cara ou Coroa\n \n");

            printf(" -> Escolha um lado da moeda: \n\n");
            printf("   0. Cara \n");
            printf("   1. Coroa \n\n");

            int lado;
            do{
                lado = getch();
                fflush(stdin);
            }while (lado != '0' && lado != '1');

			int i;
			int joga;
			for (i = 1; i <= 10; i++){
                printf("%d", i);
                printf("ª jogada: ");

                //joga = rand() % 2;

                if ((rand() % 2) == 0){
                    printf("cara");
                }
                else{
                    printf("coroa");
                }
                //printf("%d", joga);
                pular(1);
			}
            break;

            case '2':
                printf("Esse é o 2");
            break;
        }
	break;
    }
    pular(1);
    traco(1);
}

//TRAÇO DE ESTILO
void traco(int ordem) {
	if (!ordem) {
		pular(1);
	}
	int i;
	for (i = 1; i <= 50; i++) {
		printf("-");
	}
	if (ordem) {
		pular(1);
	}
}
