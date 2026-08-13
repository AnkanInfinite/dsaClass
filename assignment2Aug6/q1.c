/*
Write a program to take input in an array 10 unordered number and apply QuickSort to order the array in ascending order.
Input: Array size = 10;
       Array Items :- [8,2,10,6,5,12,18,9,4,11]
*/

#include <stdio.h>

void swap(int* a , int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void quickSort(int arr[],int low,int high){
    if(low>=high)return;
    int i=low;
    int j=high;
    int pIndex=low;
    while(i<j){
        while(i<=high && arr[low]>=arr[i]){
            i++;

        }
        while(j>=low && arr[low]<arr[j]){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    //Putting correct index of pivot
    pIndex=j;
    swap(&arr[pIndex],&arr[low]);
    //Now sorting left part of pivot
    quickSort(arr,low,pIndex-1);
    //Sorting right part of pivot
    quickSort(arr,pIndex+1,high);

}

int main(){
    int arr[10] = {8, 2, 10, 6, 5, 12, 18, 9, 4, 11};
    int length=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, length-1);
    printf("Sorted Array:\n");
    for (int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}