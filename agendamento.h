struct agendamento{
    char cpf[12];
    char data[11];
    char hora[5];
    char funcionario[10];
};

void agendamento(void);        // Assinatura de Agendamentos
void agendarconsulta(void); 
void agendarretorno(void);
void excluirconsulta(void);
void excluirretorno(void);