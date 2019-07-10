#include <stdio.h>
#include <stdlib.h>

 count_sort(int* A,int* B,int n,int k){
    int* C = (int*)malloc((k + 1) * sizeof(int));
    for(int i = 0; i <= k; i++){
        C[i] = 0;
    }
    for(int i = 0; i < n; i++){
        C[A[i]] = C[A[i]] + 1;
    }
    for(int i = 1; i <= k; i++){
        C[i] = C[i] + C[i-1];
    }
    for(int j = n - 1; j >= 0; j--){
        B[C[A[j]]-1] = A[j];
        C[A[j]] = C[A[j]] - 1;
    } 
}

int main(){
    int A[] = {2,5,3,0,2,3,0,3};
    int B[8];
    count_sort(A,B,8,5);
}