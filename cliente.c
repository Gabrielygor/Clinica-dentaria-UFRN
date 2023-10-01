#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "cliente.h"
#include "telas.h"
#include "ulti.h"



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
    char cpf[12];
    char nome[100];

    system("clear||cls");
    printf("==========================\n");
    printf("\n");
    printf("   Cadastro de Clientes   \n");
    printf("\n");
    printf("==========================\n");

    printf("Digite o CPF do cleinte(Apenas numeros):\n");
    scanf("%s", cpf);
    if (validaCPF(cpf)) {
        printf("===========\n");
        printf("CPF válido.\n");
        printf("===========\n");
    } else {
        printf("=============\n");
        printf("CPF inválido.\n");
        printf("=============\n");
    }

    printf("\n");
    printf("Digite o nome do cliente: \n");
    scanf("%s", nome); 
    if (validarNome(nome)) {
        printf("Nome válido.\n");
        printf("=-=-=-=-=-=-=\n");
    } else {
        printf("Nome inválido.\n");  
        printf("=-=-=-=-=-=-=-=\n");
    }

    printf("Digite a data de nascimento do cliente:\n");
    printf("Digite o telefone do cliente:\n");
    printf("\n");
    printf(  "EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisacliente(void){
    system("clear||cls");
    printf("Digite o CPF do cliente que deseja buscar:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizacliente(void){
    system("clear||cls");
    printf("Digite o CPF do cliente para atualizar:");
    printf("\n");  
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listacliente(void){
    system("clear||cls");
    printf("Lista de Clientes cadastrados no sistema:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluircliente(void){
    system("clear||cls");
    printf("Digite o CPF do cliente que deseja excluir:\n");
    printf("\n");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}