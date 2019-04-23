#include<stdio.h>
#include<limits.h>
#include<stdlib.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//????
void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*)malloc((n1 + 1) * sizeof(int));
    int* R = (int*)malloc((n2 + 1) * sizeof(int));

    for(int i = 0; i < n1 ; i++)
    {
        L[i] = a[p + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

   int i = 0;
   int j = 0;

    for(int k = p; k <= r; k++)
    {
        if(R[i] <= L[j])
        {
            a[k] = R[i];
            i++;
        }
        else
        {
            a[k] = L[j];
            j++;
        }
    }
}

void merge_sort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    merge_sort(a, 0, 5);
    printArray(a, 6);
    return 0;
}