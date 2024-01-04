#include <stdio.h>
#include <stdlib.h>

// General Functions

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int lomutopartition(int a[], int low, int high)
{
    int pivot = a[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++)
    {
        if (a[j] < pivot)
        {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i + 1], &a[high]);
    return (i + 1);
}

void merge(int a[], int low, int mid, int high)
{
    int i = low, j = mid + 1, k = low;
    int b[high + 1];
    while (i <= mid && j <= high)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    for (; i <= mid; i++)
        b[k++] = a[i];
    for (; j <= high; j++)
        b[k++] = a[j];
    for (int i = low; i <= high; i++)
        a[i] = b[i];
}

// Sorting Functions

void bubblesort(int a[], int n)
{
    int flag;
    for (int i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
            flag = 1;
        }
        if (flag == 0)
            break;
    }
}

void insertionsort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = a[i];
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

void selectionsort(int a[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (a[j] < a[k])
                k = j;
        }
        swap(&a[k], &a[i]);
    }
}

void merge_sort(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = low + (high - low) / 2;
        merge_sort(a, low, mid);
        merge_sort(a, mid + 1, high);
        merge(a, low, mid, high);
    }
}

void quicksort(int a[], int l, int h)
{
    if (l < h)
    {
        int pind = lomutopartition(a, l, h);
        quicksort(a, l, pind - 1);
        quicksort(a, pind + 1, h);
    }
}

void countsort(int a[], int n, int k)
{
    int count[k];
    for (int i = 0; i < k; i++)
        count[i] = 0;
    for (int i = 0; i < n; i++)
        count[a[i]]++;
    for (int i = 1; i < k; i++)
        count[i] = count[i - 1] + count[i];
    int output[n];
    for (int i = n - 1; i >= 0; i--)
    {
        output[count[a[i]] - 1] = a[i];
        count[a[i]]--;
    }
    for (int i = 0; i < n; i++)
        a[i] = output[i];
}

int main()
{
    int a[100];
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array separated by spaces: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    countsort(a, 5, 5);
    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}