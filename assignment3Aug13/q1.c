/*
Write a C programme to take input numebr in A(2x2) and B(2x2) matrix.
Find the Sum of A and B and store in C(2x2) matrix.
Print A , B and C
*/

#include<stdio.h>

void inputMatrix(int mat[2][2] , int nrows , int nclms){
    printf("Enter elements Row wise :\n");
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nclms;j++){
            printf("Enter element at row %d column %d :",i,j);
            scanf("%d",&mat[i][j]);
        }
    }
}

void sumMatrix(int res[2][2] , int mat1[2][2] , int mat2[2][2] , int nrows , int nclms){
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nclms;j++){
            res[i][j]=mat1[i][j] + mat2[i][j];
        }
    }
}


void printMatrix(int mat[2][2] , int nrows , int nclms){
    for(int i=0;i<nrows;i++){
        for(int j=0;j<nclms;j++){
            printf("%d ",mat[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int nrows,nclms;
    printf("Enter how many rows and columns in matrix : ");
    scanf("%d %d",&nrows,&nclms);
    int A[nrows][nclms];
    int B[nrows][nclms];
    int C[nrows][nclms];
    printf("Enter Matrix A :\n");
    inputMatrix(A,nrows,nclms);
    printf("\nEnter Matrix B : \n");
    inputMatrix(B,nrows,nclms);
    sumMatrix(C,A,B,nrows,nclms);
    printf("Printing Matrices :\n");
    printf("Matrix A : \n");
    printMatrix(A,nrows,nclms);
    printf("\nMAtrix B :\n");
    printMatrix(B,nrows,nclms);
    printf("\nMatrix C :\n");
    printMatrix(C,nrows,nclms);
    printf("\n");
    return 0;
}