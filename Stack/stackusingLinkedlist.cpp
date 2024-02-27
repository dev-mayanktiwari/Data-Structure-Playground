#include<stdio.h>
#include<stdlib.h>

using namespace std;

struct Node {
    int data;
    struct Node *next;
}*top = nullptr;

void push(int val) {
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t==nullptr) printf("Stack Overflow\n");
    else {
        t->data=val;
        t->next=top;
        top=t;
    }
}

int pop() {
    int x;
    struct Node *t;
    if (top==nullptr) printf("Stack Underflow\n");
    else {
        t = top;
        x = t->data;
        top=top->next;
        free(t);
    }
    return x;
}

void display() {
    struct Node *p;
    p = top;

    while (p!=nullptr) {
        printf("%d ", p->data);
        p=p->next;
    }
}

int main () {
    struct Node *stack;

    push(20);
    push(30);
    push(40);

    display();
    
    return 0;
}