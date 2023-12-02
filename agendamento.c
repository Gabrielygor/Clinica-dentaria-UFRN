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

#include <stdio.h>      
#include <stdlib.h> 
#include "agendamento.h"
#include "telas.h"
#include "ulti.h"
#include "cliente.h"
#include "funcionario.h"
#include <string.h>



void agendamento(void){
    char op;
    //Agendamento * age;

    do{ 
        system("clear||cls"); 
        printf("=================\n");
        printf("\n");
        printf("   Agendamento   \n");
        printf("\n");
        printf("=================\n");
        printf("\n");
        printf("|[1]. Agendar Consulta\n");
        printf("|[2]. Excluir Consultas\n");
        printf("|[3]. Editar Consulta\n");
        printf("|[4]. Pesquisar Consultas po Paciente\n");
        printf("|[5]. Relatorio de Consultas\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %c", &op); 
        getchar();

        switch (op){
          case '1':
            agendarconsulta();
            break; 
          case '2':
            excluirconsulta();
            break;
          case '3':
            atualizaAgendamento();
            break;
          case '4':
            pesquisaConsultasCliente();
            break;
          case '5':
            relatorioAge();
            break;
          case '0':
            break;
          default:
            printf("Opcao invalida! Tente novamente.\n");
            }
      } while (op != '0');
}  

Agendamento* agendarconsulta(void){
    Agendamento *age;
    age = (Agendamento*)malloc(sizeof(Agendamento));
    int valido = 0; //Variavel para loop 

    system("clear||cls"); //Limpa a tela
    printf("=============================\n");
    printf("\n");
    printf("   Agendamento de consulta   \n");
    printf("\n");
    printf("=============================\n");
    printf("\n");

    do {
        printf("======\n");
        printf("|Digite o CPF do cliente para a consulta:");
        scanf("%s", age->cpf);
        getchar();

        // Recupere o nome do cliente usando a função getCli
        char *clienteNome = getCli(age->cpf);

        if (clienteNome != NULL) {
            printf("|\n");
            printf("|Cliente encontrado: %s\n", clienteNome);
            printf("=-=-=-=-=-=-=\n");
            free(clienteNome); // Libera a memória alocada para o nome do cliente
            valido = 1; // Sai do loop se o cliente for válido
        } else {
            printf("|\n");
            printf("|Cliente nao encontrado.\n");
            printf("=-=-=-=-=-=-=\n");
            }
    } while (!valido);

    valido = 0;
    do {
        printf("======\n");
        printf("|\n");
        printf("|Digite o CPF do funcionario responsavel pela consulta:");
        scanf("%s", age->cpff);
        getchar();

        // Recupere o nome do funcionário usando a função getFun
        char *funcionarioNome = getFun(age->cpff);

        if (funcionarioNome != NULL) {
            printf("|\n");
            printf("|Funcionario encontrado: %s\n", funcionarioNome);
            printf("=-=-=-=-=-=-=\n");
            free(funcionarioNome); // Libera a memória alocada para o nome do funcionário
            valido = 1; // Sai do loop se o funcionário for válido
        } else {
            printf("|\n");
            printf("|Funcionario nao encontrado.\n");
            printf("=-=-=-=-=-=-=\n");
        }
    } while (!valido);


    valido = 0; 
    do {
      printf("\n");
      printf("======\n");
      printf("|Digite a data da consulta(DD/MM/AA):");
      scanf("%9s",  age->data);

      if (lerData (age->data)) { 
        printf("|Data valida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1; 
      } else { 
        printf("|Data invalida. Tente novamente.\n");
      }
    } while (!valido); 

    age->ativo = 1;

    salvarAgendamento(age);

    free(age);

    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();
    return age;

}

void excluirconsulta(void){
    Agendamento age;
    char cpf_cliente[15];

    system("clear||cls");

    printf("===========================\n");
    printf("   Excluir de Agendamento  \n");
    printf("===========================\n");
    printf("\n");
    printf("Digite o CPF do cliente para excluir uma consulta: ");
    scanf("%s", cpf_cliente);

    FILE *file = fopen("agendamentos.dat", "r+b"); // Open for reading and writing

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos para leitura e escrita.\n");
        return;
    }

    int found = 0;

    while (fread(&age, sizeof(Agendamento), 1, file) == 1) {
        if (strcmp(age.cpf, cpf_cliente) == 0 && age.ativo == 1) {
            found = 1;
            age.ativo = 0; // Mark as inactive (logical deletion)
            fseek(file, -sizeof(Agendamento), SEEK_CUR); // Move file cursor back
            fwrite(&age, sizeof(Agendamento), 1, file); // Update the record
            printf("Consulta excluida com sucesso.\n");
            printf("\n");
            getchar();
            printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
            getchar();
            break;
        }
    }

    if (!found) {
        printf("Consulta nao encontrada.\n");
        printf("\n");
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
        getchar();
    }

    fclose(file);
}


char *getCli(const char *cpf) {
    Cliente cliente;
    FILE *file = fopen("clientes.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return NULL;
    }

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(cliente.cpf, cpf) == 0) {
            // CPF encontrado, aloca memória para o nome
            char *result = (char *)malloc(strlen(cliente.nome) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memoria.\n");
                fclose(file);
                return NULL;
            }

            // Copia o nome para o resultado e o retorna
            strcpy(result, cliente.nome);
            fclose(file);
            return result;
        }
    }

    // Se o CPF não for encontrado, retorna NULL
    fclose(file);
    return NULL;
}

//FUNCAO DESENVOLVIDA COM AUXILIO DO CHATGPT

char *getFun(const char *cpff) {
    Funcionario funcionario;
    FILE *file = fopen("funcionarios.dat", "rb"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de funcionarios para leitura.\n");
        return NULL;
    }

    while (fread(&funcionario, sizeof(Funcionario), 1, file) == 1) {
        if (strcmp(funcionario.cpf, cpff) == 0) {
            // CPF encontrado, aloca memória para o nome
            char *result = (char *)malloc(strlen(funcionario.nome) + 1);
            if (result == NULL) {
                printf("Erro ao alocar memoria.\n");
                fclose(file);
                return NULL;
            }

            // Copia o nome para o resultado e o retorna
            strcpy(result, funcionario.nome);
            fclose(file);
            return result;
        }
    }

    // Se o CPF não for encontrado, retorna NULL
    fclose(file);
    return NULL;
}

void salvarAgendamento(Agendamento *age) {
    FILE * file;

    file = fopen("agendamentos.dat", "ab");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(age, sizeof(Agendamento), 1, file);

    fclose(file);

}


void listaagendamentoAtivo(void) {
    system("clear||cls");
    FILE *file = fopen("agendamentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos para leitura.\n");
        return;
    }

    Agendamento age;

    printf("=================================\n");
    printf("   Lista de Agendamentos Ativos  \n");
    printf("=================================\n");
    printf("\n");

    cabecalhoAge();

    while (fread(&age, sizeof(Agendamento), 1, file) == 1) {
        if (age.ativo == 1) {
            exibeAgendamento(&age);
        }
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();
}

void listaagendamentoInativo(void) {
    system("clear||cls");
    FILE *file = fopen("agendamentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos para leitura.\n");
        return;
    }

    Agendamento age;

    printf("===================================\n");
    printf("   Lista de Agendamentos Inativos  \n");
    printf("===================================\n");
    printf("\n");

    cabecalhoAge();

    while (fread(&age, sizeof(Agendamento), 1, file) == 1) {
        if (age.ativo == 0) {
            exibeAgendamento(&age);
        }
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();
}

void listaALLagendamento(void) {
    system("clear||cls");
    FILE *file = fopen("agendamentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos para leitura.\n");
        return;
    }

    Agendamento age;

    printf("===========================\n");
    printf("   Lista de Agendamentos   \n");
    printf("===========================\n");
    printf("\n");

    cabecalhoAge();

    while (fread(&age, sizeof(Agendamento), 1, file) == 1) {
           exibeAgendamento(&age);
    }

    fclose(file);

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();
}


void relatorioAge(void){
    char op3;
    //Agendamento * age;

    do{ 
        system("clear||cls"); 
        printf("==============================\n");
        printf("\n");
        printf("  Relatorio de  Agendamento   \n");
        printf("\n");
        printf("==============================\n");
        printf("\n");
        printf("|[1]. Listar Todas as Consultas\n");
        printf("|[2]. Listar Consultas Ativas\n");
        printf("|[3]. Listar Consultas Inativas\n");
        printf("|[4]. Listar Consultas por Data\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %c", &op3); 
        getchar();

        switch (op3){
          case '1':
            listaALLagendamento();
            break; 
          case '2':
            listaagendamentoAtivo();
            break;
          case '3':
            listaagendamentoInativo();
            break;
          case '4':
            ListaAlfaData();
            break;
          case '0':
            break;
          default:
            printf("Opcao invalida! Tente novamente.\n");
            }
      } while (op3 != '0');
} 

void cabecalhoAge(void){
  printf("+---------------------+---------------------+------------------------+------------------------+------------------------+------------------------+\n");
  printf("| Data da Consulta:   | CPF do Cliente:     | Nome do Cliente:       | CPF do Funcionario:    |Nome do Funcionario:    |Status da Consulta:  |\n");
}

void exibeAgendamento(Agendamento *age){
  char * nomeclie;  
  char * nomefun;

  nomeclie = getCli(age->cpf);
  nomefun = getFun(age->cpff);

  printf("+---------------------+---------------------+------------------------+------------------------+------------------------+------------------------+\n");
  printf("  %-19s   %-19s   %-24s  %-23s  %-23s  %d\n", age->data, age->cpf, nomeclie, age->cpff, nomefun, age->ativo);
  printf("+---------------------+---------------------+------------------------+------------------------+------------------------+------------------------+\n");
    
}

void ListaAlfaData(void) {
    system("clear||cls");

    FILE* file;
    Agendamento* novoage;
    Agendamento* lista;

    file = fopen("agendamentos.dat", "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    printf("================================\n");
    printf("   Relatorio Ordem de Data\n");
    printf("================================\n");
    printf("\n");

    cabecalhoAge();

    lista = NULL;
    novoage = (Agendamento*)malloc(sizeof(Agendamento));

    if (novoage == NULL) {
        printf("Erro de alocacao de memoria\n");
        exit(1);
    }

    while (fread(novoage, sizeof(Agendamento), 1, file) == 1) {
        novoage->prox = NULL;

        if ((lista == NULL) || (strcmp(novoage->data, lista->data) < 0)) {
            novoage->prox = lista;
            lista = novoage;
        } else {
            Agendamento* ant = lista;
            Agendamento* atual = lista->prox;
            while ((atual != NULL) && strcmp(atual->data, novoage->data) < 0) {
                ant = atual;
                atual = atual->prox;
            }
            ant->prox = novoage;
            novoage->prox = atual;
        }

        novoage = (Agendamento*)malloc(sizeof(Agendamento));
        if (novoage == NULL) {
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    fclose(file);

    novoage = lista;
    while (novoage != NULL) {
        exibeAgendamento(novoage);
       // printf("Pressione ENTER para ir para o proximo Cliente ou fechar a listagem\n");
        getchar();
        novoage = novoage->prox;
    }

    novoage = lista;
    while (lista != NULL) {
        lista = lista->prox;
        free(novoage);
        novoage = lista;
    }
}


void atualizaAgendamento(void) {
    char cpf_cliente[15];
    Agendamento ageAtualizado;
    int agendamentoEncontradoFlag = 0;

    system("clear||cls");
    printf("=============================\n");
    printf("   Atualizar Agendamento   \n");
    printf("=============================\n");
    printf("\n");
    printf("Digite o CPF do cliente para atualizar um agendamento: ");
    scanf("%s", cpf_cliente);

    FILE* file = fopen("agendamentos.dat", "rb+");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&ageAtualizado, sizeof(Agendamento), 1, file) == 1) {
        if (strcmp(ageAtualizado.cpf, cpf_cliente) == 0 && ageAtualizado.ativo == 1) {
            printf("\n");
            printf("Agendamento encontrado.\n");
            printf("\n");

            printf("Digite a nova data da consulta (DD/MM/AA): ");
            scanf("%s", ageAtualizado.data);
             while (!lerData(ageAtualizado.data)) {
              printf("Data invalida. Digite novamente (DD/MM/AA): ");
              scanf("%s", ageAtualizado.data);
          }

           printf("Digite o novo CPF do funcionario: ");
            scanf("%s", ageAtualizado.cpff);
            while (!validaCPF(ageAtualizado.cpff)) {
              printf("CPF invalido. Digite novamente: ");
              scanf("%s", ageAtualizado.cpff);
            }

            fseek(file, -sizeof(Agendamento), SEEK_CUR);
            fwrite(&ageAtualizado, sizeof(Agendamento), 1, file);
            agendamentoEncontradoFlag = 1;
            printf("Agendamento atualizado com sucesso.\n");
            printf("\n");
            printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
            getchar();
            getchar();
            break;
        }
    }

    if (!agendamentoEncontradoFlag) {
        printf("Agendamento nao encontrado.\n");
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
        getchar();
        getchar();
    }

    fclose(file);
}

void pesquisaConsultasCliente(void) {
    char cpf[12];
    int consultasEncontradas = 0;

    system("clear||cls");
    printf("=============================\n");
    printf(" Pesquisar Consultas Cliente \n");
    printf("=============================\n");
    printf("\n");
    printf("Informe o CPF do cliente:");
    scanf("%s", cpf);
    printf("\n");

    FILE* file = fopen("agendamentos.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    Agendamento consultaEncontrada;

    printf("Consultas do Cliente com CPF %s:\n", cpf);
    printf("\n");

    cabecalhoAge();

    while (fread(&consultaEncontrada, sizeof(Agendamento), 1, file) == 1) {
        if (strcmp(consultaEncontrada.cpf, cpf) == 0 && consultaEncontrada.ativo == 1) {
            exibeAgendamento(&consultaEncontrada);
            consultasEncontradas++;
        }
    }

    if (consultasEncontradas == 0) {
        printf("Nenhuma consulta encontrada para o cliente com CPF %s.\n", cpf);
        printf("=-=-=-=-=\n");
    }

    fclose(file);

    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}