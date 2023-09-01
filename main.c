///////////////////////////////////////////////////////////////////////////////
///             Universidade Federal do Rio Grande do Norte (UFRN)          ///
///                 Centro de Ensino Superior do Serid� (CERES)            ///
///               Departamento de Computa��o e Tecnologia                 ///
///                  Disciplina DCT1106 -- Programa��o                    ///
///             Projeto Sistema de Gest�o para clinicas dentarias           ///
///                      Developed by @Gabrielygor                          ///
///////////////////////////////////////////////////////////////////////////////
///  Trabalho referente ao segundo semestre do ano de 2023 do curso de BSI  ///
///////////////////////////////////////////////////////////////////////////////

// CONFERIR SE TODAS AS LINHAS TEM "  ; ; ;   " NO FINAL 
// CARACTERES ESPECIAIS COMO " Ç Á Â Ã " SÓ FUNCIONAM NATIVAMENTE NO LINUX

#include <stdio.h>      //Biblioteca 
#include <stdlib.h>    // Biblioteca



void tela_menu_p(void);  //Tem que ter para poder criar as telas lá em baixo 
void info_trabalho(void);
void equipe(void);
void cliente(void);    
void funcionario(void);       
void agendamento(void);                      
void estoque(void);

int main(void) {  // Função do programa principal que contem a logica de programação 
    char op;
    do {
        tela_menu_p(); //Chama a Função de menu principal 
        printf("Escolha a opção desejada: ");
        scanf(" %c", &op); //Le a opção desejada
        getchar();  //Limpa a opção escolhida acima (contida no scanf)

        switch (op) {
            case '1': //Se a opção for igual a 1 roda o codigo até o 'Break'
                cliente(); //Chama a função de gerenciamento de clientes 
                break; // Break para impedir que o programa prossiga para as proximas funções 
            case '2': //Repete as funções do código acima 
                funcionario();
                break;
            case '3':
                agendamento();
                break;
            case '4':
                estoque();
                break;
            case '5':
                printf("Em desenvolvimento\n");
                break;
            case '6':
                info_trabalho();
                break;
            case '7':
                equipe();
                break;
            case '0':
                // Caso 0, o programa sairá do loop e encerrará
                break;
            default: // Opção que acontece se qualquer uma das opções pre selecionadas não for escolhida 
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != '0'); //Loop para continuar o programa quando a opção for diferente de 0

    return 0; //Retorna 0 e encera o programa 
}

void tela_menu_p(void) {   //Tela principal do programa
    char op;
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
    printf("|[0].Sair                                       \n");
    printf("\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");   
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
    printf("odontologicas. O sistema e projetado para auxiliar a administra��o eficiente das atividades de uma\n");
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
    printf("   Gerenciamento de Funcion�rios   \n");
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



