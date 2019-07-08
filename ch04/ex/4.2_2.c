#include<stdlib.h>
#include<stdio.h>

/*
递归法的矩阵乘法,A,B代表两个子矩阵;
(m,n)代表A在原矩阵中的初始位置;
(h,k)代表B在原矩阵中的起始位置;
l代表子矩阵的每行或每列的元素个数,l*l即是A或B矩阵中元素的个数。
*/

// const int A[4][4] = {{1,8,1,1},{1,4,1,6},{2,1,1,1},{8,1,3,4}};
// const int B[4][4] = {{2,4,6,9},{1,3,1,5},{1,5,1,1},{1,9,1,1}};
// static int C[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

int* matrix_add(int cnt,int cnt_A,int cnt_B,int* A,int* B,int m,int n,int h,int k,int factor){
    int * C = (int*)malloc(sizeof(int) * cnt * cnt);
    
    for(int i = 0; i < cnt;i++){
        for(int j=0;j < cnt;j++){
            C[i*cnt+j] = A[(m+i)*cnt_A + n + j] + factor * B[(h+i) * cnt_B + k + j];           
        }
    }
    return C;
}

int* square_matrix_multiply_strassen(int cnt,int cnt_A,int cnt_B,int* A,int* B,int m, int n, int h, int k){
    int* C = (int*)malloc(sizeof(int) * cnt * cnt);
    if(cnt == 1){
        C[0] = A[m*cnt_A + n] * B[h*cnt_B+k];
    }
    else{
        //Step2 calculate S1,S2,...,S10
        int* S1  = matrix_add(cnt/2, cnt_B,cnt_B, B, B, h,       k+cnt/2,h+cnt/2,k+cnt/2,-1);
        int* S2  = matrix_add(cnt/2, cnt_A,cnt_A, A, A, m,       n,      m,      n+cnt/2, 1);
        int* S3  = matrix_add(cnt/2, cnt_A,cnt_A, A, A, m+cnt/2, n,      m+cnt/2,n+cnt/2, 1);
        int* S4  = matrix_add(cnt/2, cnt_B,cnt_B, B, B, h+cnt/2, k,      h,      k,      -1);
        int* S5  = matrix_add(cnt/2, cnt_A,cnt_A, A, A, m,       n,      m+cnt/2,n+cnt/2, 1);
        int* S6  = matrix_add(cnt/2, cnt_B,cnt_B, B, B, h,       k,      h+cnt/2,k+cnt/2, 1);
        int* S7  = matrix_add(cnt/2, cnt_A,cnt_A, A, A, m,       n+cnt/2,m+cnt/2,n+cnt/2,-1);
        int* S8  = matrix_add(cnt/2, cnt_B,cnt_B, B, B, h+cnt/2, k,      h+cnt/2,k+cnt/2, 1);
        int* S9  = matrix_add(cnt/2, cnt_A,cnt_A, A, A, m,       n,      m+cnt/2,n,      -1);
        int* S10 = matrix_add(cnt/2, cnt_B,cnt_B, B, B, h,       k,      h,      k+cnt/2, 1);
        //Step3 recursive calculate P1,P2,...P7
        int* P1 = square_matrix_multiply_strassen(cnt/2,cnt_A,cnt/2,A,S1,m,n,0,0);
        int* P2 = square_matrix_multiply_strassen(cnt/2,cnt/2,cnt_B,S2,B,0,0,h+cnt/2,k+cnt/2);
        int* P3 = square_matrix_multiply_strassen(cnt/2,cnt/2,cnt_B,S3,B,0,0,h,k);
        int* P4 = square_matrix_multiply_strassen(cnt/2,cnt_A,cnt/2,A,S4,m+cnt/2,n+cnt/2,0,0);
        int* P5 = square_matrix_multiply_strassen(cnt/2,cnt/2,cnt/2,S5,S6,0,0,0,0);
        int* P6 = square_matrix_multiply_strassen(cnt/2,cnt/2,cnt/2,S7,S8,0,0,0,0);
        int* P7 = square_matrix_multiply_strassen(cnt/2,cnt/2,cnt/2,S9,S10,0,0,0,0);

        int* temp1 = matrix_add(cnt/2,cnt/2,cnt/2,P5,P4,0,0,0,0,1);
        int* temp2 = matrix_add(cnt/2,cnt/2,cnt/2,P2,P6,0,0,0,0,-1);
        int* temp3 = matrix_add(cnt/2,cnt/2,cnt/2,P5,P1,0,0,0,0,1);
        int* temp4 = matrix_add(cnt/2,cnt/2,cnt/2,P3,P7,0,0,0,0,1);

        int* C11 = matrix_add(cnt/2,cnt/2,cnt/2,temp1,temp2,0,0,0,0,-1);
        int* C12 = matrix_add(cnt/2,cnt/2,cnt/2,P1,P2,0,0,0,0,1);
        int* C21 = matrix_add(cnt/2,cnt/2,cnt/2,P3,P4,0,0,0,0,1); 
        int* C22 = matrix_add(cnt/2,cnt/2,cnt/2,temp3,temp4,0,0,0,0,-1);

        for(int i = 0; i < cnt; i++){
            for(int j = 0; j < cnt; j++){
                if(i < cnt / 2 && j < cnt / 2){
                    C[i*cnt + j] = C11[i*(cnt/2) + j];
                }              
                else if(i < cnt / 2 && j < cnt){
                    C[i*cnt + j] = C12[i*(cnt/2) + j - cnt / 2 ];
                } 
                else if(i < cnt && j < cnt / 2){
                    C[i*cnt + j] = C21[(i-cnt / 2) * (cnt / 2) + j];
                }
                else if(i < cnt && j < cnt){
                    C[i*cnt + j] = C22[(i-cnt / 2) * (cnt / 2) + j - cnt / 2];
                }
            }
        }
    }
    return C;
}

int main(){
    int A[16] = {1,8,1,1,1,4,1,6,2,1,1,1,8,1,3,4};
    int B[16] = {2,4,6,9,1,3,1,5,1,5,1,1,1,9,1,1};
    int* C = square_matrix_multiply_strassen(4,4,4,A,B,0,0,0,0);
    for(int i = 0;i<4;i++){
        for(int j = 0; j<4;j++){
            printf("%2d ",C[i*4+j]);
        }
        printf("\n");
    }
}

