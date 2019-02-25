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

    return r;
}


link reverse(link x)
{
    link t, y, r = NULL;
    for(y = x; t != NULL; y = t)
    {
        t = y -> next;
        y -> next = r;
        r = y;
    }

    return r;
}