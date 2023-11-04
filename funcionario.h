typedef struct funcionario Funcionario;
struct funcionario { //Struct que contem as variaveis usadas no cadastro de funcionarios
    char cpf[12];
    char nome[100];
    char telefone[12];
    char data[10];
    int ativo; // 1 para ativo, 0 para inativo
};

void funcionario(void);           //Assinatura de Funcionarios 
Funcionario* cadastrofuncionario(void);
void pesquisafuncionario(void);
void atualizafuncionario(void);
void listafuncionarios(void);
void excluirfuncionario(void);
void saveFuncionario(Funcionario* fun);
int verificaCPFDuplicad(const char* cpf);

//