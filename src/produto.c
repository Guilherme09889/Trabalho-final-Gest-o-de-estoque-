#include <stdio.h>
#include <string.h>
#include "produto.h"
#include "utils.h"

Produto p1[MAX_PRODUTOS];
int total_produtos = 0;

int procurar_pelo_codigo(int codigo) {  
    for (int i = 0; i < total_produtos; i++)
        if (p1[i].codigo == codigo)
            return i;
    return -1;
}

int procurar_pelo_nome(const char *nome) {
    for (int i = 0; i < total_produtos; i++)
        if (strcmp(p1[i].nome, nome) == 0)
            return i;
    return -1;
}

void cadastro_produto(void) {
    limpar_tela();
    if (total_produtos >= MAX_PRODUTOS) { 
        printf("Limite de %d produtos atingido.\n", MAX_PRODUTOS);
        pausar_tela();
        return;
    }

    Produto novo; //É uma struct para validar os dados que serão cadastrados.

    printf("=== CADASTRAR PRODUTO ===\n\n");

    printf("Codigo: ");
    novo.codigo = ler_inteiro();
    if (novo.codigo <= 0) {
        printf("Codigo invalido.\n");
        pausar_tela();
        return;
    }
    if (procurar_pelo_codigo(novo.codigo) != -1) {
        printf("Ja existe um produto com esse codigo.\n");
        pausar_tela();
        return;
    }

    printf("Nome: ");
    ler_string(novo.nome, sizeof(novo.nome)); 
    if (string_vazia(novo.nome)) {  
        printf("Nome nao pode ser vazio.\n");
        pausar_tela();
        return;
    }
    if (procurar_pelo_nome(novo.nome) != -1) {  //Essa funcao ta em src/produto.c na linha 16.
        printf("Ja existe um produto com esse nome.\n");
        pausar_tela();
        return;
    }

    printf("Preco: ");
    novo.preco = ler_float(); //Essa funcao ta em src/utils.c, na linha 31.
    if (novo.preco < 0) {
        printf("Preco nao pode ser negativo.\n");
        pausar_tela();
        return;
    }

    printf("Quantidade em estoque: ");
    novo.quantidade = ler_inteiro(); //Essa funcao ta em src/utils.c, na linha 20.
    if (novo.quantidade < 0) {
        printf("Quantidade nao pode ser negativa.\n");
        pausar_tela();
        return;
    }

    p1[total_produtos] = novo;
    total_produtos++;
    printf("\nProduto cadastrado com sucesso!\n");
    pausar_tela();
}

/* Imprime apenas a tabela de produtos (sem limpar a tela nem pausar),
   para poder ser reaproveitada no meio de outros fluxos, como a venda. */
void exibir_produtos(void) {
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }
    printf("%-6s %-30s %10s %10s\n","Código", "Nome", "Preco", "Estoque");
    printf("%-6s %-30s %10s %10s\n", "----", "----", "-----", "-------");
    for (int i = 0; i < total_produtos; i++) {
        printf("%-6d %-30s %10.2f %10d\n",p1[i].codigo, p1[i].nome, p1[i].preco, p1[i].quantidade);
    }
}

void listar_produto(void) {
    limpar_tela();
    printf("=== LISTA DE PRODUTOS ===\n");
    exibir_produtos();
    pausar_tela();
}

void alterar_produtos(void) {
    limpar_tela();
    printf("=== ALTERAR / EXCLUIR PRODUTO ===\n\n");
    if (total_produtos == 0) {
        printf("Nenhum produto cadastrado.\n");
        pausar_tela();
        return;
    }

    printf("Digite o codigo do produto: ");
    int codigo = ler_inteiro(); 
    int idx = procurar_pelo_codigo(codigo); 
    if (idx == -1) {
        printf("Produto nao encontrado.\n");
        pausar_tela();
        return;
    }

    printf("\nProduto encontrado: %s (cod %d, R$ %.2f, estoque: %d)\n",
           p1[idx].nome, p1[idx].codigo, p1[idx].preco, p1[idx].quantidade);
    printf("\nO que deseja fazer?\n");
    printf("1 - Alterar nome\n");
    printf("2 - Alterar preco\n");
    printf("3 - Alterar quantidade em estoque\n");
    printf("4 - Alterar codigo\n");
    printf("5 - Excluir produto\n");
    printf("0 - Cancelar\n");
    printf("Opcao: ");
    int op = ler_inteiro(); 

    switch (op) {
        case 1: {
            printf("Novo nome: ");
            char novo_nome[100];
            ler_string(novo_nome, sizeof(novo_nome)); 
            if (string_vazia(novo_nome)) { 
                printf("Nome invalido.\n"); break; 
            }
            if (procurar_pelo_nome(novo_nome) != -1) { 
                printf("Nome ja existe.\n"); 
                break; 
            }
            strcpy(p1[idx].nome, novo_nome);
            printf("Nome alterado.\n");
            break;
        }
        case 2: {
            printf("Novo preco: ");
            float novo_preco = ler_float();
            if (novo_preco < 0) { 
                printf("Preco invalido.\n"); 
                break; 
            }
            p1[idx].preco = novo_preco;
            printf("Preco alterado.\n");
            break;
        }
        case 3: {
            printf("Nova quantidade: ");
            int nova_qtd = ler_inteiro();
            if (nova_qtd < 0) { 
                printf("Quantidade invalida.\n");
                 break;
            }
            p1[idx].quantidade = nova_qtd;
            printf("Quantidade alterada.\n");
            break;
        }
        case 4: {
            printf("Novo codigo: ");
            int novo_cod = ler_inteiro();
            if (novo_cod <= 0) { 
                printf("Codigo invalido.\n");
                break; 
            }
            if (procurar_pelo_codigo(novo_cod) != -1) { 
                printf("Codigo ja existe.\n"); 
                break; 
            }
            p1[idx].codigo = novo_cod;
            printf("Codigo alterado.\n");
            break;
        }
        case 5: {
            for (int i = idx; i < total_produtos - 1; i++)
                p1[i] = p1[i + 1];
            total_produtos--;
            printf("Produto excluido.\n");
            break;
        }
        case 0:
            printf("Operacao cancelada.\n");
            break;
        default:
            printf("Opcao invalida.\n");
    }
    pausar_tela();
}
