#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

void limpar_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ler_string(char *dest, int tamanho) {
    if (tamanho <= 0)
        return;

    if (fgets(dest, tamanho, stdin) != NULL) {
        size_t fim_linha = strcspn(dest, "\n");

        if (dest[fim_linha] == '\n')
            dest[fim_linha] = '\0';
        else
            limpar_buffer();
    }
}

int ler_inteiro(void) {
    int valor;
    char buf[64];
    while (1) {
        ler_string(buf, sizeof(buf));
        if (sscanf(buf, "%d", &valor) == 1)
            return valor;
        printf("Entrada invalida. Digite um numero inteiro: ");
    }
}

float ler_float(void) {
    float valor;
    char buf[64];
    while (1) {
        ler_string(buf, sizeof(buf));
        if (sscanf(buf, "%f", &valor) == 1)
            return valor;
        printf("Entrada invalida. Digite um numero: ");
    }
}

int string_vazia(const char *s) {
    while (*s) {
        if (!isspace((unsigned char)*s))
            return 0;
        s++;
    }
    return 1;
}

void pausar_tela(void) {
    printf("\nPressione Enter para continuar...");
    limpar_buffer();
}

void limpar_tela(void) {
    system("clear");
}
