#include<stdio.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}


int partition(int * A,int p,int r){
    int x = A[r];
    int i = p-1;
    for(int j = p; j < r; j++){
        if(A[j] <= x){
            i++;
            int temp = A[j];
            A[j] = A[i];
            A[i] = temp;
        }
    }
    int temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
    return i + 1;
}

void quicksort(int* A,int p,int r){
    if(p < r){
        int q = partition(A,p,r);
        quicksort(A, p, q-1);
        quicksort(A, q + 1, r);
    }
}

int main(){
    //int A[] = {2, 8, 7, 1, 3, 5, 6, 4};
    int A[] = {2, 2, 2, 2, 2, 2, 2, 2};
    quicksort(A, 0, 7);
    printArray(A,8);
}