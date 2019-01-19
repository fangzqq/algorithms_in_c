/* quick-union algorithm
 * Each object points to another object in the same set, in a structure with no cycles. 
 * To determine whether two objects are in the same set, 
 * we follow pointers for each until we reach an object that points to itself. 
 * The objects are in the same set if and only if this process leads them to the same object. 
 * If they are not in the same set, we wind up at different objects (which point to themselves). 
 * To form the union, then we just link one to the other to perform the union operation
*/

# include <stdio.h>
# define N 10000

int main(void)
{
    int i, j, p, q, id[N];
    for (i = 0; i < N; i++) id[i] = i;
    while (scanf("%d %d\n", &p, &q) == 2)
    {
        // while (id[p] != p) p = id[p];
        for (i = p; id[i] != i; i = id[i]);
        for (j = q; id[j] != j; j = id[j]);
        if (i == j) continue;
        id[i] = j;
        printf("%d %d\n", p, q);
    }
}