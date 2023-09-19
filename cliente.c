#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "cliente.h"
#include "telas.h"


void cliente(void) {
    char op;
    do { // Loop para o menu de Clientes se repetir                                                           
        system("clear||cls");
        printf("===============================\n");
        printf("\n");
        printf("   Gerenciamento de Clientes   \n");
        printf("\n");
        printf("===============================\n");
        printf("\n");
        printf("|[1]. Cadastrar Cliente\n");
        printf("|[2]. Pesquisar Cliente\n");
        printf("|[3]. Atualizar Cliente\n");
        printf("|[4]. Listar Cliente\n");
        printf("|[5]. Excluir Cliente\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();

        switch (op) {
            case '1':
                cadastrocliente();
                break;
            case '2':
                pesquisacliente();
                break;
            case '3':
                atualizacliente();
                break;
            case '4':
                listacliente();
                break;
            case '5':
                excluircliente();
                break;
            case '0':
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != '0'); // Sai do loop e volta para o menu principal caso a opcção = 0
}

void cadastrocliente(void){
    system("clear||cls");
    printf("Cadastro Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisacliente(void){
    system("clear||cls");
    printf("Pesquisa Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizacliente(void){
    system("clear||cls");
    printf("Atualizar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listacliente(void){
    system("clear||cls");
    printf("Listar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluircliente(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}