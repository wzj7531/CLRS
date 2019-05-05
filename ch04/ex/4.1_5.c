#include<stdio.h>
#include<stdlib.h>

int* find_maxiumu_subarray_Linear (int* A, int length){
    int left = 0;
    int right = 0;   
    int temp_sum = A[0];
    int max_sum = temp_sum;

    for (int j = 1; j < length; j++){
        temp_sum += A[j];
        if(max_sum < temp_sum){
            right = j;
            max_sum = temp_sum;
        }
        else{
            if(A[j] > temp_sum){
                left = j;
                right = j;
                temp_sum = A[j];
                max_sum = temp_sum;
            }
        }
    }    

    int* retArray = (int*)malloc(3 * sizeof(int));
    retArray[0] = left;
    retArray[1] = right;
    retArray[2] = max_sum;
    return retArray;
}

int main(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};   
    int* ret = find_maxiumu_subarray_Linear(A, 15);
    printf("%d,%d,%d",ret[0],ret[1],ret[2]);
    return 0;
}