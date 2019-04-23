#include<stdlib.h>
#include<stdio.h>
/*
递归法的矩阵乘法,A,B代表两个子矩阵;
(m,n)代表A在原矩阵中的初始位置;
(h,k)代表B在原矩阵中的起始位置;
l代表子矩阵的每行或每列的元素个数,l*l即是A或B矩阵中元素的个数。
*/

const int A[4][4] = {{1,8,1,1},{1,4,1,6},{2,1,1,1},{8,1,3,4}};
const int B[4][4] = {{2,4,6,9},{1,3,1,5},{1,5,1,1},{1,9,1,1}};
static int C[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};

void square_matrix_multiply_recursive(int m, int n, int h, int k, int cnt){
    if(cnt == 1){
        C[m][k] += A[m][n] + B[h][k];
    }
    else{
        //A11*B11
        square_matrix_multiply_recursive(m,n,h,k,cnt/2);
        //A12*B21
        square_matrix_multiply_recursive(m,n+cnt/2,h+cnt/2,k,cnt/2);
        //A11*B12
        square_matrix_multiply_recursive(m,n,h,k+cnt/2,cnt/2);
        //A12*B22
        square_matrix_multiply_recursive(m,n+cnt/2,h+cnt/2,k+cnt/2,cnt/2);
        //A21*B11
        square_matrix_multiply_recursive(m+cnt/2,n,h,k,cnt/2);
        //A22*B21
        square_matrix_multiply_recursive(m+cnt/2,n+cnt/2,h+cnt/2,k,cnt/2);
        //A21*B12
        square_matrix_multiply_recursive(m+cnt/2,n,h,k+cnt/2,cnt/2);
        //A22*B22
        square_matrix_multiply_recursive(m+cnt/2,n+cnt/2,h+cnt/2,k+cnt/2,cnt/2);
    }
}

// int** square_matrix_multiply_recursive(int m,int n,int h,int k,int l){
//     int** C = (int**) malloc(l * sizeof(int*));
//     for(int i = 0; i < l; i++){
//         C[i] = (int*)malloc(l * sizeof(int));
//     }
//     if(l == 1){
//         C[0][0] = A[m][n] * B[h][k];
//     }
//     else{
//         //A11*B11
//         int** temp1 = square_matrix_multiply_recursive(m,n,h,k,l/2);
//         //A12*B21
//         int** temp2 = square_matrix_multiply_recursive(m,n+l/2,h+l/2,k,l/2);
//         //A11*B12
//         int** temp3 = square_matrix_multiply_recursive(m,n,h,k+l/2,l/2);
//         //A12*B22
//         int** temp4 = square_matrix_multiply_recursive(m,n+l/2,h+l/2,k+l/2,l/2);
//         //A21*B11
//         int** temp5 = square_matrix_multiply_recursive(m+l/2,n,h,k,l/2);
//         //A22*B21
//         int** temp6 = square_matrix_multiply_recursive(m+l/2,n+l/2,h+l/2,k,l/2);
//         //A21*B12
//         int** temp7 = square_matrix_multiply_recursive(m+l/2,n,h,k+l/2,l/2);
//         //A22*B22
//         int** temp8 = square_matrix_multiply_recursive(m+l/2,n+l/2,h+l/2,k+l/2,l/2);

//         for(int i = 0; i < l; i++){
//             for(int j = 0; j < l; j++){
//                 if(i<l/2){
//                     if(j<l/2){
//                         C[i][j] = temp1[i][j]+temp2[i][i];
//                     }
//                     else{
//                         C[i][j] = temp3[i][j-l/2]+temp4[i][j-l/2];
//                     }
//                 }
//                 else{
//                     if(j<l/2){
//                         C[i][j] = temp5[i-l/2][j]+temp6[i-l/2][j];
//                     }
//                     else{
//                         C[i][j] = temp7[i-l/2][j-l/2]+temp8[i-l/2][j-l/2];
//                     }
//                 }                
//             }
//         }   
//     }

//     for(int i = 0;i<l;i++){
//         for(int j = 0; j<l;j++){
//             printf("%d ",C[i][j]);
//         }
//         printf("\n");
//     }

//     return C;
// }

int main(){  
    square_matrix_multiply_recursive(0,0,0,0,4);
    for(int i = 0;i<4;i++){
        for(int j = 0; j<4;j++){
            printf("%-2d ",C[i][j]);
        }
        printf("\n");
    }
    return 0;
}