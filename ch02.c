#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void printArray(int a[], int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%d",a[i]);
    }
    printf("\n");
}

//插入排序
void insert_sort(int a[], int length)
{
    for(int j = 1; j < length; j++)
    {
        int key = a[j];
        int i = j - 1;
        while(i > -1 && a[i] > key)
        {
            a[i+1] = a[i];
            i--;
        }
        a[i+1] = key;
    }
}

//归并排序
void merge(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*)malloc((n1 + 1) * sizeof(int));
    int* R = (int*)malloc((n2 + 1) * sizeof(int));

    for(int i = 0; i < n1 ; i++)
    {
        L[i] = a[p + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }

    L[n1] = INT_MAX;
    R[n2] = INT_MAX;

   int i = 0;
   int j = 0;

    for(int k = p; k <= r; k++)
    {
        if(R[i] <= L[j])
        {
            a[k] = R[i];
            i++;
        }
        else
        {
            a[k] = L[j];
            j++;
        }
    }
}

void merge_sort(int a[], int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort(a, p, q);
        merge_sort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

//2.1-3：
int Linear_Find(int a[],int length,int key){
    for(int i = 0;i < length;i++){
        if(a[i] == key)
            return i;       
    }
    return -1;
}

//2.1-4:二进制整数相加
void Binary_Add(int a[],int b[],int c[],int length){
    auto r = 0;
    auto q = 0;
    for(auto i = length-1;i >=0;i--){
        c[i+1] = (a[i]+b[i]+q)%2;
        q = (a[i]+b[i]+q)/2;
    }
    c[0] = q;
}

//2.2-2：选择排序
void selection_sort(int a[], int length)
{
    for(int i = 0; i < length - 1; i++)
    {
        int index = i;
        for(int j = i + 1; j < length; j++)
        {
            if(a[index] > a[j])
            {
                index = j;
            }
        }
        int temp = a[i];
        a[i] = a[index];
        a[index] = temp;
    }
}

//2.3-2:不使用哨兵的归并排序
void merge_with_no_guard(int a[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;

    int* L = (int*)malloc(n1 * sizeof(int));
    int* R = (int*)malloc(n2 * sizeof(int));

    for(int i = 0; i < n1; i++)
    {
        L[i] = a[p + i];
    }

    for(int j = 0; j < n2; j++)
    {
        R[j] = a[q + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        a[k] = L[i];
        i++;
    }

    while(j < n2)
    {
        a[k] = R[j];
        j++;
    }
}

void merge_sort_with_no_guard(int a[],int p, int r)
{
    if(p < r)
    {
        int q = (p + r) / 2;
        merge_sort_with_no_guard(a, p, q);
        merge_sort_with_no_guard(a, q + 1, r);
        merge_with_no_guard(a, p, q, r);
    }
}

//2.3-4:插入排序的递归版本
void Insert(int a[],int p){
    int key = a[p];
    int i = p - 1;
    while(i>=0 && a[i] > key){
        a[i+1] = a[i];
        i--;
    }
    a[i+1] = key;
}

void InsertSort_Cursor(int a[],int p){
    if(p >= 1){
        InsertSort_Cursor(a,p-1);
        Insert(a,p);
    }
}
//2.3-5:二分查找法
int BinarySearch(int key,int a[],int low,int high){
    if(low > high) return low;
    int mid = low + (high - low) / 2;
    if(key < a[mid]) return BinarySearch(key,a,low,mid - 1);
    else if(key > a[mid]) return BinarySearch(key,a,mid+1,high);
    else return mid;  
}

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

//2-2:冒泡排序
void Bubble_Sort(int a[], int length){
    for(int i = 0; i < length - 1; i++){
        for(int j = length; j > i; j--){
            if(a[j-1] > a[j]){
                int temp = a[j];
                a[j] = a[j-1];
                a[j - 1] = temp;
            }
        }
    }
}

int main()
{
    int a[] = {5, 2, 4, 7, 1, 3, 2, 6};

    printf("Before sorting...\n");
    printArray(a, 8);

    merge_sort_with_no_guard(a, 0, 7);

    printf("After sorting...\n");
    printArray(a, 8);

    return 1;
}






int main()
{
    int a[9] = {5,2,4,6,1,3};
    printf("Before sorting\n");
    printArray(a, 6);
    printf("After sorting\n");
    insert_sort(a, 6);
    printArray(a, 6);
}
