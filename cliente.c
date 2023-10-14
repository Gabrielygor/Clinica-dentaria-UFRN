#include <stdio.h>      //Biblioteca prontas da linguagem C 
#include <stdlib.h> 
#include "cliente.h"    //Bibliotecas/funcoes criadas por min e icluidas usando aspas " "
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
    struct cliente Cliente; //Struct que contem as informacoes de cadastro dos cliente "cliente = paciente"
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
      scanf("%s",  Cliente.cpf); //Recebe a variavel cpf   //Antes da struct == cpf dps ficou ficou Clinete.cpf
      if (validaCPF( Cliente.cpf)) { //Funcao que valida o cpf
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
      scanf("%s",  Cliente.nome); 
      if (validarNome( Cliente.nome)) {
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
      printf("======\n");
      printf("Digite a data de nascimento do cliente DD/MM/AAAA:");
      scanf("%9s",  Cliente.data);

      if (lerData (Cliente.data)) {
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
      scanf("%s", Cliente.telefone);
  
      if (validaTele(Cliente.telefone)) {
          printf("Número válido.\n");
          printf("=-=-=-=-=-=-=-=\n");
          valido = 1;
      } else {
          printf("Número inválido.\n");
      }
    } while (!valido);


    
    printf("\n");
    printf("=============================\n"); //Funcao que exibe as informacoes/dados dos pacientes
    printf("\n");
    printf("   Informações do Paciente   \n");
    printf("\n");
    printf("=============================\n");
    printf("|CPF: %s\n", Cliente.cpf);  //Da printf na string guardada na variavel CPF
    printf("|Nome: %s\n", Cliente.nome);
    printf("|Data de nascimento: %s\n", Cliente.data);
    printf("|Telefone: %s\n", Cliente.telefone);
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
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

