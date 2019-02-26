/* two-dimensional allocation
 * dynamically allocates the memory for a two-dimensional array, as an array of arrays
 * We first allocate an array of pointers, then allocate memory for each row.
 * int **a = malloc2d(M, N), allocates an M-by-N array of integers.
*/

#include <stdio.h>

int **malloc2d(int r, int c)
{
    int i;
    int **t = malloc(r * sizeof(int *));
    
    for (i = 0; i < r; i++)
        t[i] = malloc(c * sizeof(int));
    
    return t;
}
