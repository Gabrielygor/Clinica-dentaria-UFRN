#include <stdio.h>      //Biblioteca 
#include <stdlib.h> 
#include "estoque.h"
#include "telas.h"


void estoque(void){
    char op;
    do{
        system("clear||cls");
        printf("=============\n");
        printf("\n");
        printf("   Estoque   \n");
        printf("\n");
        printf("=============\n");
        printf("\n");
        printf("|[1]. Adicionar Estoque\n");
        printf("|[2]. Excluir Estoque\n");
        printf("|[3]. Listar Estoque\n");
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();

        switch (op){
          case '1':
            adicionarestoque();
            break;
          case '2':
            excluirestoque();
            break;
          case '3':
            listarestoque();
            break;
          case '0':
            break;
          default:
            printf("Opção inválida! Tente novamente.\n");
            
            
        }

      }  while (op != '0');
}

void adicionarestoque(void){
    system("clear||cls");
    printf("Adicionar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluirestoque(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listarestoque(void){
    system("clear||cls");
    printf("Listar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}