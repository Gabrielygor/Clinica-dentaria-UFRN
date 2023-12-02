typedef struct agendamento Agendamento;
struct agendamento{
    char cpf[12];
    char data[11];
   // char hora[5];
    char cpff[12];
    int ativo; // 1 para ativo, 0 para inativo
    Agendamento *prox;
};

void ListaAlfaData(void);
void cabecalhoAge(void);

void agendamento(void);        // Assinatura de Agendamentos
Agendamento* agendarconsulta(void); 
void excluirconsulta(void);

char *getCli(const char *cpf);
char *getFun(const char *cpf);
void salvarAgendamento(Agendamento *age);
void atualizaAgendamento(void);
void pesquisaConsultasCliente(void);


void relatorioAge(void);
void listaagendamentoAtivo(void);
void listaALLagendamento(void);
void listaagendamentoInativo(void);
void exibeAgendamento(Agendamento *age);