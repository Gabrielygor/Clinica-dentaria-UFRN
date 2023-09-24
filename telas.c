#include <stdio.h>      //Biblioteca 
#include <stdlib.h>    // Biblioteca
#include "telas.h"


void tela_menu_p(void) {   //Tela principal do programa
    system("clear||cls");   //Limpa a tela do terminal
    printf("=============================================== \n");
    printf("\n");
    printf("   SISTEMA DE GESTÃO PARA CLÍNICAS DENTÁRIAS    \n");
    printf("\n");
    printf("=============================================== \n");
    printf("\n");
    printf("|[1]. Gerenciamento/Cadastro de Clientes        \n");
    printf("|[2]. Gerenciamento/Cadastro de Funcionários    \n");
    printf("|[3]. Agendamento de Horários                   \n");
    printf("|[4]. Gestão de estoque                         \n");
    printf("|[5]. Listar consultas e retornos agendados     \n");
    printf("|[6]. Informações do Trabalho                   \n");
    printf("|[7]. Informações da Equipe                     \n");
    printf("|[0]. Sair                                       \n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");   
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void info_trabalho(void){
    system("clear||cls");
    printf("=============================\n");
    printf("\n");
    printf("   Inforamções do Trabalho   \n");
    printf("\n");
    printf("=============================\n");
    printf("\n");
    printf("    Este programa aborda o conteudo do segundo semestre de 2023 da disciplina de programação do curso de\n");
    printf("Bacharelado em Sistemas de Informação (BSI) na Universidade do Rio Grande do Norte(UFRN).\n");
    printf("    E também representa uma solução de software desenvolvida em linguagem C para a gestão de clinicas\n");
    printf("odontologicas. O sistema e projetado para auxiliar a administração eficiente das atividades de uma\n");
    printf("clínica dentária.\n");
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


