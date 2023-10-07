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
        printf("   Gerenciamento de Pacientes   \n");
        printf("\n");
        printf("===============================\n");
        printf("\n");
        printf("|[1]. Cadastrar paciente\n");
        printf("|[2]. Pesquisar paciente\n");
        printf("|[3]. Atualizar paciente\n");
        printf("|[4]. Listar paciente\n");
        printf("|[5]. Excluir paciente\n");
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
    char cpf[12]; // Definicao de variaveis usadas no cadasatro
    char nome[100];
    int idade;
    char telefone[12];
    char data[10];
    int valido = 0;  // Variavel para controle de loop

    system("clear||cls");
    printf("==========================\n");
    printf("\n");
    printf("   Cadastro de Pacientes   \n");
    printf("\n");
    printf("==========================\n");

    do {
      printf("======\n");
      printf("Digite o CPF do paciente(Apenas numeros):");
      scanf("%s", cpf); //Recebe a variavel cpf
      if (validaCPF(cpf)) { //Funcao que valida o cpf
          printf("CPF válido.\n");
          printf("=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o cpf for valido 
      } else {
          printf("CPF inválido.\n");
      }
    } while (!valido); // continua no loop se o cpf for valido

    valido = 0; // Zera a variavel "valido" para que seja possivel repetir o mesmo processo acima 
    do {
      printf("\n");
      printf("=======\n");
      printf("Digite o nome do paciente(Sem espaço entre os nomes): ");
      scanf("%s", nome); 
      if (validarNome(nome)) {
          printf("Nome válido.\n");
          printf("=-=-=-=-=-=-=\n");
          valido = 1;
      } else {
          printf("Nome inválido.\n");  
      }
    } while (!valido);

    valido = 0;  //Mudar para validcao de data de nascimento (Semana = ajeitar ulti.c)
    do {
      printf("\n");
      printf("======\n");
      printf("Digite a data de nascimento do cliente DD/MM/AAAA:");
      scanf("%9s", data);

      if (lerData(data)) {
        printf("Data válida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1;
      } else {
        printf("Data inválida. Tente novamente.\n");
      }
    } while (!valido);

    valido = 0;
    do {
      printf("\n");
      printf("======\n");
      printf("Digite um número de telefone (apenas números com o DD e com o 9 a mais): ");
      scanf("%s", telefone);
  
      if (validaTele(telefone)) {
          printf("Número válido.\n");
          printf("=-=-=-=-=-=-=-=\n");
          valido = 1;
      } else {
          printf("Número inválido.\n");
      }
    } while (!valido);

    exibirInformacoesCliente(cpf, nome, data, telefone);

    
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

void exibirInformacoesCliente(const char *cpf, const char *nome, const char *data, const char *telefone) {
    printf("\n");
    printf("=============================\n");
    printf("\n");
    printf("   Informações do Paciente   \n");
    printf("\n");
    printf("=============================\n");
    
    printf("CPF: %s\n", cpf);
    printf("Nome: %s\n", nome);
    printf("Data de nascimento: %s\n", data);
    printf("Telefone: %s\n", telefone);
    
    printf("\n");
    printf("Pressione <ENTER> para continuar...");
    getchar();
}