#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "agendamento.h"
#include "telas.h"
#include "ulti.h"



void agendamento(void){
    char op;
    do{
        system("clear||cls");
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
        scanf(" %c", &op);
        getchar();
      
        switch (op){
          case '1':
            agendarconsulta();
            break;
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

void agendarconsulta(void){
    struct agendamento Agendamento;
    int valido = 0;

    system("clear||cls");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("   Agendamento de consulta   \n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-==-=-=\n");
    printf("\n");

    printf("Digite o CPF do cliente para a consulta:\n");
    printf("Digite o funcionário responsavel pela consulta:\n");

  
    valido = 0;  
    do {
      printf("\n");
      printf("======\n");
      printf("Digite a data da consulta(DD/MM/AA):");
      scanf("%9s",  Agendamento.data);
  
      if (lerData (Agendamento.data)) {
        printf("Data válida.\n");       
        printf("=-=-=-=-=-=-=\n");
        valido = 1;
      } else {
        printf("Data inválida. Tente novamente.\n");
      }
    } while (!valido);
  
    valido = 0;
    do{
      printf("\n");
      printf("======\n");
      printf("Digite o horario da consulta (HH:MM):");
      scanf("%5s",  Agendamento.hora);

      if(lerHora(Agendamento.hora)) {
        printf("Hora válida.\n");
        printf("=-=-=-=-=-=-=\n");
        valido = 1;
      }else {
        printf("Hora inválida. Tente novamente.\n");
      }
    }while (!valido);

    printf("\n");
    printf("=================================\n"); //Funcao que exibe as informacoes/dados dos pacientes
    printf("\n");
    printf("   Informações do Agendamento   \n");
    printf("\n");
    printf("=================================\n");
    printf("|Data da consulta: %s\n", Agendamento.data);
    printf("|Hora da consulta: %s\n", Agendamento.hora);
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