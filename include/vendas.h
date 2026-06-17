#ifndef VENDAS_H
#define VENDAS_H

#define MAX_VENDAS 200

typedef struct {
    int   codigo_cliente;
    int   codigo_produto;
    int   quantidade;
    float valor_total;
} Venda;

extern Venda v1[MAX_VENDAS];
extern int total_vendas;

void realizar_venda(void);
void listar_vendas(void);

#endif
