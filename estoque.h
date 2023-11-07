typedef struct {
    char nome[100];      // Nome do objeto
    int quantidade;      // Quantidade do objeto
    int id;              // ID do objeto
    int ativo;           // Indica se o objeto está ativo (1) ou inativo (0)
} ObjetoEstoque;

void estoque(void);            //Assinatura de Estoque 
void adicionarestoque(void);
void excluirestoque(void);
void listarestoque(void);
void saveObjetoEstoque(ObjetoEstoque* objeto);
void alterarestoque(void);
void pesquisarestoque(void);