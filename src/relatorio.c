#include <stdio.h>
#include "relatorio.h"
#include "produto.h"
#include "utils.h"

void relatorio_geral(void) {
    limpar_tela();
    printf("=== RELATORIO GERAL DE ESTOQUE ===\n\n");

    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado. Relatorio indisponivel.\n");
        pausar_tela();
        return;
    }

    int total_itens = 0;
    float valor_total = 0.0f;
    int idx_maior = 0, idx_menor = 0;

    for (int i = 0; i < total_produtos; i++) {
        total_itens += p1[i].quantidade;
        valor_total += p1[i].preco * p1[i].quantidade;
        if (p1[i].preco > p1[idx_maior].preco) idx_maior = i;
        if (p1[i].preco < p1[idx_menor].preco) idx_menor = i;
    }

    printf("Total de produtos cadastrados : %d\n", total_produtos);
    printf("Total de itens em estoque     : %d\n", total_itens);
    printf("Valor total do estoque        : R$ %.2f\n\n", valor_total);

    printf("Produto mais caro :\n");
    printf("  Cod: %d | Nome: %s | Preco: R$ %.2f\n",
           p1[idx_maior].codigo, p1[idx_maior].nome, p1[idx_maior].preco);

    printf("Produto mais barato:\n");
    printf("  Cod: %d | Nome: %s | Preco: R$ %.2f\n",
           p1[idx_menor].codigo, p1[idx_menor].nome, p1[idx_menor].preco);

    pausar_tela();
}
