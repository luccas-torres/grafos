#ifndef GRAFOS_H
#define GRAFOS_H
#define vertex int

typedef enum
{
    branco,
    cinza,
    preto
} cor;

typedef struct {
    int descoberta, fim;
} tempo_visita;

typedef struct node *link;
struct graph
{
    int V, E;
    link *adj;
    cor *cores;
    int *dist;
    int *pai;  
    tempo_visita *tempo;
};
typedef struct graph *Graph;

typedef struct node
{
    vertex w;
    link next;
} node;

typedef struct cell {
    int value;
    struct cell *prox;
} Noh;

static link NEWnode(vertex w, link next);

Graph initGraph(int V);

void insertArc(Graph G, vertex v, vertex w);

Graph BFS(Graph G, int s);

void printPath (Graph G, int s, int v);

Graph DFS (Graph G);
void DFS_Visit(Graph G, vertex u, int *temp);

void adicionar (Noh **cabeca, int x);
Graph DFS_OrdTop (Graph G, Noh **OrdTop);
void DFS_Visit_OrdTop(Graph G, vertex u, int *temp, Noh **OrdTop);
#endif