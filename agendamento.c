#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "agendamento.h"
#include "telas.h"
#include "ulti.h"



void agendamento(void){
    char op; //Variavel de op(opcao) para navegar entre os modulos de agendamento 
    Agendamento * age;

    do{ //Cria loop que se repete se a opcao for invalida
        system("clear||cls"); //limpa a tela
        printf("=================\n");
        printf("\n");
        printf("   Agendamento   \n");
        printf("\n");
        printf("=================\n");
        printf("\n");
        printf("|[1]. Agendar Consulta\n");
        printf("|[2]. Agendar Retorno\n");
        printf("|[3]. Excluir Consultas\n");
        printf("|[4]. Excluir Retorno\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op); //Recebe a opcao desejada
        getchar();
      
        switch (op){ //Switch case com as opcoes disponiveis para esse modulo
          case '1':
            agendarconsulta();
            break; //Break funcao que para o programa quando entrar no modulo agendar consulta
          case '2':
            agendarretorno();
            break;
          case '3':
            excluirconsulta();
            break;
          case '4':
            excluirretorno();
            break;
          case '0':
            break;
          default:
            printf("Opção inválida! Tente novamente.\n");
            }
      } while (op != '0');
}  

Agendamento* agendarconsulta(void){
    Agendamento *age;
    age = (Agendamento*)malloc(sizeof(Agendamento));
    int valido = 0; //Variavel para loop 

    system("clear||cls"); //Limpa a tela
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("   Agendamento de consulta   \n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("\n");

    printf("Digite o CPF do cliente para a consulta:\n");
    printf("Digite o funcionário responsavel pela consulta:\n");

  
    valido = 0; //Zera a variavel para repetir o loop 
    do {
      printf("\n");
      printf("======\n");
      printf("Digite a data da consulta(DD/MM/AA):");
      scanf("%9s",  age->data); //Pergunta a data e salva na variavel data com o ponteira de Agendamento.data
  
      if (lerData (age->data)) { //Valida se e uma data valida
        printf("Data válida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1; //Se a data for valida muda a variavel de controle para 1 e encerra o loop 
      } else { //Se nao continua no loop ate que a opcao seja valida
        printf("Data inválida. Tente novamente.\n");
      }
    } while (!valido); 
  
    valido = 0; //Zera a variavel novamente para repetir o processo "denovo"
    do{
      printf("\n");
      printf("======\n");
      printf("Digite o horario da consulta (HH:MM):");
      scanf("%5s",  age->hora); //Pergunta e salva na variavel hora

      if(lerHora(age->hora)) { // Valida se e uma hora valida
        printf("Hora válida.\n");
        printf("=-=-=-=-=-=-=\n");
        valido = 1; //Sai do loop se a hora for valida
      }else { //Se nao continua no loop ate q a opcao seja valida
        printf("Hora inválida. Tente novamente.\n");
      }
    }while (!valido);

    printf("\n");
    printf("=================================\n"); //Funcao que exibe as informacoes/dados da consulta
    printf("\n");
    printf("   Informações do Agendamento   \n");
    printf("\n");
    printf("=================================\n");
    printf("|Data da consulta: %s\n",age->data); //Exibe a data guardada na variavel
    printf("|Hora da consulta: %s\n",age->hora); //Exibe a hora guardada na variavel
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
  
    printf("\n");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continua...\n");
    getchar();

}
void agendarretorno(void){
    system("clear||cls");
    printf("Digite o CPF do cliente:\n");
    printf("Digite a data do retorno:\n");
    printf("Digite o horário do retorno:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void excluirconsulta(void){
    system("clear||cls");
    printf("Digite o CPF do cliente para excluir uma consulta:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void excluirretorno(void){
    system("clear||cls");
    printf("Digite o CPF do cliente para excluir o retorno:\n");
    printf("\n");
    printf("EM CONSTRUÇÃO...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}