/* a two-dimensional array of lists
 * illustrates the effectiveness of proper data-structure choice, for the geometric computation of Program 3.8
*/

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

typedef struct node *link;
struct node 
{
    point p;
    link next;
};

link **grid;
int G;
float d;
int cnt = 0;


int gridinsert(float x, float y)
{
    int i, j;
    link s;
    int X = x * G + 1;
    int Y = y * G + 1;
    link t = malloc(sizeof *t);
    
    t -> p.x = x;
    t -> p.y = y;
    for (i = X - 1; i <= X + 1; i++)
    {
        for (j = Y - 1; j <= Y + 1; j++)
        {
            for (s = grid[i][j]; s != NULL; s = s -> next)
            {
                if (distance(s -> p, t -> p) < d) cnt++;
            }
        }
    }

    t -> next = grid[X][Y];
    grid[X][Y] = t;

    return 0;
}


float randFloat(void)
{
    return 1.0 * rand() / RAND_MAX;
}


link **malloc2d(int r, int c)
{
    int i;
    link **t = malloc(r * sizeof(link *));
    
    for (i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(link));
    
    return t;
}


int main(int argc, char *argv[])
{
    int i, j, N = atoi(argv[1]);
    d = atof(argv[2]);
    G = 1 / d;
    grid = malloc2d(G+2, G+2);
    
    for (i = 0; i < G + 2; i++)
    {
        for (j = 0; j < G + 2; j++)
        {
            grid[i][j] = NULL;
        }
    }

    for (i = 0; i < N; i++)
    {
        gridinsert(randFloat(), randFloat());
    }

    printf("%d edges shorter than %f\n", cnt, d);

    return 0;
}
