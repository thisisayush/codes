#include<stdio.h>
#include "my.h"
#define SIZE 15
void main(){
    int arr[SIZE],size,ele;
    storeArr(arr,&size,SIZE-2);
    printf("\nPlease Wait! Sorting Array...");
    sortArr(arr,size);
    printf("\nSorted Array: \n");
    printArr(arr,size);
    printf("\nEnter element to be inserted: ");
    scanf("%d",&ele);
    if(insertArr(arr,&size,ele)!=-1){
        printf("\n Inserted Successfully! \n New Array:");
        printArr(arr,size);
    }else{
        printf("\nWe ran into a problem! Inform Developer!");
    }

}

