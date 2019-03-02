/* adjacency-lists graph representation
 * reads a set of edges that define a graph and builds an adjacency-matrix representation for the graph
 * An adjacency list for a graph is an array of lists, one for each vertex, 
 * where the jth list contains a linked list of the nodes connected to the jth vertex
*/

#include <stdio.h>
#include <stdlib.h>

#define v 10000

typedef struct node *link;
struct node
{
    int v;
    link next;
};


link NEW(int v, link next)
{
    link x = malloc(sizeof *x);
    x -> v = v;
    x -> next = next;

    return x;
}


int main(void)
{
    int i, j;
    link adj[V];
    
    for (i = 0; i < V; i++) adj[i] = NULL;
    while (scanf("%d %d\n", &i, &j) == 2)
    {
        adj[j] = NEW(i, adj[j]);
        adj[i] = NEW(j, adj[i]);
    }

    return 0;
}
