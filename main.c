#include <stdio.h>
#include <stdlib.h>
#include "./headers/grafos.h"
#include "./headers/queue.h"

void imprimir(Graph G)
{
    for (int v = 1; v <= G->V; v++)
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
    int i = 1, adj, node;
    
    // for (i; i <= tam; i++) {
    //     scanf("%d", &qtde_nodes);
    //     // char s[30];
    //     // scanf("%s", s);
    //     // printf("%s\n", s);
    //     for (int j = 0; j < qtde_nodes; j++) {
    //         scanf("%d", &node);
    //         insertArc(G, i, node);
    //     }
    // }

    while ((scanf("%d", &adj)) != 1) {
        scanf("%d", &node);
        insertArc(G, adj, node);
    }

    // insertArc(G, 1, 2);
    // insertArc(G, 1, 5);

    // insertArc(G, 2, 1);
    // insertArc(G, 2, 5);
    // insertArc(G, 2, 4);
    // insertArc(G, 2, 3);

    // insertArc(G, 3, 2);
    // insertArc(G, 3, 4);

    // insertArc(G, 4, 3);
    // insertArc(G, 4, 2);
    // insertArc(G, 4, 5);

    // insertArc(G, 5, 2);
    // insertArc(G, 5, 1);
    // insertArc(G, 5, 4);

    imprimir(G);
    BFS(G, 1);

    for (int i = 1; i <= G->V; i++) {
        // printf("Lista pais: %d ", G->pai[i]);
        printf("%d ", G->dist[i]);
        puts("");
    }

    return 0;
}