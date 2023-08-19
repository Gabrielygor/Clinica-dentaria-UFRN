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
#include <stdlib.h>    // Biblioteca


void tela_menu_p(void);     //Similar as "DEFS" em Python
void info_trabalho(void);


int main(void){
    tela_menu_p();
    info_trabalho();
    return 0;
}

void tela_menu_p(void) {    //Tela principal do programa
    char op;
    system("clear||cls");
    printf("\n");
    printf("===============================================\n");
    printf("   SISTEMA DE GESTAO PARA CLINICAS DENTARIAS   \n");
    printf("===============================================\n");
    printf("\n");
    printf("[1].Gerenciamento/Cadastro de clientes\n");
    printf("[2].Gerenciamento/Cadastro de funcionarios\n");
    printf("[3].\n");
    printf("[4].\n");
    printf("[5].Agendamento de horarios\n");
    printf("[6].Gestao de estoque\n");
    printf("[0].Sair\n");
    printf("\n");   
    printf("Escolha a opcao desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}




void info_trabalho(void){
    system("clear||cls");
    printf("\n");
    printf("=============================\n");
    printf("   Inforamcoes do Trabalho \n");
    printf("=============================\n");
    printf("    Este programa aborda o conteudo do segundo semestre de 2023 da disciplina de programacao do curso de\n");
    printf("Bacharelado em Sistemas de Informacao (BSI) na Universidade do Rio Grande do Norte(UFRN)\n");
    printf("\n");
    printf("Este programa representa uma solucao de software desenvolvida em linguagem C para a gestao de clinicas\n");
    printf("odontologicas. O sistema é projetado para auxiliar a administracao eficiente das atividades de uma\n");
    printf("clinica dentaria\n");

}