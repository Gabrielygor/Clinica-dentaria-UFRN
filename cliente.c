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

#include <stdio.h>      //Biblioteca prontas da linguagem C 
#include <stdlib.h> 
#include "cliente.h"    //Bibliotecas/funcoes criadas por min e icluidas usando aspas " "
#include "telas.h"
#include "ulti.h"
#include <string.h>

//

void cliente(void) {
    char op;
    //Cliente* cli;


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
        printf("|[4]. Relatorio de pacientes\n");
        printf("|[5]. Excluir paciente\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %s", &op); //Recebe a opcao desejada
        getchar();

        switch (op) { //Switch case para opcoes disponiveis no modulo de clientes
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
                relatorioCli();
                break;
            case '5':
                excluircliente();
                break;
            case '0':
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (op != '0'); // Sai do loop e volta para o menu principal caso a opcção = 0
}

Cliente* cadastrocliente(void){
    Cliente *cli; //Apontador para a estrutura cliente
    cli = (Cliente*)malloc(sizeof(Cliente)); //Aloca memoria para a estrutura cliente
    int valido = 0;  // Variavel para controle de loop
    int cpfDuplicado = 0;  //Variavel de cpf duplicado

    system("clear||cls");
    printf("==========================\n");
    printf("\n");
    printf("   Cadastro de Pacientes   \n");
    printf("\n");
    printf("==========================\n");

    do {
        printf("======\n");
        printf("Digite o CPF do paciente (Apenas numeros): ");
        scanf("%s", cli->cpf);  //Recebe o CPF do paciente
        cpfDuplicado = verificaCPFDuplicado(cli->cpf);  //Verifica se o cpf e duplicado
        if (cpfDuplicado) {  //Se for duplicado da erro
            printf("CPF ja cadastrado.\n");
            printf("=-=-=-=-=-=-=-=\n");
        } else if (validaCPF(cli->cpf)) {  //Se nao for duplicado e for valido == Cpf valido
            printf("CPF valido.\n");
            printf("=-=-=-=-=-=-=-=\n");
            valido = 1;
        } else {
            printf("CPF invalido.\n");
        }
    } while (!valido || cpfDuplicado);  //Enquanto nao for valido e n duplicado continua no loop 

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

    cli->ativo = 1; // define o cliente como ativo 1 Ativo e 0 = Inativo

    saveCliente(cli); //Chama a funcao que salva os clientes 

    free(cli); // Libera a memoria armazenada para a Struct Clientes

    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();
    return cli;
}

void pesquisacliente(void) {
    char cpf[12];  //Variavel para buscar o paciente
    Cliente clienteEncontrado;  //Armazena os dados do paciente encontrado 
    int clienteEncontradoFlag = 0;  //Flag de rastreamento de paciente 
  
    system("clear||cls"); //Limpa a tela 
    printf("=========================\n");
    printf("   Pesquisar Pacientes   \n");
    printf("=========================\n");
    printf("\n");
    printf("Informe o CPF do paciente:");
    scanf("%s", cpf);  //Pergunta o cpf do paciente
    printf("\n");

    FILE* file = fopen("clientes.dat", "rb");  //Abre o arquivo (rb == modo leitura)

    if (file == NULL) {  //Se o arquivo for NULL da erro na arbetura
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    while (fread(&clienteEncontrado, sizeof(Cliente), 1, file) == 1) {  //Le os paciente cadastrados no sistema 
        if (strcmp(clienteEncontrado.cpf, cpf) == 0) {  // Confere se o cpf e igual
            if (clienteEncontrado.ativo == 1) {  // Confere se o paciente ta ativo

            printf("\n");
            printf("|CPF: %s\n", clienteEncontrado.cpf);  //Printa as informacoes do paciente encontrado 
            printf("|Nome: %s\n", clienteEncontrado.nome);
            printf("|Data de Nascimento: %s\n", clienteEncontrado.data);
            printf("|Telefone: %s\n" , clienteEncontrado.telefone);
            printf("\n");
            printf("=-=-=-=-=\n");
            clienteEncontradoFlag = 1;  //Flag q sai do loop (Parecido com oq fiz na funcao de cadastro)
            break; // Não é necessário continuar a busca
            }
        }
    }

    if (!clienteEncontradoFlag) {  // Se o cpf nao estiver no arquivo da erro
        printf("Paciente com CPF %s nao encontrado.\n", cpf);
        printf("=-=-=-=-=\n");
    }

    fclose(file);  //Fecha o arquivo 

    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void atualizacliente(void) {
    char cpf[12];  //Variavel para buscar o paciente
    Cliente clienteAtualizado;  // Estrutura que guarda o cliente atualizado 
    int clienteEncontradoFlag = 0;  //Flag que controla o loop

    system("clear||cls");
    printf("========================\n");
    printf("   Atualizar Paciente   \n");
    printf("========================\n");
    printf("\n");
    printf("Digite o CPF do cliente para atualizar:");
    scanf("%s", cpf);  // Recebe a variavel cpf para busca 

    FILE* file = fopen("clientes.dat", "rb+");  // Abre o arquivo (rb+ == modo de leitura e escrita)

    if (file == NULL) {  // Se o arquivo for NULL da erro 
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&clienteAtualizado, sizeof(Cliente), 1, file) == 1) {  //Le o arquivo de pacientes 
        if (strcmp(clienteAtualizado.cpf, cpf) == 0) {  //Confere se o cpf existe no arquivo 
            if (clienteAtualizado.ativo == 1) {  // Confere se a variavel ativo e igual a 1 (1 == paciente ativo)
            printf("\n");    
            printf("Cliente encontrado.\n");
            printf("\n");
            printf("Digite o CPF do paciente(Apenas numeros): ");
            scanf("%s", clienteAtualizado.cpf);  //Recebe o novo cpf do paciente 
            printf("=-=-=-=-=");
            while (!validaCPF(clienteAtualizado.cpf)) {  //Manda o cpf para o validador de cpf
                printf("\n");
                printf("CPF invalido, insira novamente:");  //Se o cpf for invalido pergunta o cpf novamente 
                scanf("%s", clienteAtualizado.cpf);   
                printf("=-=-=-=-=\n");

            }
            printf("\n");  //Repete o mesmo processo acima soq com a variavel nome 
            printf("Digite o nome do paciente(Sem espaco entre os nomes): ");
            scanf("%s", clienteAtualizado.nome);
            printf("=-=-=-=-=\n");
            while (!validarNome(clienteAtualizado.nome)) {
                printf("\n");
                printf("Nome invalido, insira novamente: ");
                scanf("%s", clienteAtualizado.nome);
                printf("=-=-=-=-=\n");
            }

            printf("\n");
            printf("Digite a data de nascimento do cliente DD/MM/AA (EX 12/12/12): ");
            scanf("%s", clienteAtualizado.data);
            printf("=-=-=-=-=\n");
            while (!lerData(clienteAtualizado.data)) {
                printf("\n");
                printf("Data invalida, insira novamente: ");
                scanf("%s", clienteAtualizado.data);
                printf("=-=-=-=-=\n");
            }

            printf("\n");
            printf("Digite um numero de telefone (apenas numeros com o DD e com o 9 a mais): ");
            scanf("%s", clienteAtualizado.telefone);
            printf("=-=-=-=-=\n");
            while (!validaTele(clienteAtualizado.telefone)) {
                printf("\n");
                printf("Telefone invalido, insira novamente: ");
                scanf("%s", clienteAtualizado.telefone);
                printf("=-=-=-=-=\n");
            }

            fseek(file, -sizeof(Cliente), SEEK_CUR);  //Volta o ponteiro para o paciente certo 
            fwrite(&clienteAtualizado, sizeof(Cliente), 1, file);  // Escreve os novos dados do paciente 
            clienteEncontradoFlag = 1;  //Flag q sai do loop 
            break;
            }
        }
    }

    if (!clienteEncontradoFlag) { //Se a flag nao for encontrada da print na msg de erro 
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
    fclose(file);  //Fecha o arquivo 
    getchar();
}


// Exclusao LOGICA do paciente
void excluircliente(void) {
    int clienteEncontradoFlag = 0;  //Flag de controle de loop 
    Cliente cliente;  //Estrutura para salvar os dados 
    char cpf[12];  //Variavel que le o cpf
    system("clear||cls");
    printf("=======================\n");
    printf("   Excluir Paciente   \n");
    printf("=======================\n");
    printf("\n");

    printf("Digite o CPF do paciente que deseja excluir: ");
    scanf("%s", cpf);  //Le o cpf

    FILE* file = fopen("clientes.dat", "rb+");  //Abre o arquivo no mode de leitura e escrita (rb+)

    if (file == NULL) {  //Da erro se o arquivo for NULL
        printf("Erro ao abrir o arquivo para leitura e escrita.\n");
        return;
    }

    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {  //Le o aruivo 
        if (strcmp(cliente.cpf, cpf) == 0) {  //Confere se o cpf de entrada e igual 
            cliente.ativo = 0; // Marca o cliente como inativo (==0)
            fseek(file, -sizeof(Cliente), SEEK_CUR);  //Volta o apontador para o paciente certo 
            fwrite(&cliente, sizeof(Cliente), 1, file);  //Escreve a mudanca no arquivo (de 1 para 0)
            clienteEncontradoFlag = 1; //Flag que sai do loop 
            break;
        }
    }

    if (!clienteEncontradoFlag) {  //Print de paciente nao encontrado 
        printf("\n");
        printf("Paciente com CPF %s nao encontrado.\n", cpf);
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    } else {
        printf("\n");
        printf("Paciente excluido LOGICAMENTE com sucesso.\n");
        getchar();
        printf("\n");
        printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    }

    fclose(file);

    getchar();
}

void saveCliente(Cliente* cli) {  
    FILE* file = fopen("clientes.dat", "ab");  //Abre e cria o arquivo (Cliente.dat) em modo de escrita 

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return;
    }

    fwrite(cli, sizeof(Cliente), 1, file);  //Escreve as informacoes do paciente

    fclose(file);  //Fecha o arquivo
}

// Funcao feita com auxilio do ChatGpt

int verificaCPFDuplicado(const char* cpf) {
    // Abre o arquivo de clientes para leitura
    FILE* file = fopen("clientes.dat", "rb");

    if (file == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 0; // Retorna 0 para falso (CPF não duplicado)
    }

    Cliente clienteLido;

    while (fread(&clienteLido, sizeof(Cliente), 1, file) == 1) {
        if (strcmp(clienteLido.cpf, cpf) == 0) {
            // CPF já cadastrado
            fclose(file);
            return 1; // Retorna 1 para verdadeiro (CPF duplicado)
        }
    }

    // Fecha o arquivo
    fclose(file);

    return 0; // Retorna 0 para falso (CPF não duplicado)
}

void listaclienteAtivo(void) {
    Cliente cliente;  //Estrutura para armazenar os dados 
    system("clear||cls");
    printf("=========================\n");
    printf("    Lista de Pacientes   \n");
    printf("=========================\n");
    printf("\n");

    cabecalhoCli();

    FILE* file = fopen("clientes.dat", "rb");  //Abre o arquivo no modo de leitura

    if (file == NULL) {  //Se o arquivo for NULL da erro 
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    //LOOP que so para quanto tds os apcientes ativos forem printados 
    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {  //Le os pacientes cadastrados no sistema 
        if (cliente.ativo == 1) {  //Verifica se o paciente esta ativo
        exibeCliente(&cliente);
        }
    }

    fclose(file);  //Fecha o arquivo

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaALLcliente(void) {
    Cliente cliente;  //Estrutura para armazenar os dados 
    system("clear||cls");
    printf("=========================\n");
    printf("    Lista de Pacientes   \n");
    printf("=========================\n");
    printf("\n");

    cabecalhoCli();

    FILE* file = fopen("clientes.dat", "rb");  //Abre o arquivo no modo de leitura

    if (file == NULL) {  //Se o arquivo for NULL da erro 
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    //LOOP que so para quanto tds os apcientes ativos forem printados 
    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {  //Le os pacientes cadastrados no sistema 
        exibeCliente(&cliente);
    }

    fclose(file);  //Fecha o arquivo

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void listaclienteInativo(void) {
    Cliente cliente;  //Estrutura para armazenar os dados 
    system("clear||cls");
    printf("=========================\n");
    printf("    Lista de Pacientes   \n");
    printf("=========================\n");
    printf("\n");

    cabecalhoCli();

    FILE* file = fopen("clientes.dat", "rb");  //Abre o arquivo no modo de leitura

    if (file == NULL) {  //Se o arquivo for NULL da erro 
        printf("Erro ao abrir o arquivo para leitura.\n");
        return;
    }

    //LOOP que so para quanto tds os apcientes ativos forem printados 
    while (fread(&cliente, sizeof(Cliente), 1, file) == 1) {  //Le os pacientes cadastrados no sistema 
        if (cliente.ativo == 0) {  //Verifica se o paciente esta ativo
        exibeCliente(&cliente);
        }
    }

    fclose(file);  //Fecha o arquivo

    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void relatorioCli (void){
    char op1;

    do { // Loop para o menu de Clientes se repetir                                                           
        system("clear||cls"); //Limpa a tela 
        printf("============================\n");
        printf("\n");
        printf("   Relatorio de Pacientes   \n");
        printf("\n");
        printf("============================\n");
        printf("\n");
        printf("|[1]. Listar todos os Pacientes\n");
        printf("|[2]. Listar Pacientes Ativos\n");
        printf("|[3]. Listar Pacientes Inativos\n");
        printf("|[4]. Listar em ordem Alfabetica\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opcao desejada: ");
        scanf(" %s", &op1); //Recebe a opcao desejada
        getchar();

        switch (op1) { //Switch case para opcoes disponiveis no modulo de clientes
            case '1':
                listaALLcliente();
                break;
            case '2':
                  listaclienteAtivo();
                break;
            case '3':
                  listaclienteInativo();
                break;
            case '4':
                  ListaAlfaCli();
                break;
            case '0':
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    } while (op1 != '0'); // Sai do loop e volta para o menu principal caso a opcção = 0
}

void cabecalhoCli(void){
  printf("+----------------------+----------------------+----------------------+----------------------+\n");
  printf("| CPF:                 | Nome:                | Data de Nascimento:  | Telefone:            |\n");
}

void exibeCliente(Cliente *cli){
  
  printf("+----------------------+----------------------+----------------------+----------------------+\n");
  printf("  %-20s   %-20s   %-20s   %-20s  \n", cli->cpf, cli->nome, cli->data, cli->telefone);
  printf("+----------------------+----------------------+----------------------+----------------------+\n");
}

void ListaAlfaCli(void) {
    system("clear||cls");
    FILE* file;
    Cliente* novocli;  //Apontador para estrutura de clientes
    Cliente* lista;  //Apontador para a variavel de lista (para fazer a lista encadeiada)

    file = fopen("clientes.dat", "rb");  //Abre o arquivo que contem os dados dos clientes
    if (file == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);  //Encerra o programa 
    }

    printf("================================\n");
    printf("   Relatorio Ordem Alfabetica\n");
    printf("================================\n");
    printf("\n");

    cabecalhoCli();

    lista = NULL;  //Define a lista como NULL (Lista vazia)
    novocli = (Cliente*)malloc(sizeof(Cliente)); // Aloca memoria para a estrutura novocli com o tamanho de um Cliente

    if (novocli == NULL) {  //Se nao consegui alocar da erro 
        printf("Erro de alocacao de memoria\n");
        exit(1);  //Sai do programa 
    }

    while (fread(novocli, sizeof(Cliente), 1, file) == 1) {  //Loop para ler enquato existir
        novocli->prox = NULL;  //Aponta o ponteiro para NULL

        if ((lista == NULL) || (strcmp(novocli->nome, lista->nome) < 0)) {  //Se a lista for vazia 
            novocli->prox = lista;  //Atualiza o ponteiro 'prox' do novo cliente para apontar para o início da lista
            lista = novocli;  // Atualiza a inicio da lista para apontar para o novo cliente
        } else {  
            Cliente* ant = lista;  // Ponteiro para o cliente anterior na lista
            Cliente* atual = lista->prox;   // Ponteiro para o próximo cliente na lista
            while ((atual != NULL) && strcmp(atual->nome, novocli->nome) < 0) {   // Enquanto não chegamos ao final da lista e o novo cliente vem depois do cliente atual
                ant = atual;  // Atualiza o ponteiro para o cliente anterior
                atual = atual->prox; // Move para o próximo cliente na lista
            }
            ant->prox = novocli;  // Atualiza o ponteiro 'prox' do cliente anterior para apontar para o novo cliente
            novocli->prox = atual;  // Atualiza o ponteiro 'prox' do novo cliente para apontar para o cliente atual
        }

        novocli = (Cliente*)malloc(sizeof(Cliente));
        if (novocli == NULL) {
            printf("Erro de alocacao de memoria\n");
            exit(1);
        }
    }

    fclose(file);  //Fecha o arquivo 

    novocli = lista;  //Aponta para o proximo 
    while (novocli != NULL) {  //Enqunato for diferente de NULL
        exibeCliente(novocli);
        //printf("Tecle ENTER para ir para o proximo Paciente ou fechar a listagem\n");
        novocli = novocli->prox;   // Move para o próximo cliente na lista encadeada
    }

    novocli = lista;  // Atualiza o ponteiro 'novocli' para apontar para o início da lista
    while (lista != NULL) {
        lista = lista->prox;  // Move a lista para o próximo nó
        free(novocli); // Libera a memória alocada para o nó anterior da lista
        novocli = lista; // Atualiza 'novocli' para apontar para o próximo nó da lista
    }
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}