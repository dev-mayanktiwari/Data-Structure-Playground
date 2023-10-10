#include <stdio.h>
#include <stdlib.h>

struct matrix {
    int A[10];
    int n;
};

void set(struct matrix *m, int i, int j, int x) {
    if (i == j && i >= 1 && i <= m->n) {
        m->A[i - 1] = x;
    }
}

void get(struct matrix m, int i, int j) {
    if (i == j && i >= 1 && i <= m.n) {
        printf("%d ", m.A[i - 1]);
    }
    else {
        printf("0 ");
    }
}

void display(struct matrix m) {
    for (int i = 1; i <= m.n; i++) {
        for (int j = 1; j <= m.n; j++) {
            if (i == j) {
                printf("%d ", m.A[i - 1]);
            }
            else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    struct matrix m;
    int n;
    printf("Enter the dimension of the matrix: \n");
    scanf("%d", &n);
    if (n < 0 || n > 10) {
        printf("Invalid dimension.\n");
        return 1;
    }
    else {
        m.n = n;
    }
    printf("Enter the diagonal elements: \n");
    for (int i = 1; i <= n; i++) {
        int x;
        printf("Element at position (%d,%d): ", i, i);
        scanf("%d", &x);
        set(&m, i, i, x);
    }
    printf("The matrix is: \n");
    display(m);

    return 0;
}
