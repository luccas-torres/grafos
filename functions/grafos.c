#include <stdio.h>
#include <stdlib.h>
#include "../headers/grafos.h"
#include "../headers/queue.h"

static link NEWnode(vertex w, link next)
{
    link a = malloc(sizeof(struct node));
    a->w = w;
    a->next = next;
    return a;
}

Graph initGraph(int V)
{
    Graph G = malloc(sizeof(struct graph));
    G->V = V;
    G->E = 0;
    G->adj = malloc(V * sizeof(link));
    G->cores = malloc(V * sizeof(cor));
    G->dist = malloc(V * sizeof(int));
    G->pai = malloc(V * sizeof(int));
    for (int i = 0; i < G->V; ++i)
    {
        G->adj[i] = NULL;
    }

    return G;
}

void insertArc(Graph G, vertex v, vertex w)
{
    for (link a = G->adj[v]; a != NULL; a = a->next)
    {
        if (a->w == w)
            return;
    }
    G->adj[v] = NEWnode(w, G->adj[v]);
    G->E++;
}

Graph BFS(Graph G, int s)
{
    for (int v = 0; v < G->V; v++)
    {
        G->cores[v] = s != v ? branco : cinza;
        G->dist[v] = 0;
        G->pai[v] = -1;
    }

    Fila *Q = malloc(sizeof(Fila));
    Q->inicio = Q->fim = NULL;
    enqueue(&Q, s);

    while (Q->inicio != NULL)
    {
        int u_index = dequeue(&Q);

        for (link v = G->adj[u_index]; v != NULL; v = v->next)
        {
            if (G->cores[v->w] == branco)
            {
                G->cores[v->w] = cinza;
                G->dist[v->w] = G->dist[u_index] + 1;
                G->pai[v->w] = u_index;
                enqueue(&Q, v->w);
            }
        }
        G->cores[u_index] = preto;
    }
    free(Q);
    return G;
}
