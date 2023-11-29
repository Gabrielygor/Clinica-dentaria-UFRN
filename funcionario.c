///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte (UFRN)          ///
///                 Centro de Ensino Superior do Seridó (CERES)             ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///             Projeto Sistema de Gestão para clinicas dentarias           ///
///                      Developed by @Gabrielygor                          ///
///////////////////////////////////////////////////////////////////////////////
///  Trabalho referente ao segundo semestre do ano de 2023 do curso de BSI  ///
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "funcionario.h"
#include "telas.h"
#include "ulti.h"
#include <string.h>



void funcionario(void){
    char op; //Recebe o opcao para navegar entres os modulos de fun
    //Funcionario* fun;

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
        printf("|[4]. Relatorio de Funcionarios\n");
        printf("|[5]. Excluir Funcionario\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %s", &op); //Recebe a opcao desejada
        getchar();
    
        switch (op){ //Switch case para navegar entre os modulos de fun
          case '1':
              cadastrofuncionario();
              break; 
          case '2':
              pesquisafuncionario();
              break;
          case '3':
              atualizafuncionario();
              break;
          case '4':
              relatorioFun();
              break;
          case '5':
              excluirfuncionario();
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
        printf("Digite um numero de telefone (apenas numeros com o DD e com o 9 a mais): ");
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
    return fun;
}

void pesquisafuncionario(void) {
    char cpf[12];
    Funcionario funcionarioEncontrado;
    int funcionarioEncontradoFlag = 0;

    system("clear||cls");
    printf("===========================\n");
    printf("   Pesquisar Funcionario   \n");
    printf("===========================\n");
    printf("\n");
    printf("Informe o CPF do funcionario:");
    scanf("%s", cpf);
    printf("\n");

    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionarioEncontrado, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionarioEncontrado.cpf, cpf) == 0) {
            if (funcionarioEncontrado.ativo == 1) {
                printf("\n");
                printf("|CPF: %s\n", funcionarioEncontrado.cpf);
                printf("|Nome: %s\n", funcionarioEncontrado.nome);
                printf("|Data de Nascimento: %s\n", funcionarioEncontrado.data);
                printf("|Telefone: %s\n", funcionarioEncontrado.telefone);
                printf("\n");
                printf("=-=-=-=-=\n");
                funcionarioEncontradoFlag = 1;
                break;
            }
        }
    }

    if (!funcionarioEncontradoFlag) {
        printf("Funcionario com CPF %s nao encontrado.\n", cpf);
        printf("=-=-=-=-=\n");
    }

    fclose(file);

    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizafuncionario(void) {
    char cpf[12];
    Funcionario funcionarioAtualizado;
    int funcionarioEncontradoFlag = 0;
    system("clear||cls");

    printf("===========================\n");
    printf("   Atualizar Funcionario   \n");
    printf("===========================\n");
    printf("\n");
    printf("Digite o CPF do funcionario para atualizar:\n");
    scanf("%s", cpf);

    FILE* file = fopen("funcionarios.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&funcionarioAtualizado, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionarioAtualizado.cpf, cpf) == 0) {
            if (funcionarioAtualizado.ativo == 1) {
                printf("Funcionario encontrado.\n");
                printf("\n");
                printf("Digite o CPF do funcionario (Apenas numeros): ");
                scanf("%s", funcionarioAtualizado.cpf);
                printf("=-=-=-=-=\n");
                while (!validaCPF(funcionarioAtualizado.cpf)) {
                    printf("CPF invalido, insira novamente abaixo: \n");
                    scanf("%s", funcionarioAtualizado.cpf);
                    printf("=-=-=-=-=\n");
                }
                printf("Digite o nome do funcionario (Sem espacos entre os nomes): ");
                scanf("%s", funcionarioAtualizado.nome);
                printf("=-=-=-=-=\n");
                while (!validarNome(funcionarioAtualizado.nome)) {
                    printf("Nome invalido, insira novamente abaixo: \n");
                    scanf("%s", funcionarioAtualizado.nome);
                    printf("=-=-=-=-=\n");
                }
                printf("Digite a data de nascimento do funcionario (DD/MM/AA, Ex: 12/12/12): ");
                scanf("%9s", funcionarioAtualizado.data);
                printf("=-=-=-=-=\n");
                while (!lerData(funcionarioAtualizado.data)) {
                    printf("Data invalida, insira novamente abaixo: \n");
                    scanf("%9s", funcionarioAtualizado.data);
                    printf("=-=-=-=-=\n");
                }
                printf("Digite um numero de telefone (apenas numeros com o DD e com o 9 a mais): ");
                scanf("%s", funcionarioAtualizado.telefone);
                printf("=-=-=-=-=\n");
                while (!validaTele(funcionarioAtualizado.telefone)) {
                    printf("Telefone invalido, insira novamente abaixo: \n");
                    scanf("%s", funcionarioAtualizado.telefone);
                    printf("=-=-=-=-=\n");
                }

                fseek(file, -sizeof(Funcionario), SEEK_CUR);
                fwrite(&funcionarioAtualizado, sizeof(Funcionario), 1, file);
                funcionarioEncontradoFlag = 1;
                break;
            }
        }
    }
}  



void excluirfuncionario(void) {
    int funcionarioEncontradoFlag = 0;
    Funcionario funcionario;
    char cpf[12];
    system("clear||cls");

    printf("=========================\n");
    printf("   Excluir Funcionario   \n");
    printf("=========================\n");
    printf("\n");

    printf("Digite o CPF do funcionario que deseja excluir: ");
    scanf("%s", cpf);

    FILE* file = fopen("funcionarios.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.cpf, cpf) == 0) {
            funcionario.ativo = 0; // Marca o funcionário como inativo
            fseek(file, -sizeof(Funcionario), SEEK_CUR);
            fwrite(&funcionario, sizeof(Funcionario), 1, file);
            funcionarioEncontradoFlag = 1;
            break;
        }
    }

    if (!funcionarioEncontradoFlag) {
        printf("\n");
        printf("Funcionario com CPF %s nao encontrado.\n", cpf);
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("\n");
        printf("Funcionario excluido LOGICAMENTE com sucesso.\n");
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    fclose(file);

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

void listafuncionariosAtivo(void) {
    Funcionario funcionario;
    system("clear||cls");
    printf("============================\n");
    printf("    Lista de Funcionarios   \n");
    printf("============================\n");
    printf("\n");

    cabecalhoFun();

    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (funcionario.ativo == 1) {
            exibeFuncionario(&funcionario);
        }
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listafuncionariosInativo(void) {
    Funcionario funcionario;
    system("clear||cls");
    printf("============================\n");
    printf("    Lista de Funcionarios   \n");
    printf("============================\n");
    printf("\n");

    cabecalhoFun();

    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (funcionario.ativo == 0) {
            exibeFuncionario(&funcionario);
        }
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaALLfuncionarios(void) {
    Funcionario funcionario;
    system("clear||cls");
    printf("============================\n");
    printf("    Lista de Funcionarios   \n");
    printf("============================\n");
    printf("\n");

    cabecalhoFun();

    FILE* file = fopen("funcionarios.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
            exibeFuncionario(&funcionario);
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioFun(void){
    char op2; //Recebe o opcao para navegar entres os modulos de fun
    //Funcionario* fun;

    do { //Faz um loop para o menu de funcionarios so aceitar opcoes validas
        system("clear||cls"); //Limpa a tela
        printf("===============================\n");
        printf("\n");
        printf("   Relatorio de Funcionarios   \n");
        printf("\n");
        printf("===============================\n");
        printf("\n");
        printf("|[1]. Listar Todos os Funcionarios\n");
        printf("|[2]. Listar Funcionario Ativos\n");
        printf("|[3]. Listar Funcionario Inativos\n");
        printf("|[4]. Listar em Ordem Alfabetica\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %s", &op2); //Recebe a opcao desejada
        getchar();
    
        switch (op2){ //Switch case para navegar entre os modulos de fun
          case '1':
              listaALLfuncionarios();
              break; 
          case '2':
              listafuncionariosAtivo();
              break;
          case '3':
              listafuncionariosInativo();
              break;
          case '4':
              ListaAlfaFun();
              break;
          case '0':
              break;
          default:
              printf("Opção inválida! Tente novamente.\n");
      }     
    } while (op2 != '0');
}

void cabecalhoFun(void){
  printf("+------------------------+----------------------+----------------------+------------------------+\n");
  printf("| Nome:                  | CPF:                 | Telefone:            | Data de Nascimento:    |\n");
  
}

void exibeFuncionario(Funcionario *fun){
  printf("+------------------------+----------------------+----------------------+------------------------+\n");
  printf("  %-22s   %-19s    %-20s   %-22s \n", fun->nome, fun->cpf, fun->telefone, fun->data);
  printf("+------------------------+----------------------+----------------------+------------------------+\n");
  
}

void ListaAlfaFun(){
    system("clear||cls");
    FILE* file;
    Funcionario* novofun;  
    Funcionario* lista;  


    file = fopen("funcionarios.dat", "rb"); 
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);  
    }

    printf("================================\n");
    printf("   Relatorio Ordem Alfabetica\n");
    printf("================================\n");
    printf("\n");

    cabecalhoFun();

    lista = NULL; 
    novofun = (Funcionario*)malloc(sizeof(Funcionario));

    if (novofun == NULL) {  
        printf("Erro de alocação de memória\n");
        exit(1); 
      }

    while (fread(novofun, sizeof(Funcionario), 1, file) == 1) {  
      novofun->prox = NULL;  

      if ((lista == NULL) || (strcmp(novofun->nome, lista->nome) < 0)) {  
          novofun->prox = lista;  
          lista = novofun;  
      } else {  
          Funcionario* ant = lista;  
          Funcionario* atual = lista->prox;
          while ((atual != NULL) && strcmp(atual->nome, novofun->nome) < 0) {   
              ant = atual;  
              atual = atual->prox; 
          }
          ant->prox = novofun;  
          novofun->prox = atual; 
      }

      novofun = (Funcionario*)malloc(sizeof(Funcionario));
      if (novofun == NULL) {
          printf("Erro de alocação de memória\n");
          exit(1);
      }
    }

    fclose(file);

    novofun = lista; 
    while (novofun != NULL) {  
        exibeFuncionario(novofun);
        //printf("Tecle ENTER para ir para o proximo Paciente ou fechar a listagem\n");
        getchar();
        novofun = novofun->prox;  
    }

    novofun = lista;  
    while (lista != NULL) {
        lista = lista->prox;  
        free(novofun); 
        novofun = lista; 
    }
}