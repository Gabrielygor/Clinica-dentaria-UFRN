#include "ulti.h"
#include <string.h>
#include <stdio.h>


//Valida CPF
///Validacao baseada no seguinte codigo: https://github.com/Brunowcst/Sistema-de-controle-de-clientes-
int validaCPF(char *cpf) {
    int i, j, digito1 = 0, digito2 = 0;

    if (strlen(cpf) != 11)
        return 0;
    else if ((strcmp(cpf, "00000000000") == 0) || (strcmp(cpf, "11111111111") == 0) || (strcmp(cpf, "22222222222") == 0) || (strcmp(cpf, "33333333333") == 0) || (strcmp(cpf, "44444444444") == 0) || (strcmp(cpf, "55555555555") == 0) || (strcmp(cpf, "66666666666") == 0) || (strcmp(cpf, "77777777777") == 0) || (strcmp(cpf, "88888888888") == 0) || (strcmp(cpf, "99999999999") == 0))
        return 0;
    else {
        for (i = 0, j = 10; i < strlen(cpf) - 2; i++, j--)
            digito1 += (cpf[i] - '0') * j;
        digito1 %= 11;
        if (digito1 < 2)
            digito1 = 0;
        else
            digito1 = 11 - digito1;
        if ((cpf[9] - '0') != digito1)
            return 0;
        else {
            for (i = 0, j = 11; i < strlen(cpf) - 1; i++, j--)
                digito2 += (cpf[i] - '0') * j;
            digito2 %= 11;
            if (digito2 < 2)
                digito2 = 0;
            else
                digito2 = 11 - digito2;
            if ((cpf[10] - '0') != digito2)
                return 0;
        }
    }
    return 1;
}

// Valida letra 
// Baseado no codigo de Flavius GORGÔNIO
int testaLetra(char c){
  if (c >= 'A' && c <= 'Z'){
    return 1;
  } else if (c >= 'a' && c <= 'z'){
    return 1;
  } else if (c == ' '){
    return 1;
  } else {
    return 0;
  }
}

// Valida nome 
// Baseado no codigo de Flavius GORGÔNIO
int validarNome(char *nome){
  for (int i=0; nome[i]!='\0'; i++){
    if (!testaLetra(nome[i])){
      printf("<%c>", nome[i]);
      return 0;
    }
  }
    return 1;
}

/*
//Validador de idade 
//Desenvolvido com auxilio do perplexity.ai 
int validarIdade(int idade) {
    if (idade >= 0 && idade <= 150) {
        return 1; // Idade válida
    } else {
        return 0; // Idade inválida
    }
}
*/


//VALIDA TELEFONE
// Desenvolvido com auxilio do ChatGPT
int validaTele(char* fone){ 
  int tam;
  tam = strlen(fone);
  if (tam != 11){
    return 0;
  }
  for (int i=0; i < tam; i++){
    if (!ehDg(fone[i])) {
      return 0;
    }
  }
  return 1;
}
int ehDg(char c){
  if (c>= '0' && c <= '9'){
    return 1;
  } else {
    return 0;
  }
}

// Funcao adaptada do aluno https://github.com/Japagabriel

int lerHora(char hora[5]) {
    int tamanho = strlen(hora); //formato HH:MM  

    if (tamanho != 5) {
        return 0;
    } else {
        if (hora[2] != ':') {
            return 0;
        }

        if (hora[0] >= '0' && hora[0] <= '2' && hora[1] >= '0' && hora[1] <= '9' &&
            hora[3] >= '0' && hora[3] <= '5' && hora[4] >= '0' && hora[4] <= '9') {
            return 1;
        } else {
            return 0;
        }
    }

    return 1;
}



// Valida data
int lerData(char data[9]) {
    int tamanho = strlen(data);
    if (tamanho < 1 || tamanho > 9) {
        return 0;
    } else {
        for (int i = 0; i <= (tamanho - 1); i++) {
            if (data[i] == '0' || data[i] <= '9') {
              if (data[2] == '/' && data[5] == '/') {
                  if (data[i] == ' ') {
                      return 1;
                  }
                  if (data[i] == '@') {
                      return 0;
                  }
              } else {
                return 0;
              }
            } else {
                return 0;
            }
        }

    }
    return 1;
}