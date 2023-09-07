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

// CONFERIR SE TODAS AS LINHAS TEM "  ; ; ;   " NO FINAL DE CADA FRASE
// CARACTERES ESPECIAIS COMO " Ç Á Â Ã " SÓ FUNCIONAM NATIVAMENTE NO LINUX

#include <stdio.h>      //Biblioteca 
#include <stdlib.h>    // Biblioteca

void tela_menu_p(void);     
void info_trabalho(void);
void equipe(void);

void cliente(void);
void cadastrocliente(void);
void pesquisacliente(void);
void atualizacliente(void);
void listacliente(void);
void excluircliente(void);

void funcionario(void);
void cadastrofun(void);
void pesquisafun(void);
void atualizafun(void);
void listafun(void);
void excluirfun(void);

void agendamento(void);
void agendarconsulta(void);
void agendarretorno(void);
void excluirconsulta(void);
void excluirretorno(void);

void estoque(void);
void adicionarestoque(void);
void excluirestoque(void);
void listarestoque(void);

int main(void) {  // Função do programa principal que contem a logica de programação 
    char op;
    do {
        tela_menu_p(); //Chama a Função de menu principal 
        printf("Escolha a opção desejada: "); //Pergunta a opção
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

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void cliente(void) {
    char op;
    do { // Loop para o menu de Clientes se repetir                                                           
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
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();

        switch (op) {
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
                listacliente();
                break;
            case '5':
                excluircliente();
                break;
            case '0':
                tela_menu_p();
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (op != '0'); // Sai do loop e volta para o menu principal caso a opcção = 0
}

void cadastrocliente(void){
    system("clear||cls");
    printf("Cadastro Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisacliente(void){
    system("clear||cls");
    printf("Pesquisa Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizacliente(void){
    system("clear||cls");
    printf("Atualizar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listacliente(void){
    system("clear||cls");
    printf("Listar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluircliente(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void funcionario(void){
    char op;
    do {
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
        printf("|[0]. Voltar ao menu Principal\n");
        printf("\n");
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        printf("\n");
        printf("|Escolha a opção desejada: ");
        scanf(" %c", &op);
        getchar();
    
        switch (op){
          case '1':
              cadastrofun();
              break;
          case '2':
              pesquisafun();
              break;
          case '3':
              atualizafun();
              break;
          case '4':
              excluirfun();
              break;
          case '5':
              listafun();
              break;
          case '0':
              tela_menu_p();
              break;
          default:
              printf("Opção inválida! Tente novamente.\n");
      }     
    } while (op != '0');
}

void cadastrofun(void){
    system("clear||cls");
    printf("Cadastro Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void pesquisafun(void){
    system("clear||cls");
    printf("Pesquisa Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void atualizafun(void){
    system("clear||cls");
    printf("Atualizar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void listafun(void){
    system("clear||cls");
    printf("Listar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

void excluirfun(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
            tela_menu_p();
            break;
          default:
            printf("Opção inválida! Tente novamente.\n");



            }
      } while (op != '0');
}  

void agendarconsulta(void){
    system("clear||cls");
    printf("Agendar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void agendarretorno(void){
    system("clear||cls");
    printf("Agendar Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void excluirconsulta(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}
void excluirretorno(void){
    system("clear||cls");
    printf("Excluir Em construção...");
    getchar();
    printf("\n");
    printf("\t\t\t>>> Tecle <ENTER> para continuar...\n");
    getchar();

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

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
            tela_menu_p();
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



