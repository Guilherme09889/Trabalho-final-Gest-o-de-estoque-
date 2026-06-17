#include <stdio.h>
#include <string.h>
#include "cliente.h"
#include "utils.h"

Cliente c1[MAX_CLIENTES];
int total_clientes = 0;

static int proximo_codigo = 1;

int procurar_cliente_pelo_nome(const char *nome) {
    for (int i = 0; i < total_clientes; i++)
        if (strcmp(c1[i].nome, nome) == 0){
            return i;
        }
    return -1;
}

int procurar_cliente_pelo_cpf(const char *cpf) {
    for (int i = 0; i < total_clientes; i++)
        if (strcmp(c1[i].documento, cpf) == 0)
            return i;
    return -1;
}

void cadastro_cliente(void) {
    limpar_tela();
    if (total_clientes >= MAX_CLIENTES) {
        printf("Limite de %d clientes atingido.\n", MAX_CLIENTES);
        pausar_tela();
        return;
    }

    Cliente novo;
    novo.codigo = proximo_codigo;

    printf("=== CADASTRAR CLIENTE ===\n\n");
    printf("Codigo gerado automaticamente: %d\n\n", novo.codigo);

    printf("Nome completo: ");
    ler_string(novo.nome, sizeof(novo.nome));
    if (string_vazia(novo.nome)) {
        printf("Nome nao pode ser vazio.\n");
        pausar_tela();
        return;
    }

    printf("CPF: ");
    ler_string(novo.documento, sizeof(novo.documento));
    if (string_vazia(novo.documento)) {
        printf("CPF nao pode ser vazio.\n");
        pausar_tela();
        return;
    }
    if (procurar_cliente_pelo_cpf(novo.documento) != -1) {
        printf("Ja existe um cliente com esse CPF.\n");
        pausar_tela();
        return;
    }

    printf("Telefone: ");
    ler_string(novo.telefone, sizeof(novo.telefone));

    printf("Cidade: ");
    ler_string(novo.cidade, sizeof(novo.cidade));

    printf("\n--- Confirme os dados ---\n");
    printf("Codigo  : %d\n", novo.codigo);
    printf("Nome    : %s\n", novo.nome);
    printf("CPF     : %s\n", novo.documento);
    printf("Telefone: %s\n", novo.telefone);
    printf("Cidade  : %s\n", novo.cidade);
    printf("\nOs dados estao corretos? (s/n): ");
    char resp[4];
    ler_string(resp, sizeof(resp));
    if (resp[0] != 's' && resp[0] != 'S') {
        printf("Cadastro cancelado.\n");
        pausar_tela();
        return;
    }

    c1[total_clientes++] = novo;
    proximo_codigo++;
    printf("\nCliente cadastrado com sucesso!\n");
    pausar_tela();
}

void listar_cliente(void) {
    limpar_tela();
    printf("=== LISTA DE CLIENTES ===\n\n");
    if (total_clientes == 0) {-
        printf("Nenhum cliente cadastrado.\n");
        pausar_tela();
        return;
    }
    printf("%-4s %-30s %-15s %-15s %-20s\n", "Cod", "Nome", "CPF", "Telefone", "Cidade");
    printf("%-4s %-30s %-15s %-15s %-20s\n", "---", "----", "---", "--------", "------");
    for (int i = 0; i < total_clientes; i++) {
        printf("%-4d %-30s %-15s %-15s %-20s\n",
               c1[i].codigo, c1[i].nome, c1[i].documento,
               c1[i].telefone, c1[i].cidade);
    }
    pausar_tela();
}
