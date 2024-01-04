#include<stdio.h>
#include<stdlib.h>

struct array {
    int *A;
    int size;
    int length;
};

void display (struct array arr) {
    printf("Elements are: \n");
    for (int i=0; i<arr.length; i++) {
        printf("%d ", arr.A[i]);
    }
}

void append (struct array *arr, int x) {
    if (arr->length < arr->size) {
        arr->A[arr->length++] = x;
    }
}

void insert (struct array *arr, int index, int x) {
    int i;
    if (index>=0 && index<=arr->length) {
        for (i=arr->length;i>index;i--) 
            arr->A[i]=arr->A[i-1];
        arr->A[index]=x;
        arr->length++;   
    }  
}

int delete (struct array *arr, int index) {
    int x=0;
    int i;
    x=arr->A[index];
    for (i=index;i<arr->length-1;i++) {
        arr->A[i]=arr->A[i+1];
    }
    printf("Element deleted Successfuly.\n");
    arr->length--;
    return x;
}

void swap (int *x, int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}


int main () {


}