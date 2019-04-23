#include<stdio.h>
#include<stdlib.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//2.3-2:不使用哨兵的归并排序
void merge_with_no_guard(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = L[i];
        i++;
    }

    while(j < n2)
    {
        a[k] = R[j];
        j++;
    }
}

void merge_sort_with_no_guard(int a[],int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort_with_no_guard(a, p, q);
        merge_sort_with_no_guard(a, q + 1, r);
        merge_with_no_guard(a, p, q, r);
    }
}

int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    merge_sort_with_no_guard(a, 0, 5);
    printArray(a, 6);
    return 0;
}