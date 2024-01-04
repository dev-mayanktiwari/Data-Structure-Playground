#include <stdio.h>
#include <stdlib.h>

struct edgeList;
struct nodeList;

struct edgeList
{
    struct nodeList *next;
    struct edgeList *nextEdge;
};

struct nodeList
{
    int info;
    struct nodeList *nextNode;
    struct edgeList *edge;
};

struct nodeList *head = NULL;

struct nodeList *createNode(int data)
{
    struct nodeList *newNode = (struct nodeList *)malloc(sizeof(struct nodeList));
    newNode->info = data;
    newNode->nextNode = NULL;
    newNode->edge = NULL;
    return newNode;
}

struct nodeList *findNode(struct nodeList *start, int value)
{
    struct nodeList *currentNode = start;
    while (currentNode != NULL)
    {
        if (currentNode->info == value)
            return currentNode;
        currentNode = currentNode->nextNode;
    }
    return NULL;
}

void addEdge(struct nodeList *start, int startValue, int targetValue)
{
    struct nodeList *startNode = findNode(start, startValue);
    struct nodeList *targetNode = findNode(start, targetValue);

    if (startNode != NULL && targetNode != NULL)
    {
        struct edgeList *newEdge = (struct edgeList *)malloc(sizeof(struct edgeList));
        newEdge->next = targetNode;
        newEdge->nextEdge = NULL;

        struct edgeList *lastEdge = startNode->edge;
        if (lastEdge == NULL)
            startNode->edge = newEdge;
        else
        {
            while (lastEdge->nextEdge != NULL)
            {
                lastEdge = lastEdge->nextEdge;
            }
            lastEdge->nextEdge = newEdge;
        }
    }
    else
    {
        printf("One or both nodes not found.\n");
    }
}

void addNode(int value)
{
    struct nodeList *newNode = createNode(value);
    struct nodeList *lastNode = head;
    if (lastNode == NULL)
        head = newNode;
    else
    {
        while (lastNode->nextNode != NULL)
        {
            lastNode = lastNode->nextNode;
        }
        lastNode->nextNode = newNode;
    }
}

void displayGraph()
{
    struct nodeList *node = head;
    while (node != NULL)
    {
        printf("Node %d -> ", node->info);

        struct edgeList *edge = node->edge;
        while (edge != NULL)
        {
            printf("%d ", edge->next->info);
            edge = edge->nextEdge;
        }

        printf("\n");
        node = node->nextNode;
    }
}

int main()
{
    char choice;

    do
    {
        int nodeValue;
        printf("Enter the value for the new node: ");
        scanf("%d", &nodeValue);
        addNode(nodeValue);

        printf("Do you want to add another node? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    struct nodeList *currentNode = head;
    while (currentNode != NULL)
    {
        printf("\nEnter edges for Node %d:\n", currentNode->info);

        do
        {
            int edgeValue;
            printf("Enter an edge value for the current node (or -1 to finish): ");
            scanf("%d", &edgeValue);

            if (edgeValue != -1) addEdge(head, currentNode->info, edgeValue);
            else  break; 

            printf("Do you want to add another edge for the current node? (y/n): ");
            scanf(" %c", &choice);

        } while (choice == 'y' || choice == 'Y');

        currentNode = currentNode->nextNode;
    }

    printf("\nGraph:\n");
    displayGraph();

    return 0;
}

