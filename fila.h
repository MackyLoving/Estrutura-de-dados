// fila.h
#ifndef FILA_H
#define FILA_H

#include <stdbool.h>

#define MAX 5

typedef struct {
    int itens[MAX];
    int inicio, fim, tamanho;
} Fila;

void inicializar(Fila *f);
bool estaVazia(Fila *f);
bool estaCheia(Fila *f);
bool inserir(Fila *f, int valor);
bool remover(Fila *f, int *valor);
bool consultarInicio(Fila *f, int *valor);

#endif // FILA_H
