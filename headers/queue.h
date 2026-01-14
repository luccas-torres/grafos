#ifndef QUEUE_H
#define QUEUE_H

typedef struct Noh {
    int v;
    struct Noh *prox;
} Noh;

typedef struct {
    Noh *inicio, *fim;
} Fila;

void enqueue (Fila **fila, int v);

int dequeue (Fila **fila);

#endif