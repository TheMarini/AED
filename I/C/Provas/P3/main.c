#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>

struct produto
{
    int codigo;
    char descricao[50];
    float preco;
};
typedef struct produto Produto;

void main()
{
    setlocale(LC_ALL, "portuguese");

    int key;

    do
    {
        system("cls");
        header();
        pular(1);
        menu();

        key = getch();

        switch(key)
        {
        case '1':
            pular(2);
            setProduto();
            break;

        case '2':
            editProduto();
            break;
        case '3':
            break;

        case '4':
            pular(2);
            getProdutos();
            break;

        case '5':
            pular(2);
            getProdutos_byValue();
            break;
        }
    }
    while (key != 27);
}

void pular(int qtd_linhas)
{
    int i;
    for (i = 1; i <= qtd_linhas; i++)
    {
        printf("\n");
    }
}

void header()
{
    printf("----- PROVA -----\n\n");
    printf("|| Nome: Bruno Marini\n");
    printf("|| Matrícula: 634883\n\n");
    printf("| Aperte ESC para sair | \n");
}

void menu()
{
    printf("1. Incluir\n");
    printf("2. Alterar\n");
    printf("3. Excluir\n");
    printf("4. Listar todos os items e seus respectivos preços\n");
    printf("5. Listar todos os items que possuem preço acima de um determinado valor\n");

}

void setProduto()
{
    FILE *file;
    fflush(stdin);

    Produto produto;

    printf("Digite o código do produto: ");
    scanf("%d", &produto.codigo);
    printf("Digite a descrição do produto: ");
    scanf("%s", &produto.descricao);
    printf("Digite o preço do produto: ");
    scanf("%f", &produto.preco);
    if((file = fopen("produtos.dat", "a+b")) != NULL){
        fseek(file, 0, SEEK_END);
        fwrite(&produto, sizeof(produto), 1, file);
        fclose(file);

        pular(2);
        printf("Produto registrado com sucesso! ");
    }
    else{
        printf("Ocorreu um erro ao abrir o arquivo :(");
    }
    pular(2);
    system("pause");
}

void getProdutos()
{
    FILE *file;
    Produto produto;
    if((file = fopen("produtos.dat","r+b")) != NULL){
        fseek(file, 0, SEEK_SET);
        fread(&produto, sizeof(produto), 1, file);
        while(!feof(file)){
            printf("Código: %d\nDescrição: %s\nPreço: %f\n", produto.codigo, produto.descricao, produto.preco);
            fread(&produto, sizeof(produto), 1, file);
            pular(1);
        }
        fclose(file);
    }
    else{
        printf("Ocorreu um erro ao abrir o arquivo :(");
    }
    pular(1);
    system("pause");
}

void getProdutos_byValue(){

    int found = 0;
    float preco;

    printf("Digite o preço mínimo a ser procurado: ");
    scanf("%f", &preco);

    pular(1);

    FILE *file;
    Produto produto;
    if((file = fopen("produtos.dat","r+b")) != NULL){
        fseek(file, 0, SEEK_SET);
        fread(&produto, sizeof(produto), 1, file);
        while(!feof(file)){
            if (produto.preco > preco){
                printf("Código: %d\nDescrição: %s\nPreço: %f\n", produto.codigo, produto.descricao, produto.preco);
                found = 1;
            }
            fread(&produto, sizeof(produto), 1, file);
        }
        if(!found)
            printf("\nNenhum produto encontrado!\n");
        fclose(file);
    }
    else{
        printf("Ocorreu um erro ao abrir o arquivo :(");
    }
    pular(1);
    system("pause");
}

void editProduto()
{
    FILE *file;

    int procura;
    printf("Difite o código do produto a ser alterado: ");
    scanf("%d", &procura);

    Produto produto;
    if((file = fopen("produtos.dat","r+b")) != NULL){
        fseek(file, 0, SEEK_SET);
        fread(&produto, sizeof(produto), 1, file);
        while(!feof(file)){
            if (produto.codigo == procura){
                produto.codigo = codigo;
                produto.descricao = descricao;
                produto.preco = preco;
                found = 1;
            }
            fread(&produto, sizeof(produto), 1, file);
        }
        if(!found)
            printf("\nNenhum produto encontrado!\n");
        fclose(file);
    }
    else{
        printf("Ocorreu um erro ao abrir o arquivo :(");
    }
    pular(1);
    system("pause");
}
