#include<stdio.h>
#include<stdlib.h>

//4-1-2: 暴力求解最大子数组问题
int* find_maximum_subarray_violence(int* A,int length){
    int* retArray = (int*)malloc(3 * sizeof(int));

    int max_sum = A[0];
    int temp_sum = 0;
    int left = 0;
    int right = 0;

    for(int i = 0; i < length - 1; i++){
        temp_sum = A[i];      
        for(int j = i + 1; j < length; j++){
            temp_sum += A[j];
            if(temp_sum > max_sum){
                max_sum = temp_sum;
                left = i;
                right = j;
            }
        }
    }

    retArray[0] = left;
    retArray[1] = right;
    retArray[2] = max_sum;

    return retArray;
}

int main(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};    
    int* ret = find_maximum_subarray_violence(A, 16);
    printf("%d,%d,%d",ret[0],ret[1],ret[2]);
}