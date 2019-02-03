/* sieve of Eratosthenes
 * The goal of this program is to set a[i] to 1 if i is prime, and to 0 if i is not prime
*/
#include <stdio.h>

#define N 10000
int main(void)
{
    int i, j, a[N];
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
        if (a[i]) printf("%6d", i);
    }
    printf("\n");
}
