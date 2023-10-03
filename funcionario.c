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
        printf("   Gerenciamento de Funcionarios   \n");
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
    char cpf[12];     //Variaveis utilizados no cadastro de funcionarios
    char nome[100];
    char telefone[12];
  
    system("clear||cls");
    printf("===========================\n");
    printf("\n");
    printf("   Cadastro de Dentista   \n");
    printf("\n");
    printf("===========================\n");
  
    printf("Digite o CPF do dentista(Apenas numeros):\n"); // pergunta qual o cpf do dentista
    scanf("%s", cpf); //Recebe o cpf do dentista
    if (validaCPF(cpf)) { //Manda o cpf para o validador (ulti.c)
        printf("CPF válido.\n"); //Se o cpf for valido retorna (valido)
        printf("=-=-=-=-=-=\n");
    } else {
        printf("CPF inválido.\n");
        printf("=-=-=-=-=-=-=\n");
    }
    
    printf("\n");
    printf("Digite o nome do dentista(Sem espaço entre os nomes): \n"); // Repete o mesmo processo que a validacao de cpf. (ulti.c)
    scanf("%s", nome); 
    if (validarNome(nome)) {
        printf("Nome válido.\n");
        printf("=-=-=-=-=-=-=\n");
    } else {
        printf("Nome inválido.\n");  
        printf("=-=-=-=-=-=-=-=\n");
    }
    
    printf("\n");
    printf("Digite um número de telefone (apenas números com o DD e com o 9 a mais): ");
    scanf("%s", telefone);

    if (validaTele(telefone)) {
        printf("Número de telefone válido.\n");
    } else {
        printf("Número de telefone inválido.\n");
    }
    
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