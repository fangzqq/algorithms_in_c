/* quick-find algorithm
 * an array of integers with the property that p and q are connected
 * if and only if the pth and qth array entries are equal
*/

# include <stdio.h>
# define N 10000

int main(void)
{
    int i, p, q, t, id[N];
    for (i = 0; i < N; i++) id[i] =i;
    while (scanf("%d %d\n", &p, &q) == 2)
    {
        if (id[p] == id[q]) continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];
        printf(" %d %d\n", p, q);
    }
}