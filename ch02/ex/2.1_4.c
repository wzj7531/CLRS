#include<stdio.h>
#include<stdlib.h>

//2.1-4:二进制整数相加
int* Binary_Add(int a[],int b[],int n){
    int r = 0;
    int q = 0;
    int* c = (int*)malloc((n + 1) * sizeof(int));
    c[0] = 0;
    for(int i = n-1;i >=0;i--){
        c[i+1] = (a[i]+b[i]+q)%2;
        q = (a[i]+b[i]+q)/2;
    }
    c[0] = q;
    return c;
}

int main(){
    int a[] = {1,0,0,1,0,1,0,1};
    int b[] = {1,1,0,0,1,0,0,1};
    int* c = Binary_Add(a,b,8);
}