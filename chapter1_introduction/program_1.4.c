/* weighted quick union with path compression by halving
 * compresses the paths by making each link skip to the next node in the path on the way up the tree
*/

# include <stdio.h>
# define N 10000

int main(void)
{
    int i ,j, p, q, id[N], sz[N];
    for(i = 0; i < N; i++)
    {
        id[i] = i;
        sz[i] = 1;
    }
    while (scanf("%d %d\n", &p, &q) == 2)
    {
        for (i = p; id[i] != i; i = id[i]) id[i] = id[id[i]];
        for (j = q; id[j] != j; j = id[j]) id[j] = id[id[j]];

        if (i == j) continue;
        if (sz[i] < sz[j]) 
        {
            id[i] = j;
            sz[j] += sz[i];
        }
        else
        {
            id[j] = i;
            sz[i] += sz[j];
        }
    }
}