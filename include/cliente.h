#ifndef CLIENTE_H
#define CLIENTE_H

#define MAX_CLIENTES 50

typedef struct {
    int  codigo;
    char nome[100];
    char documento[20];
    char telefone[20];
    char cidade[50];
} Cliente;

extern Cliente c1[MAX_CLIENTES];
extern int total_clientes;

void cadastro_cliente(void);
void listar_cliente(void);
int  procurar_cliente_pelo_nome(const char *nome);
int  procurar_cliente_pelo_cpf(const char *cpf);

#endif
