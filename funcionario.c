#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "funcionario.h"
#include "telas.h"
#include "ulti.h"
#include <string.h>



void funcionario(void){
    char op; //Recebe o opcao para navegar entres os modulos de fun
    Funcionario* fun;

    do { //Faz um loop para o menu de funcionarios so aceitar opcoes validas
        system("clear||cls"); //Limpa a tela
        printf("===================================\n");
        printf("\n");
        printf("   Gerenciamento de Funcionarios   \n");
        printf("\n");
        printf("===================================\n");
        printf("\n");
        printf("|[1]. Cadastrar Funcionario\n");
        printf("|[2]. Pesquisar Funcionario\n");
        printf("|[3]. Atualizar Funcionario\n");
        printf("|[4]. Listar Funcionarios\n");
        printf("|[5]. Excluir Funcionario\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %c", &op); //Recebe a opcao desejada
        getchar();
    
        switch (op){ //Switch case para navegar entre os modulos de fun
          case '1':
              cadastrofuncionario();
              break; 
          case '2':
              pesquisafun();
              break;
          case '3':
              atualizafun();
              break;
          case '4':
              listafuncionarios();
              break;
          case '5':
              //listafun();
              break;
          case '0':
              break;
          default:
              printf("Opção inválida! Tente novamente.\n");
      }     
    } while (op != '0');
}

Funcionario* cadastrofuncionario(void) {
    Funcionario* fun;
    fun = (Funcionario*)malloc(sizeof(Funcionario));
    int valido = 0;
    int cpfDuplicado = 0;

    system("clear||cls");
    printf("===========================\n");
    printf("   Cadastro de Funcionario   \n");
    printf("===========================\n");

     do {
        printf("======\n");
        printf("Digite o CPF do funcionario(Apenas numeros): ");
        scanf("%s", fun->cpf);
        if (validaCPF(fun->cpf) && !verificaCPFDuplicad(fun->cpf)) {
            printf("CPF valido.\n");
            printf("=-=-=-=-=-=\n");
            valido = 1;
        } else if (verificaCPFDuplicad(fun->cpf)) {
            printf("CPF ja cadastrado.\n");
        } else {
            printf("CPF invalido.\n");
        }
    } while (!valido);
  
    valido = 0;
    do {
        printf("\n");
        printf("Digite o nome do funcionario (Sem espacos entre os nomes): ");
        scanf("%s", fun->nome);
        if (validarNome(fun->nome)) {
            printf("Nome valido.\n");
            printf("=-=-=-=-=-=-=\n");
            valido = 1;
        } else {
            printf("Nome invalido.\n");
        }
    } while (!valido);

    valido = 0;
    do {
        printf("\n");
        printf("Digite a data de nascimento do funcionario (DD/MM/AA, Ex: 12/12/12): ");
        scanf("%9s", fun->data);
        if (lerData(fun->data)) {
            printf("Data valida.\n");
            printf("=-=-=-=-=-=-=\n");
            valido = 1;
        } else {
            printf("Data invalida. \n");
        }
    } while (!valido);

    valido = 0;
    do {
        printf("\n");
        printf("Digite um numero de telefone (apenas números com o DD e com o 9 a mais): ");
        scanf("%s", fun->telefone);
        if (validaTele(fun->telefone)) {
            printf("Numero de telefone valido.\n");
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            valido = 1;
        } else {
            printf("Numero de telefone invalido.\n");
        }
    } while (!valido);

    fun->ativo = 1;

    saveFuncionario(fun);

    free(fun);

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

void listafuncionarios(void) {
    Funcionario funcionario;
    system("clear||cls");
    printf("============================\n");
    printf("    Lista de Funcionarios   \n");
    printf("============================\n");
    printf("\n");


    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (funcionario.ativo == 1) {
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("CPF: %s\n", funcionario.cpf);
            printf("Nome: %s\n", funcionario.nome);
            printf("Data de Nascimento: %s\n", funcionario.data);
            printf("Telefone: %s\n", funcionario.telefone);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }
    }

    fclose(file);

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

void saveFuncionario(Funcionario* fun) {
    FILE* file = fopen("funcionarios.dat", "ab");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(fun, sizeof(Funcionario), 1, file);

    fclose(file);
}


//Funcao feita com auxilio do chatgpt

int verificaCPFDuplicad(const char* cpf) {
    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0;
    }

    Funcionario funcionarioLido;

    while (fread(&funcionarioLido, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionarioLido.cpf, cpf) == 0) {
            fclose(file);
            return 1;
        }
    }

    fclose(file);

    return 0;
}