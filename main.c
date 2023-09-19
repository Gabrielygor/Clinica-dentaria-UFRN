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



#include "cliente.h"
#include "funcionario.h"
#include "agendamento.h"
#include "estoque.h"
#include "valida.h"
#include "telas.h"

void tela_menu_p(void);         //Assinaturas variadas     
void info_trabalho(void);
void equipe(void);

// Cria telas.h 
// Mudar tela principal (void)Principal(void)
//Olhar git Renan 
//ver como colocar pelo gcc terminal
//

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







