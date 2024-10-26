#include <stdio.h>
#include <stdlib.h>

// Uma lista normal feita em C
// A normal list made in C

typedef struct node
{
    int value;
    struct node *next;
} node;


int main(int agrc, char *argv[])
{
    int i, j;
    node *list = NULL;
    for(i = 1; i < agrc; i++)
    {
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            return 1;
        }
        n->value = atoi(argv[i]);
        n->next = list;
        list = n;
    }
    node *ptr = list;
    while (ptr != NULL)
    {
        printf("%d\n", ptr->value);
        ptr = ptr->next;
    }
    return 0;
}