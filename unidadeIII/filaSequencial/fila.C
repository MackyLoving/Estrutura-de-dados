// fila.c
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

void inicializar(Fila *f) {
    f->inicio = 0;
    f->fim = -1;
    f->tamanho = 0;
}

bool estaVazia(Fila *f) {
    return f->tamanho == 0;
}

bool estaCheia(Fila *f) {
    return f->tamanho == MAX;
}

bool inserir(Fila *f, int valor) {
    if (estaCheia(f)) {
        printf("Fila cheia!\n");
        return false;
    }
    f->fim = (f->fim + 1) % MAX;
    f->itens[f->fim] = valor;
    f->tamanho++;
    return true;
}

bool remover(Fila *f, int *valor) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return false;
    }
    *valor = f->itens[f->inicio];
    f->inicio = (f->inicio + 1) % MAX;
    f->tamanho--;
    return true;
}

bool consultarInicio(Fila *f, int *valor) {
    if (estaVazia(f)) {
        printf("Fila vazia!\n");
        return false;
    }
    *valor = f->itens[f->inicio];
    return true;
}
