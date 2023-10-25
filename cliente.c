#include <stdio.h>      //Biblioteca prontas da linguagem C 
#include <stdlib.h> 
#include "cliente.h"    //Bibliotecas/funcoes criadas por min e icluidas usando aspas " "
#include "telas.h"
#include "ulti.h"



void cliente(void) {
    char op;
    Cliente* cli;


    do { // Loop para o menu de Clientes se repetir                                                           
        system("clear||cls"); //Limpa a tela 
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
        scanf(" %c", &op); //Recebe a opcao desejada
        getchar();

        switch (op) { //Switch case para opcoes disponiveis no modulo de clientes
            case '1':
                cadastrocliente();
                break;
            case '2':
                pesquisacliente(cli);
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

Cliente* cadastrocliente(void){
    Cliente *cli;
    cli = (Cliente*)malloc(sizeof(Cliente));
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
      scanf("%s",  cli->cpf); //Recebe a variavel cpf   //Antes da struct == cpf dps ficou ficou Clinete.cpf
      if (validaCPF( cli->cpf)) { //Funcao que valida o cpf
          printf("CPF válido.\n");
          printf("=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o cpf for valido 
      } else { //Se nao repete ate o cpf se validado
          printf("CPF inválido.\n");
      }
    } while (!valido); // continua no loop se o cpf for valido

    valido = 0; // Zera a variavel "valido" para que seja possivel repetir o mesmo processo acima 
    do {
      printf("\n");
      printf("=======\n");
      printf("Digite o nome do paciente(Sem espaço entre os nomes): ");
      scanf("%s",  cli->nome); //Recebe o nome do cliente
      if (validarNome( cli->nome)) { //Valida o nome do cliente
          printf("Nome válido.\n");
          printf("=-=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o nome for valido 
      } else { //Se nao repete ate o nome ser validado
          printf("Nome inválido.\n");  
      }
    } while (!valido);

    valido = 0; //Zera a variavel novamente
    do { //Cria o laco
      printf("\n");
      printf("======\n");
      printf("Digite a data de nascimento do cliente DD/MM/AAAA:");
      scanf("%9s",  cli->data); //Rece a variavel data

      if (lerData (cli->data)) { //Valida a data
        printf("Data válida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1; //Sai do loop se a data for valida
      } else { //Se nao repete o loop 
        printf("Data inválida. Tente novamente.\n");
      }
    } while (!valido);

    valido = 0; //Zera denovo kkkkkk
    do { //Cria loop novamente kk
      printf("\n");
      printf("======\n");
      printf("Digite um número de telefone (apenas números com o DD e com o 9 a mais): ");
      scanf("%s", cli->telefone); //Recebe a variavel de telefone
  
      if (validaTele(cli->telefone)) { //Valida o telefone
          printf("Número válido.\n");
          printf("=-=-=-=-=-=-=-=\n");
          valido = 1; //Se o telefone for valido sai do krai do loop 
      } else { //Se nao repete ate o telefone ser validado 
          printf("Número inválido.\n");
      }
    } while (!valido);


    
    printf("\n");
    printf("=============================\n"); //Funcao que exibe as informacoes/dados dos pacientes
    printf("\n");
    printf("   Informações do Paciente   \n");
    printf("\n");
    printf("=============================\n");
    printf("|CPF: %s\n", cli->cpf);  //Da printf na string guardada na variavel CPF
    printf("|Nome: %s\n", cli->nome); //Exibe o nome
    printf("|Data de nascimento: %s\n", cli->data); //Exibe a data
    printf("|Telefone: %s\n", cli->telefone); //Exibe o telefone
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();

}

void pesquisacliente(const Cliente* cli){
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

