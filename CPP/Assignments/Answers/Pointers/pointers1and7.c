#include<stdio.h>
#include "my.h"
#define SIZE 15
void main(){
    int arr[SIZE],size;
    storeArr(arr,&size,SIZE);
    printf("\nPrinting Array in reverse!");
    printReverseArr(arr,size);

    printf("\n\nReversing Array! (In actual)");
    reverseArr(arr,size);
    printf("\nReversed Array:");

    printArr(arr,size);
}
