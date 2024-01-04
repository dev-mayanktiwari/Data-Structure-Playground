#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;

void Display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void insert(struct Node *p, int index, int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    int i;
    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}

void insertAtEnd(struct Node **first, int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (*first == NULL)
    {
        t->prev = NULL;
        *first = t;
    }
    else
    {
        last = *first;
        while (last->next != NULL)
        {
            last = last->next;
        }
        t->prev = last;
        last->next = t;
    }
}

int main()
{
    int A[]={10,20,40,50,60};
    create(A,5);
    insert(first,2,30);
    insertAtEnd(&first,100);
    Display(first);
}