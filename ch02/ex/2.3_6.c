#include<stdio.h>

//2.3-6:插入排序使用二分查找
void Insertion_Sort_BS(int a[],int length){
    for(int j = 1; j < length; j++){
        int key = a[j];
        int i = j - 1;
        int index = BinarySearch(key,a,0,i);
        if(a[index] < key){
           index++;
        }
        while(i >= index){
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

int main(){
    int a[9] = {5,2,4,6,1,3};       
    printf("After sorting\n");
    Insertion_Sort_BS(a,6);   
    return 0;
}