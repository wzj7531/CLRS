#include<stdio.h>

//2.3-4:插入排序的递归版本
void Insert(int a[],int p){
    int key = a[p];
    int i = p - 1;
    while(i>=0 && a[i] > key){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = key;
}

void InsertSort_ReCursive(int a[],int p){
    if(p >= 1){
        InsertSort_Cursor(a,p-1);
        Insert(a,p);
    }
}

int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    InsertSort_ReCursive(a, 5);
    printArray(a, 6);
    return 0;
}