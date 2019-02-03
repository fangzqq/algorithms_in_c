/* list reversal
*/
#include <stdio.h>

typedef struct node *link;
struct node {int item; link next;};

link reverse(link x)
{
    link t, y=x, r = NULL;
    while (y != NULL)
    {
        t = y -> next;
        y -> next = r;
        r = y;
        y = t;
    }
}
