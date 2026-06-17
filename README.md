# Sistema de Gestão de Loja

Trabalho final da disciplina de Desenvolvimento de Desktop. Sistema de gestão de
loja desenvolvido em C, com cadastro de produtos e clientes, registro de vendas
e geração de relatórios.

## Funcionalidades

- Cadastrar, listar, alterar e procurar produtos
- Cadastrar e listar clientes
- Realizar vendas
- Relatório geral

## Estrutura do projeto

```
.
├── main.c            
├── include/          
│   ├── cliente.h
│   ├── produto.h
│   ├── relatorio.h
│   ├── utils.h
│   └── vendas.h
└── src/              
    ├── cliente.c
    ├── produto.c
    ├── relatorio.c
    ├── utils.c
    └── vendas.c
```

## Como compilar e executar

gcc main.c src/*.c -Iinclude -o programa
./programa

