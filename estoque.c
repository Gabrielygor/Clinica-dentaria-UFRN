#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "estoque.h"
#include "telas.h"
#include "ulti.h"
#include <string.h>


void estoque(void){
    char op;
    do{
        system("clear||cls");
        printf("=============\n");
        printf("\n");
        printf("   Estoque   \n");
        printf("\n");
        printf("=============\n");
        printf("\n");
        printf("|[1]. Adicionar Estoque\n");
        printf("|[2]. Excluir Estoque\n");
        printf("|[3]. Listar Estoque\n");
        printf("|[4]. Editar Estoque\n");
        printf("|[5]. Pesquisar Estoque\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %s", &op);
        getchar();

        switch (op){
          case '1':
            adicionarestoque();
            break;
          case '2':
            excluirestoque();
            break;
          case '3':
            listarestoque();
            break;
          case '4':
            alterarestoque();
            break;
          case '5':
            pesquisarestoque();
            break;
          case '0':
            break;
          default:
            printf("Opção inválida! Tente novamente.\n");
            
            
        }

      }  while (op != '0');
}

void saveObjetoEstoque(ObjetoEstoque* objeto) {
    FILE* file = fopen("estoque.dat", "ab");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }
    fwrite(objeto, sizeof(ObjetoEstoque), 1, file);
    fclose(file);
}

// Função para listar os objetos no estoque
void listarestoque(void) {
    ObjetoEstoque objeto;
    system("clear||cls");
    printf("=========================\n");
    printf("   Lista de Objetos   \n");
    printf("=========================\n");
    printf("\n");

    FILE* file = fopen("estoque.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&objeto, sizeof(ObjetoEstoque), 1, file) == 1) {
        if (objeto.ativo == 1) {
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Nome: %s\n", objeto.nome);
            printf("Quantidade: %d\n", objeto.quantidade);
            printf("ID: %d\n", objeto.id);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// Função para adicionar um objeto ao estoque
void adicionarestoque(void) {
    ObjetoEstoque objeto;

    system("clear||cls");
    printf("===========================\n");
    printf("   Adicionar ao Estoque   \n");
    printf("===========================\n");

    printf("Digite o nome do objeto: ");
    scanf("%s", objeto.nome);

    printf("Digite a quantidade do objeto: ");
    scanf("%d", &objeto.quantidade);

    printf("Digite um ID para o objeto: ");
    scanf("%d", &objeto.id);

    objeto.ativo = 1;

    saveObjetoEstoque(&objeto);

    printf("\n");
    printf("Objeto adicionado ao estoque com sucesso.\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

// Função para excluir um objeto do estoque
void excluirestoque(void) {
    char nome[100];
    ObjetoEstoque objeto;
    int objetoEncontradoFlag = 0;

    system("clear||cls");
    printf("=========================\n");
    printf("   Excluir do Estoque   \n");
    printf("=========================\n");

    printf("Digite o nome do objeto que deseja excluir: ");
    scanf("%s", nome);

    FILE* file = fopen("estoque.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&objeto, sizeof(ObjetoEstoque), 1, file) == 1) {
        if (strcmp(objeto.nome, nome) == 0) {
            objeto.ativo = 0;
            fseek(file, -sizeof(ObjetoEstoque), SEEK_CUR);
            fwrite(&objeto, sizeof(ObjetoEstoque), 1, file);
            objetoEncontradoFlag = 1;
            break;
        }
    }

    if (!objetoEncontradoFlag) {
        printf("\n");
        printf("Objeto com nome %s não encontrado.\n", nome);
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("\n");
        printf("Objeto excluído do estoque com sucesso.\n");
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    fclose(file);
    getchar();
}

void alterarestoque(void) {
    char nome[100];
    ObjetoEstoque objeto;
    int objetoEncontradoFlag = 0;

    system("clear||cls");
    printf("===========================\n");
    printf("   Alterar no Estoque   \n");
    printf("===========================\n");

    printf("Digite o nome do objeto que deseja alterar: ");
    scanf("%s", nome);

    FILE* file = fopen("estoque.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&objeto, sizeof(ObjetoEstoque), 1, file) == 1) {
        if (strcmp(objeto.nome, nome) == 0) {
            objeto.ativo = 0;
            fseek(file, -sizeof(ObjetoEstoque), SEEK_CUR);
            printf("Digite o novo nome do objeto: ");
            scanf("%s", objeto.nome);
            printf("Digite a nova quantidade do objeto: ");
            scanf("%d", &objeto.quantidade);
            printf("Digite o novo ID do objeto: ");
            scanf("%d", &objeto.id);
            objeto.ativo = 1;
            fseek(file, -sizeof(ObjetoEstoque), SEEK_CUR);
            fwrite(&objeto, sizeof(ObjetoEstoque), 1, file);
            objetoEncontradoFlag = 1;
            break;
        }
    }

    if (!objetoEncontradoFlag) {
        printf("\n");
        printf("Objeto com nome %s nao encontrado.\n", nome);
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("\n");
        printf("Objeto alterado no estoque com sucesso.\n");
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    fclose(file);
    getchar();
}

// Função para pesquisar objetos no estoque
void pesquisarestoque(void) {
    char nome[100];
    ObjetoEstoque objeto;
    int objetoEncontradoFlag = 0;

    system("clear||cls");
    printf("===========================\n");
    printf("   Pesquisar no Estoque   \n");
    printf("===========================\n");

    printf("Digite o nome do objeto que deseja pesquisar: ");
    scanf("%s", nome);

    FILE* file = fopen("estoque.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&objeto, sizeof(ObjetoEstoque), 1, file) == 1) {
        if (strcmp(objeto.nome, nome) == 0) {
            printf("\n");
            printf("Nome: %s\n", objeto.nome);
            printf("Quantidade: %d\n", objeto.quantidade);
            printf("ID: %d\n", objeto.id);
            printf("\n");
            objetoEncontradoFlag = 1;
            break;
        }
    }

    if (!objetoEncontradoFlag) {
        printf("\n");
        printf("Objeto com nome %s nao encontrado no estoque.\n", nome);
    }

    fclose(file);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}