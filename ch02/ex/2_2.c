#include<stdio.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//2-2:冒泡排序
void Bubble_Sort(int a[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = length; j > i; j--){
            if(a[j-1] > a[j]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j - 1] = temp;
            }
        }
    }
}

int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    Bubble_Sort(a, 6);
    printArray(a, 6);
    return 0;
}