#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int priority;
    int value;
    struct Node *next;
} *head = NULL;

struct Node *createNode(int value)
{
    if (head == NULL)
}
struct Node *findNode(int priority)
{
    if (head == NULL)
        return head;
    struct Node *temp = head;
    while (temp != NULL)
    {
        if (temp->priority < priority)
            temp = temp->next;
        else
            break;
    }
    return temp;
}

int main()
{
}