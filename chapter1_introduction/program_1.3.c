/* weighted quick-union algorithm
 * we keep track of the number of nodes in each tree and always connect the smaller tree to the larger
 * The weighted quick-union algorithm follows at most 2 lgN pointers to determine whether two of N objects are connected
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
        for (i = p; id[i] != i; i = id[i]);
        for (j = q; id[j] != j; j = id[j]);

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