/* sieve of Eratosthenes
 * The goal of this program is to set a[i] to 1 if i is prime, and to 0 if i is not prime
 * we can take the maximum desired number from the command line, 
 * and use it to allocate space for the array at execution time, 
 * using the library function malloc from stdlib.c
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    long int i, j, N = atoi(argv[1]);
    int *a = malloc(N*sizeof(int));
    if (a == NULL)
    {
        printf("insufficient memory.\n");
        return -1;
    }
    for (i = 2; i < N; i++) a[i] = 1;
    for (i = 2; i < N; i++)
    {
        if (a[i])
        {
            for (j = i; i*j < N; j++) a[i*j] = 0;
        }
    }
    for (i = 2; i < N; i++)
    {
        if (a[i]) printf("%16ld", i);
    }
    printf("\n");
}