#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "funcionario.h"
#include "telas.h"
#include "ulti.h"



void funcionario(void){
    char op;
    do { //Faz um loop para o menu de funcionarios so aceitar opcoes validas
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
    struct funcionario Funcionario; //Struct que contem as informacoes de cadastro de funcionarios
    int valido = 0;  // Variavel para controle de loop
  
    system("clear||cls");
    printf("===========================\n");
    printf("\n");
    printf("   Cadastro de Dentista   \n");
    printf("\n");
    printf("===========================\n");
  
    do { //Cria um loop que so sai quando a informacao for valida
      printf("Digite o CPF do Dentista(Apenas numeros):");
      scanf("%s", Funcionario.cpf); //Recebe a variavel CPF
      if (validaCPF(Funcionario.cpf)) { //Valida o CPF
          printf("CPF válido.\n");
          printf("=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o CPF for valido
      } else {
          printf("CPF inválido.\n");
          printf("=-=-=-=-=-=-=\n");
      }
    } while (!valido); 
    
    valido = 0; //Zera o variavel para ser possivel realizar o loop novamente
    do {
      printf("\n");
      printf("Digite o nome do Dentista:");
      scanf("%s", Funcionario.nome); //"Funcionario.nome" armazena a variavel nome na struct de funcionarios "funcionario.h"
      if (validarNome(Funcionario.nome)) {
          printf("Nome válido.\n");
          printf("=-=-=-=-=-=-=\n");
          valido = 1;
      } else {
          printf("Nome inválido.\n");  
      }
    } while (!valido);
    
    valido = 0;
    do {
      printf("\n");
      printf("Digite um número de telefone(apenas números com o DD e com o 9 a mais):");
      scanf("%s", Funcionario.telefone);
      if (validaTele(Funcionario.telefone)) {
          printf("Número de telefone válido.\n");
          printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
          valido = 1;
      } else {
          printf("Número de telefone inválido.\n");
      }
    } while (!valido);

    
    printf("\n");
    printf("=============================\n"); //Exibe as informaceos de cadastro dos funcionarios
    printf("\n");
    printf("   Informações do Dentista   \n");
    printf("\n");
    printf("=============================\n");

    printf("|CPF: %s\n", Funcionario.cpf); //Da printf na string contida na variavel CPF
    printf("|Nome: %s\n", Funcionario.nome);
    printf("|Telefone: %s\n", Funcionario.telefone);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("\n");
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

