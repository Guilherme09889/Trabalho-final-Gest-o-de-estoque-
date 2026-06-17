#ifndef PRODUTO_H
#define PRODUTO_H

#define MAX_PRODUTOS 20

typedef struct {
    int   codigo;
    char  nome[100];
    float preco;
    int   quantidade;
} Produto;

extern Produto p1[MAX_PRODUTOS];
extern int total_produtos;

void cadastro_produto(void);
void listar_produto(void);
void exibir_produtos(void);
void alterar_produtos(void);
int  procurar_pelo_nome(const char *nome);
int  procurar_pelo_codigo(int codigo);

#endif
