#include<stdio.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//插入排序
void insert_sort(int a[], int length)
{
    for(int j = 1; j < length; j++)
    {
        int key = a[j];
        int i = j - 1;
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    insert_sort(a, 6);
    printArray(a, 6);
}