#include <stdio.h>
#include <stdlib.h>

struct node
{
    int number;
    struct node *prev;
    struct node *next;
};

struct node *insert(struct node *head, int x);
struct node *begin(struct node *head, int x);
struct node *end(struct node *head, int x);
struct node *between(struct node *head, int x, int position);

int main(void)
{
    struct node *head = NULL;
    struct node *tail = NULL;


    head = insert(head, 1);
    head = begin(head, 2);
    head = begin(head, 3);
    head = end(head, 19);
    head = between(head, 20, 2);
    struct node *ptr = head;

    while(ptr != NULL)
    {
        //printf("inside while \n");
        printf("%d ", ptr->number);
        ptr = ptr->next;
    }

    printf("\n");
    return 0;
}

//create a node
struct node *insert(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->number = x;
    temp->next = NULL;
    head = temp;
    return head;
}


//add node at the beginning
struct node *begin(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->number = x;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;

}


//add node at the end
struct node *end(struct node *head, int x)
{
    struct node *temp = malloc(sizeof(struct node));
    struct node *tp;
    temp->prev = NULL;
    temp->number = x;
    temp->next = NULL;
    tp = head;

    while(tp->next != NULL)
    {
        tp = tp->next;
    }

    tp->next = temp;
    temp->prev = tp;
    return head;
}

//add node in between
struct node *between(struct node *head, int x, int position)
{
    struct node *np = NULL;
    struct node *temp = head;
    struct node *temp2 = NULL;

    np = insert(np, x);

    while(position != 1)
    {
        temp = temp->next;
        position--;
    }
    temp2 = temp->next;

    if(temp->next == NULL)
    {
        temp->next = np;
        np->prev = temp;
    }
    else
    {
        temp->next = np;
        temp2->prev = np;
        np->prev = temp;
        np->next = temp2;
    }


    return head;
}
