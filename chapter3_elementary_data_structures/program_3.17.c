/* sorting an array of strings
 * rearranging a set of strings into sorted order.
 * We read strings into a buffer large enough to hold them all, maintaining a pointer to each string in an array,
 * then rearrange the pointers to put the pointer to the smallest string in the first position in the array,
 * the pointer to the second smallest string in the second position in the array, and so forth.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Nmax 1000
#define Mmax 10000
char buf[Mmax];
int M = 0;

int compare(void *i, void *j)
{
    /* void指针可以指向任意的数据类型，即任意类型的指针可以赋值给void指针
     * 如果void指针赋值给其他类型，则需要强制转换
    */
    return strcmp(*(char **)i, *(char **)j);
}

int main(void)
{
    int i, N;
    char* a[Nmax];
    for (N = 0; N < Nmax; N++)
    {
        a[N] = &buf[M];
        if (scanf("%s", a[N]) == EOF) break;
        M += strlen(a[N]) + 1;
    }
    // qsort takes four arguments: 
    // a pointer to the beginning of the array, the number of objects, the size of each object, and a comparison function.
    qsort(a, N, sizeof(char*), compare);
    for (i = 0; i < N; i++) printf("%s\n", a[i]);
    
    return 0;
}
