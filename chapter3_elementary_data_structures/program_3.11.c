/* list insertion sort
 * This code generates N random integers between 0 and 999, builds a linked list with one number per node (first for loop), 
 * and then rearranges the nodes so that the numbers appear in order when we traverse the list (second for loop).
 * The code is simplified by the use of head nodes for each list, that contain the links to the first nodes on the lists.
*/
#include <stdio.h>

typedef struct node *link;
struct node {int item; link next};
#define N 100

link sort(void)
{
    struct node heada, headb;
    link t, u, x, a = &heada, b;
    int i;
    // generates N random integers
    for (i = 0, t = a; i < N; i++)
    {
        t -> next = malloc(sizeof *t);
        t = t -> next;
        t -> next = NULL;
        t -> item = rand() % 1000;
    }
    
    // sort
    b = &headb;
    b -> next = NULL;
    for (t = a -> next; t != NULL; t = u)
    {
        u = t -> next;
        for (x = b; x -> next != NULL; x = x ->next)
            if (x -> next -> item > t -> item) break;
        t -> next = x -> next;
        x -> next = t;
    }
    
    return b;
}
