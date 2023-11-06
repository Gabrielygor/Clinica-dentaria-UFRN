typedef struct cliente Cliente;
struct cliente { //STRUCT que contem as informacoes de cadastro de clientes "cliente = paciente"
    char cpf[12];
    char nome[100];
    char telefone[12];
    char data[10];
    int ativo; // 1 para ativo, 0 para inativo
};


void cliente(void);                  // Assinaturas de Clientes
Cliente* cadastrocliente(void);
void pesquisacliente(const Cliente* cli);
void atualizacliente(void);
void listacliente(void);
void excluircliente(void);
void tela_menu_p(void);
void saveCliente(Cliente* cli);
int verificaCPFDuplicado(const char* cpf);

//void listaALLcliente(void);