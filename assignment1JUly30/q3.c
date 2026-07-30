/*
30/07/2026

A class Teacher has a list of marks of 10 students in a random fashion .
All the marks are whole numebrs.Before pusblishing the result the class teacher wants to
arrange the marks in an order so that the rank of the students can easily be detected .
Use a method to order the marks in ascending order.
Which methodology you use here implement the method using C programming languague .
(We can use any sorting techniques but here we use Bubble sort)

Sample Input : {99,85,58,71,46,80,78,65,49,55}
Output : 
The Marks In Ascending order : 
46 49 55 58 65 71 78 80 85 99
*/
#include<stdio.h>

void swap(int* a , int* b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void bubbleSort(int arr[],int size){
    for(int i=0 ; i< size ; i++){
        int flag=0;
        //We use size-i because on each cycle the last element becomes the largest
        for(int j=0;j<size-i-1;j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag=1;
            }
        }
        //If no swapping takes place meaning array is already sorted
        if(!flag){
            return;
        }
    }
}

int main(){
    int arr[]={99,85,58,71,46,80,78,65,49,55};
    int length = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr,length);
    printf("The Marks In Ascending order : \n");
    for(int i=0;i<length;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}