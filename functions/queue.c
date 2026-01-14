#include <stdio.h>
#include <stdlib.h>
#include "../headers/queue.h"

void enqueue (Fila **fila, int v) {
    Noh *novo_no = malloc(sizeof(Noh));
    novo_no->v = v;

    if ((*fila)->inicio == NULL) {
        (*fila)->inicio = (*fila)->fim = novo_no;
        novo_no->prox = NULL;
    } else {
        (*fila)->fim->prox = novo_no;
        (*fila)->fim =  novo_no;
    }
}

int dequeue (Fila **fila) {
    if ((*fila)->inicio == NULL) return -1;

    Noh *tmp = (*fila)->inicio;
    int value = tmp->v;
    (*fila)->inicio = tmp->prox;
    free(tmp);
    return value;
}