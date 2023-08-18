///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte (UFRN)          ///
///                 Centro de Ensino Superior do Seridó (CERES)             ///
///               Departamento de Computação e Tecnologia                   ///
///                  Disciplina DCT1106 -- Programação                      ///
///                  Projeto Sistema de Gestão para clinicas dentarias      ///
///                      Developed by @Gabrielygor                          ///
///////////////////////////////////////////////////////////////////////////////
///  Trabalho referente ao segundo semestre do ano de 2023 do curso de BSI  ///
///////////////////////////////////////////////////////////////////////////////


#include <stdio.h>      //Biblioteca 
#include <stdlib.h>    // Biblioteca


void tela_menu_p(void);


int main(void){
    tela_menu_p();
    return 0;
}

void tela_menu_p(void) {
    char op;
    system("clear||cls");
    printf("\n");
    printf("===============================================\n");
    printf("   SISTEMA DE GESTAO PARA CLINICAS DENTARIAS\n");
    printf("===============================================\n");
    printf("\n");
    printf("[1].Gerenciamento/Cadastro de clientes\n");
    printf("[2].Gerenciamento/Cadastro de funcionarios\n");
    printf("[3].\n");
    printf("[4].\n");
    printf("[5].Agendamento de horarios\n");
    printf("[6].Gestão de estoque\n");
    printf("[0].Sair\n");
   
    printf("///            Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\n");
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}