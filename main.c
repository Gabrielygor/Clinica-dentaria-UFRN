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


void tela_menu_p(void);     
void info_trabalho(void);
void equipe(void);
void cliente(void);    
void funcionario(void);       
void agendamento(void);                      
void estoque(void);

int main(void){   //Funcao principal do programa
    tela_menu_p();
    info_trabalho();
    equipe();
    cliente();
    funcionario();
    agendamento();
    estoque();
    return 0;
}

void tela_menu_p(void) {   //Tela principal do programa
    char op;
    system("clear||cls");   //Limpa a tela do terminal
    printf("===============================================\n");
    printf("\n");
    printf("   SISTEMA DE GESTÃO PARA CLÍNICAS DENTÁRIAS   \n");
    printf("\n");
    printf("===============================================\n");
    printf("                                                          ⠀⣀⣠⠤⠶⠶⠤⠄⣀⡀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣀⠀⠀                 \n");
    printf("|[1]. Gerenciamento/Cadastro de Clientes                ⣠⡖⠋⠁⠀⠀⠀⠀⠀⠈⠉⠐⠦⠄⠒⠈⠉⠉⠉⠉⠉⠛⠲⣤                \n");
    printf("|[2]. Gerenciamento/Cadastro de Funcionários           ⢸⠇⠀⠀⠀⠀⣀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠈⢿⠀                \n");
    printf("|[3]. Agendamento de Horários                          ⡟⠀⠀⠀⠀⠛⠉⠁⠀⠀⠀⠀⠀⠐⠉⠙⠣⡀⠀⠀⠀⠀⠀⠀⠀⠈⡇⣀⡀⠀⠀⠀         \n");
    printf("|[4]. Gestão de estoque                                ⡇⠀⠀⠀⢠⢉⢤⡑⠀⠀⠀⠀⠀⡀⢉⣉⢂⠀⠀⠀⠀⠀⠀⠀⠀⠀⡏⡀⠈⠂⠀⠀         \n");
    printf("|[5]. Listar consultas e retornos agendados            ⢣⠀⠀⠀⠠⢸⣿⣇⠀⠀⠀⠀⠀⡁⣷⣿⡾⠀⠀⠀⠀⠀⠀⠀⠀⣸⡴⠀⠀⠦⠄⡀         \n");
    printf("|[6]. Informações do Trabalho                          ⢸⡄⠀⠀⠀⠒⠛⠄⠀⠀⠀⠀⠀⢠⡹⠭⠂⠀⠀⠀⠀⠀⠀⠀⣠⠁⡀⡏⣁⡀⠰⡁        \n");
    printf("|[7]. Informações da Equipe                           ⠠⠃⢃⠀⠀⠀⠀⠒⣀⠀⠀⠀⠀⠀⢀⡄⠀⠀⠀⠀⠀⠀⠀⠤⠐⠐⠋⠙⢵⡆⠐⡺⠀        \n");
    printf("|[0].Sair                                            ⢠⡇⢀⡼⡄⠀⠀⠀⠀⠘⣮⣭⣉⣭⣴⣾⠃⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡠⠚⠁⠀⠀⠀⠀        \n");
    printf("                                                     ⠈⠣⡀⠀⠙⡀⠀⠀⠀⠀⠘⣉⣙⣁⡰⠃⠀⠀⠀⠀⠀⠀⠀⣰⠀⠈⠁⠀⠀⠀⠀⠀⠀⠀        \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=         ⢈⠡⠆⠳⠀⠀⠀⠀⠀⠐⠭⠵⠊⠀⠀⠀⠀⠀⠀⠀⠀⠇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀        \n");   
    printf("                                                        ⠈⠑⠒⠂⢧⠀⠀⠀⠀⠀⠠⡄⡀⠀⠀⠀⠀⠀⠀⠀⢰⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀        \n");
    printf("                                                              ⢣⠀⠀⠀⠀⡜⠀⠀⠡⡄⠀⠀⠀⠀⠀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀          \n");
    printf("                                                               ⢣⡀⠀⢀⠃⠀⠀⠀⠘⢢⡀⠀⠀⠀⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         \n");   
    printf("                                                                ⠙⠛⠛⠀⠀⠀⠀⠀⠀⠘⠳⠶⠞⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀         \n");
    printf("|Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

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

void cliente(void){
    char op;
    system("clear||cls");
    printf("===============================\n");
    printf("\n");
    printf("   Gerenciamento de Clientes   \n");
    printf("\n");
    printf("===============================\n");
    printf("\n");
    printf("|[1]. Cadastrar Cliente\n");
    printf("|[2]. Pesquisar Cliente\n");
    printf("|[3]. Atualizar Cliente\n");
    printf("|[4]. Listar Cliente\n");
    printf("|[5]. Excluir Cliente\n");
    printf("|[0]. Voltar ao menu anterior\n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("|Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");   
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void funcionario(void){
    char op;
    system("clear||cls");
    printf("===================================\n");
    printf("\n");
    printf("   Gerenciamento de Funcionários   \n");
    printf("\n");
    printf("===================================\n");
    printf("\n");
    printf("|[1]. Cadastrar Funcionário\n");
    printf("|[2]. Pesquisar Funcionário\n");
    printf("|[3]. Atualizar Funcionário\n");
    printf("|[4]. Excluir Funcionário\n");
    printf("|[5]. Listar Funcionários\n");
    printf("|[0]. Voltar ao menu anterior\n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("|Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void agendamento(void){
    char op;
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
    printf("|[0]. Voltar ao menu anterior\n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=\n");
    printf("\n");
    printf("|Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}

void estoque(void){
    char op;
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
    printf("|[0]. Voltar ao menu anterior\n");
    printf("\n");
    printf("=-=-=-=-=-=-=\n");
    printf("\n");
    printf("|Escolha a opção desejada: ");
    scanf("%c", &op);
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();
}





