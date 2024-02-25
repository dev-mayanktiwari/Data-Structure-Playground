#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int top;
    int size;
    int *s;
};

void createStack(struct Stack *st)
{
    printf("Enter the size of the stack: ");
    scanf("%d", &st->size);
    st->top = -1;
    st->s = (int *)malloc(st->size * sizeof(int));
}

int isEmpty(struct Stack st)
{
    if (st.top == -1)
        return 1;
    else
        return 0;
}

int isFull(struct Stack st)
{
    if (st.top == st.size - 1)
        return 1;
    else
        return 0;
}

void push(struct Stack *st, int val)
{

    if (st->top == st->size - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        st->s[st->top] = val;
        st->top++;
    }
}

int pop(struct Stack *st)
{
    int x = -1;
    if (st->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        x = st->s[st->top];
    }
    return x;
}

int peek(struct Stack st, int pos)
{
    int x = -1;
    if (st.top - pos + 1 < 0)
        printf("Invalid position\n");
    else
    {
        x = st.s[st.top - pos + 1];
    }
    return x;
}

int main()
{
    struct Stack st;
    createStack(&st);
    int ch;
    char choice = 'y';

    do
    {
        printf("Enter your choice :\n1. Push \n2. Pop \n3. Peek \n");
        scanf("%d", &ch);

        int val, x, z;

        switch (ch)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            push(&st, val);
            break;

        case 2:
            x = pop(&st);
            if (x != -1)
            {
                printf("The popped value is %d\n", x);
            }
            break;

        case 3:
            printf("Enter the position to look at: ");
            scanf("%d", &z);
            int x = peek(st, z);
            if (x != -1)
            {
                printf("The value at index %d is %d\n", z, x);
            }
            break;

        default:
            printf("Invalid choice.\n");
            break;

        }
        
        printf("Want to enter more?? (Y/N) ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}