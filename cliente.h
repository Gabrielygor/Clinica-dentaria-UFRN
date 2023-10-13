struct cliente { //STRUCT que contem as informacoes de cadastro de clientes "cliente = paciente"
    char cpf[12];
    char nome[100];
    char telefone[12];
    char data[10];
};


void cliente(void);                  // Assinaturas de Clientes
void cadastrocliente(void);
void pesquisacliente(void);
void atualizacliente(void);
void listacliente(void);
void excluircliente(void);
void tela_menu_p(void);
