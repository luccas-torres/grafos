#ifndef GRAFOS_H
#define GRAFOS_H
#define vertex int

typedef enum
{
    branco,
    cinza,
    preto
} cor;

typedef struct node *link;
struct graph
{
    int V, E;
    link *adj;
    cor *cores;
    int *dist;
    int *pai;  
};
typedef struct graph *Graph;

typedef struct node
{
    vertex w;
    link next;
} node;

static link NEWnode(vertex w, link next);

Graph initGraph(int V);

void insertArc(Graph G, vertex v, vertex w);

Graph BFS(Graph G, int s);
#endif