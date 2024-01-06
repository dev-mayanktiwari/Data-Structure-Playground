#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node *leftChild;
    int data;
    struct Node *rightChild;
};

struct Queue
{
    struct Node *data;
    struct Queue *next;
};

struct Node *createNode(int val)
{
    struct Node *tempNode = (struct Node *)malloc(sizeof(struct Node));
    if (tempNode == NULL)
    {
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    tempNode->leftChild = NULL;
    tempNode->rightChild = NULL;
    tempNode->data = val;
    return tempNode;
}

struct Queue *createQueue()
{
    struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
    if (queue == NULL)
    {
        printf("Memory allocation failed.");
        exit(EXIT_FAILURE);
    }
    queue->data = NULL;
    queue->next = NULL;
    return queue;
}

void enqueue(struct Queue **rear, struct Node *node)
{
    struct Queue *queueNode = (struct Queue *)malloc(sizeof(struct Queue));
    if (queueNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    queueNode->data = node;
    queueNode->next = NULL;

    if (*rear == NULL)
    {
        *rear = queueNode;
    }
    else
    {
        (*rear)->next = queueNode;
        *rear = queueNode;
    }
}

struct Node *dequeue(struct Queue **front)
{
    if (*front == NULL)
    {
        return NULL;
    }

    struct Queue *temp = *front;
    struct Node *node = temp->data;
    *front = temp->next;

    free(temp);

    return node;
}

struct Node *createTree()
{
    int value;
    printf("Enter the root value: ");
    scanf("%d", &value);

    struct Node *root = createNode(value);
    struct Queue *queue = createQueue();
    struct Queue *rear = queue;

    enqueue(&rear, root);

    while (queue != NULL)
    {
        struct Node *currentNode = dequeue(&queue);

        char hasRightChild, hasLeftChild;

        printf("Does this node %d has left child (y/n) ?", currentNode->data);
        scanf(" %c", &hasLeftChild);

        if (hasLeftChild == 'y' || hasLeftChild == 'Y')
        {
            int leftValue;
            printf("Enter the value for left child: ");
            scanf("%d", &leftValue);
            currentNode->leftChild = createNode(leftValue);
            enqueue(&rear, currentNode->leftChild);
        }

        printf("Does this node %d has right child (y/n) ?", currentNode->data);
        scanf(" %c", &hasRightChild);

        if (hasRightChild == 'y' || hasRightChild == 'Y')
        {
            int rightValue;
            printf("Enter the value for right child: ");
            scanf("%d", &rightValue);
            currentNode->rightChild = createNode(rightValue);
            enqueue(&rear, currentNode->rightChild);
        }
    }

    free(queue);

    return root;
}

void inorderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inorderTraversal(root->leftChild);
        printf("%d ", root->data);
        inorderTraversal(root->rightChild);
    }
}

int main()
{
    struct Node *root = createTree();

    printf("The inorder traversal of the given tree is: \n");
    inorderTraversal(root);

    return 0;
}
