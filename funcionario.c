#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "funcionario.h"
#include "telas.h"
#include "ulti.h"



void funcionario(void){
    char op;
    do {
        system("clear||cls");
        printf("===================================\n");
        printf("\n");
        printf("   Gerenciamento de Funcion�rios   \n");
        printf("\n");
        printf("===================================\n");
        printf("\n");
        printf("|[1]. Cadastrar Funcionário\n");
        printf("|[2]. Pesquisar Funcionário\n");
        printf("|[3]. Atualizar Funcionário\n");
        printf("|[4]. Excluir Funcionário\n");
        printf("|[5]. Listar Funcionários\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();
    
        switch (op){
          case '1':
              cadastrofun();
              break;
          case '2':
              pesquisafun();
              break;
          case '3':
              atualizafun();
              break;
          case '4':
              excluirfun();
              break;
          case '5':
              listafun();
              break;
          case '0':
              break;
          default:
              printf("Opção inválida! Tente novamente.\n");
      }     
    } while (op != '0');
}

void cadastrofun(void){
    char cpf[12];
    char nome[100];
  
    system("clear||cls");
    printf("===========================\n");
    printf("\n");
    printf("   Cadastro de Dentista   \n");
    printf("\n");
    printf("===========================\n");
  
    printf("Digite o CPF do dentista(Apenas numeros):\n");
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
    printf("Digite o nome do dentista: \n");
    scanf("%s", nome); 
    if (validarNome(nome)) {
        printf("Nome válido.\n");
        printf("=-=-=-=-=-=-=\n");
    } else {
        printf("Nome inválido.\n");  
        printf("=-=-=-=-=-=-=-=\n");
    }
    
    printf("Digite a data de nascimentos do funcionário:\n");
    printf("Digite o telefone do funcionário:\n");
    
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisafun(void){
    system("clear||cls");
    printf("Digite o CPF do funcionário que deseja pesquisar:\n");
    printf("\n");
    printf("EM CONSTRÇÃO...");  
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizafun(void){
    system("clear||cls");
    printf("Digite o CPF do funcionário que deseja atualizar:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listafun(void){
    system("clear||cls");
    printf("Lista de funcionários cadastrados nos sistema:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluirfun(void){
    system("clear||cls");
    printf("Digite o CPF do funcionário que deseja excluir:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}