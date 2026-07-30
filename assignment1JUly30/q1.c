/*
 Date : 30/07/2026
In a library the books are store using there Acc. no. Acc number is the whole number the consist maximum 3 digits
number whole number.Consider an array where the access number of the books are store in are organised fashion.
The librarian once to search for us specific access number in the array .Which searching methodology the librarian must follow ,
write the C program to implement this searching technique.
Sample input: [101,20,49,385,210,620,85,921,12,206]
Case 1: Access number to be search : 85
Case 2: Access number to be search : 465
*/


#include<stdio.h>

int linearSearch(int arr[] , int size , int key){
    int found=0;
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            found=1;
            break;
        }
    }
    return found;
}

int main(){
    int arr[]={101,20,49,385,210,620,85,921,12,206};
    int key;
    printf("Enter Acc. no. to be searched :");
    scanf("%d",&key);
    int length = sizeof(arr) / sizeof(arr[0]);
    if(linearSearch(arr,length,key)){
        printf("Found !");
    }
    else{
        printf("Not Found !");
    }
    printf("\n");
    return 0;
}