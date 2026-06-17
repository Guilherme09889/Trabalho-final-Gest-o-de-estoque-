#include <stdio.h>
#include "produto.h"
#include "cliente.h"
#include "vendas.h"
#include "relatorio.h"
#include "utils.h"

static void exibir_menu(void) {
    limpar_tela();
    printf("========================================\n");
    printf("     SISTEMA DE GESTAO DE LOJA\n");
    printf("========================================\n");
    printf("  1 - Cadastrar produto\n");
    printf("  2 - Listar produtos\n");
    printf("  3 - Alterar produtos\n");
    printf("  4 - Procurar produto\n");
    printf("  5 - Cadastrar cliente\n");
    printf("  6 - Listar clientes\n");
    printf("  7 - Realizar venda\n");
    printf("  8 - Relatorio geral\n");
    printf("  9 - Sair\n");
    printf("========================================\n");
    printf("Opcao: ");
}

static void procurar_produto_menu(void) {
    limpar_tela();
    printf("=== PROCURAR PRODUTO ===\n\n");
    printf("1 - Pelo nome\n");
    printf("2 - Pelo codigo\n");
    printf("Opcao: ");
    int op = ler_inteiro();
    if (op == 1) {
        printf("Nome: ");
        char nome[100];
        ler_string(nome, sizeof(nome));
        int idx = procurar_pelo_nome(nome);
        if (idx == -1) {
            printf("Produto nao encontrado.\n");
        } else {
            printf("\nCod: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                   p1[idx].codigo, p1[idx].nome, p1[idx].preco, p1[idx].quantidade);
        }
    } else if (op == 2) {
        printf("Codigo: ");
        int cod = ler_inteiro();
        int idx = procurar_pelo_codigo(cod);
        if (idx == -1) {
            printf("Produto nao encontrado.\n");
        } else {
            printf("\nCod: %d | Nome: %s | Preco: R$ %.2f | Estoque: %d\n",
                   p1[idx].codigo, p1[idx].nome, p1[idx].preco, p1[idx].quantidade);
        }
    } else {
        printf("Opcao invalida.\n");
    }
    pausar_tela();
}

int main(void) {
    int opcao;
    do {
        exibir_menu();
        opcao = ler_inteiro();
        switch (opcao) {
            case 1: cadastro_produto();      break;
            case 2: listar_produto();        break;
            case 3: alterar_produtos();      break;
            case 4: procurar_produto_menu(); break;
            case 5: cadastro_cliente();      break;
            case 6: listar_cliente();        break;
            case 7: realizar_venda();        break;
            case 8: relatorio_geral();       break;
            case 9: printf("\nSaindo...\n"); break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                pausar_tela();
        }
    } while (opcao != 9);

    return 0;
}
