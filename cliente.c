#include <stdio.h>      //Biblioteca prontas da linguagem C 
#include <stdlib.h> 
#include "cliente.h"    //Bibliotecas/funcoes criadas por min e icluidas usando aspas " "
#include "telas.h"
#include "ulti.h"
#include <string.h>



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
        printf("|Escolha a opcao desejada: ");
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
          printf("CPF valido.\n");
          printf("=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o cpf for valido 
      } else { //Se nao repete ate o cpf se validado
          printf("CPF invalido.\n");
      }
    } while (!valido); // continua no loop se o cpf for valido

    valido = 0; // Zera a variavel "valido" para que seja possivel repetir o mesmo processo acima 
    do {
      printf("\n");
      printf("=======\n");
      printf("Digite o nome do paciente(Sem espaco entre os nomes): ");
      scanf("%s",  cli->nome); //Recebe o nome do cliente
      if (validarNome( cli->nome)) { //Valida o nome do cliente
          printf("Nome valido.\n");
          printf("=-=-=-=-=-=-=\n");
          valido = 1; //Sai do loop se o nome for valido 
      } else { //Se nao repete ate o nome ser validado
          printf("Nome invalido.\n");  
      }
    } while (!valido);

    valido = 0; //Zera a variavel novamente
    do { //Cria o laco
      printf("\n");
      printf("======\n");
      printf("Digite a data de nascimento do cliente DD/MM/AA (EX 12/12/12):");
      scanf("%9s",  cli->data); //Rece a variavel data

      if (lerData (cli->data)) { //Valida a data
        printf("Data valida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1; //Sai do loop se a data for valida
      } else { //Se nao repete o loop 
        printf("Data invalida. Tente novamente.\n");
      }
    } while (!valido);

    valido = 0; //Zera denovo kkkkkk
    do { //Cria loop novamente kk
      printf("\n");
      printf("======\n");
      printf("Digite um numero de telefone (apenas numeros com o DD e com o 9 a mais): ");
      scanf("%s", cli->telefone); //Recebe a variavel de telefone
  
      if (validaTele(cli->telefone)) { //Valida o telefone
          printf("Numero valido.\n");
          printf("=-=-=-=-=-=-=-=\n");
          valido = 1; //Se o telefone for valido sai do krai do loop 
      } else { //Se nao repete ate o telefone ser validado 
          printf("Numero invalido.\n");
      }
    } while (!valido);

    saveCliente(cli);

    free(cli);

    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();

}

void pesquisacliente(const Cliente* cli) {
    char cpf[12];
  
    system("clear||cls");
    printf("Informe o CPF do paciente:");
    printf("\n");

    scanf("%s", cpf);

    // Abrir o arquivo de clientes para leitura
    FILE* file = fopen("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    // Loop para buscar o cliente com o CPF fornecido
    Cliente clienteEncontrado;
    int clienteEncontradoFlag = 0;

    while (fread(&clienteEncontrado, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(clienteEncontrado.cpf, cpf) == 0) {
            // Cliente encontrado, exibir informações

            printf("==============\n");
            printf("   Paciente   \n");
            printf("===============\n");
            printf("\n");
            printf("|CPF: %s\n", clienteEncontrado.cpf);
            printf("|Nome: %s\n", clienteEncontrado.nome);
            printf("|Data de Nascimento: %s\n", clienteEncontrado.data);
            printf("|Telefone: %s\n" , clienteEncontrado.telefone);
            clienteEncontradoFlag = 1;
            break; // Não é necessário continuar a busca
        }
    }

    if (!clienteEncontradoFlag) {
        printf("Paciente com CPF %s não encontrado.\n", cpf);
    }

    // Fechar o arquivo
    fclose(file);

    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizacliente(void) {
    char cpf[12];   
    Cliente clienteAtualizado;
    int clienteEncontradoFlag = 0;
    system("clear||cls");

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("   Atualizar Paciente   \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("Digite o CPF do cliente para atualizar:\n");
    scanf("%s", cpf);

    FILE* file = fopen("clientes.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&clienteAtualizado, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(clienteAtualizado.cpf, cpf) == 0) {
            printf("Cliente encontrado.\n");
            printf("\n");
            printf("Digite o CPF do paciente(Apenas numeros): ");
            scanf("%s", clienteAtualizado.cpf);
            printf("=-=-=-=-=\n");
            while (!validaCPF(clienteAtualizado.cpf)) {
                printf("CPF invalido, insira novamente abaixo: \n");
                scanf("%s", clienteAtualizado.cpf);  
                printf("=-=-=-=-=\n");
            }
            printf("Digite o nome do paciente(Sem espaco entre os nomes): ");
            scanf("%s", clienteAtualizado.nome);
            printf("=-=-=-=-=\n");
            while (!validarNome(clienteAtualizado.nome)) {
                printf("Nome invalido, insira novamente abaixo: ");
                scanf("%s", clienteAtualizado.nome);
                printf("=-=-=-=-=\n");
            }
            printf("Digite a data de nascimento do cliente DD/MM/AA (EX 12/12/12): ");
            scanf("%s", clienteAtualizado.data);
            printf("=-=-=-=-=\n");
            while (!lerData(clienteAtualizado.data)) {
                printf("Data invalida, insira novamente abaixo: ");
                scanf("%s", clienteAtualizado.data);
                printf("=-=-=-=-=\n");
            }
            printf("Digite um numero de telefone (apenas numeros com o DD e com o 9 a mais): ");
            scanf("%s", clienteAtualizado.telefone);
            printf("=-=-=-=-=\n");
            while (!validaTele(clienteAtualizado.telefone)) {
                printf("Telefone invalido, insira novamente abaixo: ");
                scanf("%s", clienteAtualizado.telefone);
                printf("=-=-=-=-=\n");
            }

            fseek(file, -sizeof(Cliente), SEEK_CUR);
            fwrite(&clienteAtualizado, sizeof(Cliente), 1, file);
            clienteEncontradoFlag = 1;
            break;
        }
    }

    if (!clienteEncontradoFlag) {
        printf("\n");
        printf("Cliente com CPF %s nao encontrado.\n", cpf);
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    } else {
        printf("\n");
        printf("Cliente atualizado com sucesso.\n");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
        getchar();
    }
    fclose(file);
    getchar();
}

void listacliente(void) {
    Cliente cliente;
    system("clear||cls");
    printf("Lista de Clientes cadastrados no sistema:\n\n");

    FILE* file = fopen("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("CPF: %s\n", cliente.cpf);
        printf("Nome: %s\n", cliente.nome);
        printf("Data de Nascimento: %s\n", cliente.data);
        printf("Telefone: %s\n", cliente.telefone);
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }

    fclose(file);

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

void saveCliente(Cliente* cli) {
    FILE* file = fopen("clientes.dat", "ab");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(cli, sizeof(Cliente), 1, file);

    fclose(file);
}