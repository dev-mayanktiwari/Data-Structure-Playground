#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack {
    int top;
    int size;
    char *S;
}st;

void initializeStack(struct Stack *st, char *a) {
    st->top=-1;
    st->size=strlen(a);
    st->S= (char *)malloc(st->size * sizeof(char));
}

void push(struct Stack *st, char val) {
    if(st->top==st->size-1) printf("Stack Overflow\n");
    else {
        st->top++;
        st->S[st->top]=val;
    }
}

void pop(struct Stack *st) {
    int x;
    if(st->top==-1) printf("Stack Underflow");
    else {
        x = st->S[st->top--];
    }
}

int isEmpty(struct Stack st) {
    if(st.top==-1) return 1;
    return 0;
}

int validParantheses(char *a) {


    for(int i=0; a[i]!='\0'; i++) {
        if (a[i]=='(') push(&st,'(');
        if (a[i]==')') {
            if (isEmpty(st)) return 0;
            else {
                pop(&st);
            }
        }
    }
    if (isEmpty(st)) return 1;
    return 0;
}

int main() {
    char *a = "((a+b*(c+d))";

    initializeStack(&st, a);
    int ans = validParantheses(a);

    if(ans) printf("Valid paranthesis\n");
    else printf("Invalid parantheses\n");
    
    return 0;
}