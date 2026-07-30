/*
30/07/2026
An online shop keeps it product catalog sorted by product id(Whole Number) in ascending order .
When a customer searchs for a specific product id the system returns true if the product id present
in the catalog else it return false.
Which Searching technique is used to find the product id quickly from the catalog.
Implement this searching method using a function.
The function takes parameters productIdList , size of the list and productId to be searched.

sample Input : [2,8,9,16,18,26,38,48,51,90]
Case 1 : Product id to be searched : 26
Case 2 : Product id to be searched : 49
*/
#include<stdio.h>
int binarySearch(int arr[] , int size , int key){
    int low=0;
    int high=size-1;
    int found=0;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key){
            found=1;
            break;
        }
        else if(key>arr[mid]){
            low=mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return found;
}

int main(){
    int arr[]={2,8,9,16,18,26,38,48,51,90};
    int key;
    printf("Enter ProductId to be searched :");
    scanf("%d",&key);
    int length = sizeof(arr) / sizeof(arr[0]);
    if(binarySearch(arr,length,key)){
        printf("Product Found !");
    }
    else{
        printf("Product Not Found !");
    }
    printf("\n");
    return 0;
}