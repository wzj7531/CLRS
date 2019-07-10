#include<stdio.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//2.2-2：选择排序
void selection_sort(int a[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < length; j++)
        {
            if(a[index] > a[j])
            {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

int main(){
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    selection_sort(a, 6);
    printArray(a, 6);
    return 0;
}