typedef struct funcionario Funcionario;
struct funcionario { //Struct que contem as variaveis usadas no cadastro de funcionarios
    char cpf[12];
    char nome[100];
    char telefone[12];
};

void funcionario(void);           //Assinatura de Funcionarios 
Funcionario* cadastrofun(void);
void pesquisafun(void);
void atualizafun(void);
void listafun(void);
void excluirfun(void);
