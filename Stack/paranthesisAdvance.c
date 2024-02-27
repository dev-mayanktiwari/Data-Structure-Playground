#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct stack {
    int size;
    int top;
    char *s;

}st;

void initializeStack(struct stack *st, char *a) {
    st->top=-1;
    st->size=strlen(a);
    st->s = (char *)malloc(st->size*sizeof(char));
}

void push(struct stack *st, char val) {
    if (st->top==st->size-1) printf("Stack Overflow\n");
    else {
        st->top++;
        st->s[st->top]=val;
    }   
}

void pop(struct stack *st) {
    char v;
    if(st->top==-1) printf("Stack Underflow\n");
    else {
        v = st->s[st->top--];
    }
}

int isEmpty(struct stack st) {
    return (st.top==-1) ? 1 : 0;
}

int parenthesisAdv(char *a) {
    for(int i=0; a[i]!='\0'; i++) {
        if (a[i]=='(' || a[i] == '{' || a[i]=='[') push(&st,a[i]);
        if (a[i]==']' || a[i] == '}' || a[i]==')') {
            if(isEmpty(st)) return 0;
            if(st.top==a[i]) pop(&st);
            if(st.top!=a[i]) return 0;
        }
    }
    return (isEmpty(st));

}

int main() {

    char *a = "[(a+n}*(a+c)]";

    initializeStack(&st,a);
    
    int x = parenthesisAdv(a);
    x ? printf("Valid") : printf("Invalid");
    
    return 0;
}