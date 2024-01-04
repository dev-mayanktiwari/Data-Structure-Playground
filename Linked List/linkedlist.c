#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *first;

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


void display(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

int count(struct Node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int recursiveCount(struct Node *p)
{
    return (p != NULL) ? recursiveCount(p->next) + 1 : 0;
}

int max(struct Node *p)
{
    int max = INT32_MIN;
    while (p)
    {
        if (p->data)
            max = p->data;
        p = p->next;
    }
    return max;
}

int recursiveMax(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT32_MIN;
    x = max(p->next);
    return x > p->data ? x : p->data;
}

struct Node *recursiveSearch(struct Node *p, int key)
{
    if (p == NULL)
        return NULL;
    if (key == p->data)
        return p;
    return recursiveSearch(p->next, key);
}

struct Node *optimisedSearch(struct Node *p, int key)
{
    struct Node *q = NULL;
    while (p != NULL)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
        }
        q = p;
        p = p->next;
    }
    return p;
}

void insertBefore(struct Node *p, int x)
{
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    p->next = first;
    first = p;
}

void insertAt(int index, int x)
{
    struct Node *t, *p;
    p = (struct Node *)malloc(sizeof(struct Node));
    p->data = x;
    if (index == 0)
    {
        p->next = first;
        first = p;
    }
    else
    {
        t = first;
        for (int i = 0; i < index - 1 && t; i++)
        {
            t = t->next;
        }
        if (t)
        {
            p->next = t->next;
            t->next = p;
        }
    }
}

void insertLast(int x)
{
    struct Node *t, *last;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
        first = last = t;
    else
    {
        last->next = t;
        last = t;
    }
}
void sortedInsert(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int deleteElement(struct Node *p, int index)
{
    struct node *q;
    int x = -1;
    if (index < 1 || index > count(p))
        ;
    return -1;
    if (index == 1)
    {
        q = first;
        x = first->data;
        first = first->next;
        free(q);
        return x;
    }
    else
    {

    }
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 7};
    create(A, 7);
    // printf("Printing the linked list using simple Display function: \t");
    // display(first);
    // printf("\nPrinting the linked list using recursive Display function: \t");
    // display(first);
    // int a = count(first);
    // printf("\nDisplaying the number of elements using normal Countfunction:\t %d", a);
    // int b = recursiveCount(first);
    // printf("\nDisplaying th number of elements using recursive Count function:\t %d", b);
    // int c = max(first);
    // printf("\nDisplaying the maximum element using Max function:\t %d", c);
    // int d = recursiveMax(first);
    // printf("\nDisplaying th number of elements using recursive Max function:\t %d", d);
    insertLast(5);
    display(first);
    printf("\nPrinting the linked list using recursive Display function: \t");
}