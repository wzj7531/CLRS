#include<stdio.h>

int minimum(int A[],int lenth){
    int min = A[0];
    for(int i = 1; i < lenth; i++){
        if(min > A[i]){
            min = A[i];
        }
    }
    return min;
}

int main(){
    int A[] = {2,5,6,1,8,9,22,13,15};
    int min = minimum(A,9);
}