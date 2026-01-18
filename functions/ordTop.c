#include <stdio.h>
#include <stdlib.h>
#include "../headers/grafos.h"

void adicionar (Noh **cabeca, int x) {
    Noh *novo_no = malloc(sizeof(Noh));
    novo_no->value = x;
    novo_no->prox = *cabeca; 
    
    *cabeca = novo_no;
}

Graph DFS_OrdTop (Graph G, Noh **OrdTop) {
    int temp = 0;
    
    for (int i = 0; i < G->V; i++) {
        if (G->cores[i] == branco) DFS_Visit_OrdTop(G, i, &temp, OrdTop);
    }
}

void DFS_Visit_OrdTop(Graph G, vertex u, int *temp, Noh **OrdTop) {
    (*temp)++;
    G->tempo[u].descoberta = *temp;
    G->cores[u] = cinza;

    for (link a = G->adj[u]; a != NULL; a = a->next) {
        if (G->cores[a->w] == branco) {
            G->pai[a->w] = u;
            DFS_Visit_OrdTop(G, a->w, temp, OrdTop);
        }
    }

    G->cores[u] = preto;
    adicionar(OrdTop, u);
    (*temp)++;
    G->tempo[u].fim = *temp;
}