#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Produto{
        char codigo[5];
        char descricao[30];
        float preco;
 }Produto;

void carregar_menu(){
    printf("====CADASTRO DE PRODUTOS====\n\n");
    printf("Escolha uma das opcoes abaixo\n");
    printf("[1] Cadastrar Produto\n");
    printf("[2] Gerar Estoque\n");
    printf("[3] Exibir Estoque\n");
    printf("[0] Sair\n\n");
 }

void cadastrar_produto(Produto *produtos, int *i){

    system("cls");

    Produto produto;

    printf("Insira o codigo do produto: ");
    scanf("%s", &produto.codigo);
    produto.codigo[strcspn(produto.codigo, "\n")] = '\0';

    printf("Insira a descricao do produto: ");
    scanf("%s", &produto.descricao);
    produto.descricao[strcspn(produto.descricao, "\n")] = '\0';

    printf("Insira o valor do produto: ");
    scanf("%f", &produto.preco);

    produtos[*i] = produto;
    (*i)++;

    system("cls");
    printf("Produto cadastrado com sucesso!\n\n");
}

void gravar_estoque(Produto *produtos, int i){

    system("cls");

    FILE *estoque = fopen("estoque.txt", "w");

    for(int j = 0; j < i; j++){
        fprintf(estoque, "Codigo: %s\nDescricao: %s\nPreco: %.2f\n\n", produtos[j].codigo, produtos[j].descricao, produtos[j].preco);
    }

    fclose(estoque);
    printf("Produtos gravados com sucesso\n\n");
}

void exibir_estoque(){

    system("cls");

    FILE *estoque = fopen("estoque.txt", "r");
    char linha[100];

    if(estoque == NULL){
        printf("Nao foi possivel localizar o arquivo estoque.txt\n\n");
        return;
    }

    printf("PRODUTOS EM ESTOQUE\n\n");
    while (fgets(linha, sizeof(linha), estoque) != NULL) {
        printf("%s", linha);
    }
    printf("------------------------------------\n\n");
    fclose(estoque);
}

void finalizar_programa(){
    system("cls");
    printf("Programa encerrado com sucesso\n\n");
}

int main(){
    Produto produtos[10];
    int i = 0;
    int opcao;

    while(1){
        carregar_menu();
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1) cadastrar_produto(produtos, &i);
        if(opcao == 2) gravar_estoque(produtos, i);
        if(opcao == 3) exibir_estoque();
        if(opcao == 0){
            finalizar_programa();
            break;
        }
    }

    return 0;
}
