#include <stdio.h>
#include <stdlib.h>
#include "./headers/grafos.h"
#include "./headers/queue.h"

void imprimir(Graph G)
{
    for (int v = 0; v < G->V; v++)
    {
        if (G->adj[v] == NULL)
            return;
        link tmp = G->adj[v];
        printf("%d: ", v);
        while (tmp != NULL)
        {
            printf("%d -> ", tmp->w);
            tmp = tmp->next;
        }
        puts("");
    }
}

int main()
{
    int tam;
    scanf("%d", &tam);
    Graph G = initGraph(tam);
    int adj, node, source;
    scanf("%d", &source);

    while ((scanf("%d", &adj)) == 1) {
        scanf("%d", &node);
        insertArc(G, adj, node);
    }

    imprimir(G);
    Noh *OrdTop = NULL;
    DFS_OrdTop(G, &OrdTop);
    Noh *tmp = OrdTop;
    if (OrdTop == NULL) puts("oiii");
    while (tmp != NULL) {
        printf("%d ", tmp->value);
        tmp = tmp->prox;
    }

    for (int i = 0; i < G->V; i++) {
        // printf("Pai do %d: %d ", i, G->pai[i]);
        // printf("Distancia do %i ao %d: %d ", i, source, G->dist[i]);
        printf("\nVértice %d: \nTempo de descoberta %d\nTempo de finalização %d", i, G->tempo[i].descoberta, G->tempo[i].fim);
        puts("");
    }

    // int vert = 3;
    // printf("Caminho de %d até %d\n", source, vert);
    // printPath(G, source, vert);
    return 0;
}