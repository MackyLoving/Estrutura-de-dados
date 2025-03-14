// main.c
#include "fila.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    Fila fila;
    inicializar(&fila);

    inserir(&fila, 10);
    inserir(&fila, 20);
    inserir(&fila, 30);
    inserir(&fila, 40);
    inserir(&fila, 50);
    inserir(&fila, 60);

    int valor;
    if (consultarInicio(&fila, &valor)) {
        printf("Inicio da fila: %d\n", valor);
    }

    while (remover(&fila, &valor)) {
        printf("Removido: %d\n", valor);
    }

    remover(&fila, &valor);

    return 0;
}
