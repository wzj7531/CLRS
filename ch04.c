#include "ch04.h"

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
            int mid = floor((low + high) / 2);
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

//4-1-3:找到暴力求解和递归求解的时间分离点


void test_find_maximum_subarray(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};    
    int* ret = find_maximum_subarray(A, 0, 15);
    printf("%d,%d,%d",ret[0],ret[1],ret[2]);
}

void test_find_maximum_subarray_violence(){
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};   
    int* ret = find_maximum_subarray_violence(A, 15);
    printf("%d,%d,%d",ret[0],ret[1],ret[2]);
}

void test_time_violence_recurse()
{
    int begintime,endtime;
    int A[] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};

    //递归方式时间测试
    begintime = clock();
    find_maximum_subarray(A,0,7);
    endtime = clock();
    printf("Recurse way:%dms\n",endtime - begintime);

    //暴力方式时间测试
    begintime=clock();
    find_maximum_subarray_violence(A,7);
    endtime = clock();
    printf("violence:%dms\n",endtime - begintime);
}

int main(){
    //递归方式求解最大子数组测试
    test_find_maximum_subarray();
    //4-1-2:暴力方式求解最大子数组测试
    //test_find_maximum_subarray_violence();
    //4-1-3:暴力方式和递归方式求解最大子数组分别所需的时间
    //test_time_violence_recurse();
}
