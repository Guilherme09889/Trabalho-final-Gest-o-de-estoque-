#include <stdio.h>
#include "vendas.h"
#include "produto.h"
#include "cliente.h"
#include "utils.h"

Venda v1[MAX_VENDAS];
int total_vendas = 0;

void realizar_venda(void) {
    limpar_tela();
    printf("=== REALIZAR VENDA ===\n\n");

    if (total_vendas >= MAX_VENDAS) {
        printf("Limite de vendas atingido.\n");
        pausar_tela();
        return;
    }

    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado. Cadastre um produto antes de vender.\n");
        pausar_tela();
        return;
    }

    printf("Produtos disponiveis:\n");
    exibir_produtos();
    printf("\n");

    char nome_produto[100];
    printf("Nome do produto: ");
    ler_string(nome_produto, sizeof(nome_produto));
    int idx_prod = procurar_pelo_nome(nome_produto);
    if (idx_prod == -1) {
        printf("Produto '%s' nao encontrado.\n", nome_produto);
        pausar_tela();
        return;
    }
    printf("Produto encontrado: %s (cod %d, R$ %.2f, estoque: %d)\n\n",
           p1[idx_prod].nome, p1[idx_prod].codigo,
           p1[idx_prod].preco, p1[idx_prod].quantidade);

    /* 2. Validar cliente pelo CPF */
    char cpf[20];
    printf("CPF do cliente: ");
    ler_string(cpf, sizeof(cpf));
    int idx_cli = procurar_cliente_pelo_cpf(cpf);
    if (idx_cli == -1) {
        printf("Cliente com CPF '%s' nao encontrado.\n", cpf);
        pausar_tela();
        return;
    }
    printf("Cliente: %s (cod %d)\n\n", c1[idx_cli].nome, c1[idx_cli].codigo);

    /* 3. Confirmar produto pelo codigo */
    printf("Confirme o codigo do produto: ");
    int codigo_prod = ler_inteiro();
    if (procurar_pelo_codigo(codigo_prod) != idx_prod) {
        printf("Codigo invalido ou nao corresponde ao produto informado.\n");
        pausar_tela();
        return;
    }

    /* 4. Quantidade */
    printf("Quantidade desejada: ");
    int qtd = ler_inteiro();
    if (qtd <= 0) {
        printf("Quantidade deve ser maior que zero.\n");
        pausar_tela();
        return;
    }

    /* 5. Verificar estoque */
    if (qtd > p1[idx_prod].quantidade) {
        printf("Estoque insuficiente. Disponivel: %d\n", p1[idx_prod].quantidade);
        pausar_tela();
        return;
    }

    /* 6. Registrar venda */
    float valor = p1[idx_prod].preco * qtd;
    p1[idx_prod].quantidade -= qtd;

    v1[total_vendas].codigo_cliente = c1[idx_cli].codigo;
    v1[total_vendas].codigo_produto  = p1[idx_prod].codigo;
    v1[total_vendas].quantidade      = qtd;
    v1[total_vendas].valor_total     = valor;
    total_vendas++;

    printf("\nVenda realizada com sucesso!\n");
    printf("Cliente : %s\n", c1[idx_cli].nome);
    printf("Produto : %s\n", p1[idx_prod].nome);
    printf("Qtd     : %d\n", qtd);
    printf("Total   : R$ %.2f\n", valor);
    pausar_tela();
}

void listar_vendas(void) {
    limpar_tela();
    printf("=== HISTORICO DE VENDAS ===\n\n");
    if (total_vendas == 0) {
        printf("Nenhuma venda realizada.\n");
        pausar_tela();
        return;
    }
    printf("%-6s %-6s %-8s %12s\n", "CLI", "PROD", "QTD", "VALOR TOTAL");
    printf("%-6s %-6s %-8s %12s\n", "---", "----", "---", "-----------");
    for (int i = 0; i < total_vendas; i++) {
        printf("%-6d %-6d %-8d %12.2f\n",
               v1[i].codigo_cliente, v1[i].codigo_produto,
               v1[i].quantidade, v1[i].valor_total);
    }
    pausar_tela();
}
