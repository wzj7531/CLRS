#include<stdlib.h>
#include<stdio.h>
#include <limits.h>
#include <math.h>

int* find_max_crossing_subarray(int* a,int low,int mid,int high){
    int *retArray= (int *)malloc(3 * sizeof(int));

    int max_left = low;
    int max_right = high;

    int left_sum = INT_MIN;
    int right_sum = INT_MIN;

    int temp_sum = 0;    
    for(int i = mid;i >= low;i--){
        temp_sum += a[i];
        if(temp_sum > left_sum){
            left_sum = temp_sum;
            max_left = i;
        }
    }

    temp_sum = 0;
    for(int i = mid + 1; i <= high; i++){
        temp_sum += a[i];
        if(temp_sum > right_sum){
            right_sum = temp_sum;
            max_right = i;
        }
    }

    retArray[0] = max_left;
    retArray[1] = max_right;
    retArray[2] = left_sum + right_sum;

    return retArray;
}

//递归方式求解最大子数组问题
int* find_maximum_subarray(int* a,int low,int high){
    int *retArray= (int *)malloc(3 * sizeof(int));
    if(low == high){
        retArray[0] = low;
        retArray[1] = high;
        retArray[2] = a[low];
    }
    else{
            int mid = (low + high) / 2;
            int* ret_left = find_maximum_subarray(a, low, mid);
            int* ret_right = find_maximum_subarray(a, mid + 1, high);
            int* ret_middle = find_max_crossing_subarray(a, low, mid, high);
            if(ret_left[2] > ret_right[2] && ret_left[2] > ret_middle[2]){
                retArray[0] = ret_left[0];
                retArray[1] = ret_left[1];
                retArray[2] = ret_left[2];
            }
            else if(ret_right[2] > ret_left[2] && ret_right[2] > ret_middle[2]){
                retArray[0] = ret_right[0];
                retArray[1] = ret_right[1];
                retArray[2] = ret_right[2];
            }
            else{
                retArray[0] = ret_middle[0];
                retArray[1] = ret_middle[1];
                retArray[2] = ret_middle[2];
            }
        }
    return retArray;
}

int main(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};    
    int* ret = find_maximum_subarray(A, 0, 15);
    printf("%d,%d,%d",ret[0],ret[1],ret[2]);
}