typedef struct cliente Cliente;
struct cliente { //STRUCT que contem as informacoes de cadastro de clientes "cliente = paciente"
    char cpf[12];
    char nome[100];
    char telefone[12];
    char data[10];
    int ativo; // 1 para ativo, 0 para inativo
    Cliente *prox;
};

void ListaAlfaCli(void);
void exibeCliente(Cliente *cli);
void cabecalhoCli(void);

void cliente(void);                  // Assinaturas de Clientes
Cliente* cadastrocliente(void);
void pesquisacliente(void);
void atualizacliente(void);
void excluircliente(void);
void tela_menu_p(void);
void saveCliente(Cliente* cli);
int verificaCPFDuplicado(const char* cpf);

void listacliente(void);
void relatorioCli(void);
void listaclienteInativo(void);
void listaALLcliente(void);

//Cliente *prox;