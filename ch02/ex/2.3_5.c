#include<stdio.h>

//2.3-5:二分查找法
int BinarySearch(int key,int a[],int low,int high){
    if(low > high) return low;
    int mid = low + (high - low) / 2;
    if(key < a[mid]) return BinarySearch(key,a,low,mid - 1);
    else if(key > a[mid]) return BinarySearch(key,a,mid+1,high);
    else return low;  
}

int main(){
    int a[9] = {5,2,4,6,1,3};       
    printf("After sorting\n");
    BinarySearch(2,a,0,5);   
    return 0;
}