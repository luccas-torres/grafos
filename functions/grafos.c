#include <stdio.h>
#include <stdlib.h>
#include "../headers/grafos.h"

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
    G->tempo = malloc(V * sizeof(tempo_visita));
    for (int i = 0; i < G->V; ++i)
    {
        G->adj[i] = NULL;
        G->cores[i] = branco;
        G->dist[i] = -1;
        G->pai[i] = -1;
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
    int *fila = malloc(G->V * sizeof(int));
    int ini, fim;
    ini = fim = 0;

    G->cores[s] = cinza;
    G->dist[s] = 0;
    
    fila[fim++] = s;

    while (ini < fim)
    {
        int u = fila[ini++];

        for (link v = G->adj[u]; v != NULL; v = v->next)
        {
            if (G->cores[v->w] == branco)
            {
                G->cores[v->w] = cinza;
                G->dist[v->w] = G->dist[u] + 1;
                G->pai[v->w] = u;
                fila[fim++] = v->w;
            }
        }
        G->cores[u] = preto;
    }
    free(fila);
    return G;
}

Graph DFS (Graph G) {
    int temp = 0;

    for (int i = 0; i < G->V; i++) {
        if (G->cores[i] == branco) DFS_Visit(G, i, &temp);
    }
}

void DFS_Visit(Graph G, vertex u, int *temp) {
    (*temp)++;
    G->tempo[u].descoberta = *temp;
    G->cores[u] = cinza;

    for (link a = G->adj[u]; a != NULL; a = a->next) {
        if (G->cores[a->w] == branco) {
            G->pai[a->w] = u;
            DFS_Visit(G, a->w, temp);
        }
    }

    G->cores[u] = preto;
    (*temp)++;
    G->tempo[u].fim = *temp;
}

void printPath (Graph G, int s, int v) {
    if (v == s) printf("%d -> ", s);
    else if (G->pai[v] == -1) printf("Não existe nenhum caminho de %d para %d\n", v, s);
    else {
        printPath(G, s, G->pai[v]);
        printf("%d -> ", v);
    }
}
