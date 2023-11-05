#include <stdio.h>      //Biblioteca 
#include <stdlib.h>    // Biblioteca
#include "telas.h"


void tela_menu_p(void) {   //Tela principal do programa
    system("clear||cls");   //Limpa a tela do terminal
    printf("=============================================== \n");
    printf("\n");
    printf("   SISTEMA DE GESTAO PARA CLINICAS DENTARIAS    \n");
    printf("\n");
    printf("=============================================== \n");
    printf("\n");
    printf("|[1]. Gerenciamento/Cadastro de Clientes        \n");
    printf("|[2]. Gerenciamento/Cadastro de Funcionarios    \n");
    printf("|[3]. Agendamento de Horarios                   \n");
    printf("|[4]. Gestao de estoque                         \n");
    printf("|[5]. Listar consultas e retornos agendados     \n");
    printf("|[6]. Informacoes do Trabalho                   \n");
    printf("|[7]. Informacoes da Equipe                     \n");
    printf("|[0]. Sair                                       \n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void info_trabalho(void){
    system("clear||cls");
    printf("=============================\n");
    printf("\n");
    printf("   Inforamcoes do Trabalho   \n");
    printf("\n");
    printf("=============================\n");
    printf("\n");
    printf("    Este programa aborda o conteudo do segundo semestre de 2023 da disciplina de programacao do curso de\n");
    printf("Bacharelado em Sistemas de Informacao (BSI) na Universidade do Rio Grande do Norte(UFRN).\n");
    printf("    E tambem representa uma solucao de software desenvolvida em linguagem C para a gestao de clinicas\n");
    printf("odontologicas. O sistema e projetado para auxiliar a administracao eficiente das atividades de uma\n");
    printf("clinica dentária.\n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("\n");   
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void equipe(void){
    system("clear||cls");
    printf("============\n");
    printf("\n");
    printf("   Equipe   \n");
    printf("\n");
    printf("============\n");
    printf("\n");
    printf("|Projeto desenvolvido por:\n");
    printf("\n");
    printf("|Gabriel Ygor Canuto\n");
    printf("|E-mail: gabrielcanuto042@gmail.com\n");
    printf("|Instagram: https://www.instagram.com/gabriel_ygors/ \n");
    printf("|Github: https://github.com/Gabrielygor\n");
    printf("\n");
    printf("=-=-=-=-=-=-\n");
    printf("\n");   
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}


