#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}node;

node *n = NULL;

void insert_node(int x);


int main(void)
{
    int i = 2;


    while (i < 12)
    {
        insert_node(i);
        i += 2;
    }

    node *ptr = n;
    while(ptr)
    {
     printf("%d ", ptr->number);
     ptr = ptr->next;
    }
    printf("\n");

}

void insert_node(int x)
{
    node *temp = malloc(sizeof(node));
    temp->number = x;
    temp->next = n;

    n = temp;

}