#include<stdio.h>
#define SIZE 15
#define debug 0 /** Set it to 1 to show all info during program execution*/
#define MAIN_MENU 0

void main(){
    int arr[SIZE],arr2[SIZE],arr3[SIZE],size,i;
    int choice = display(MAIN_MENU);
    printf("\nEnter a size for matrix (less than %d): ",SIZE-2);
    switch(choice){
    case SINGLE_MATRIX:
        storeArr(arr,size);
        choice = display(SINGLE_MATRIX);
        switch(choice){
        case REVERSE_ARR:
            printf("\n Please Wait! Reversing Array...");
            reverseArr(arr,size);

            break;
        case SORT_ARR:
            printf("\n Please Wait! Sorting Array...");
            sortArr(arr,size);

            break;
        case INSERT_ARR:
            printf("\n Initializing Insertion!\n Sorting Array...");
            sortArr(arr,size);
            insertArr(arr,size);

            break;
        default:
            printf("\n Unknown error Occurred!");
        }

        printf("\n New array is: ");
        printArr(arr,size);
    break;

    case DOUBLE_MATRIX:
        printf("\nEnter elements for first matrix:");
        storeArr(arr,size);
        printf("\nEnter elements for second matrix:");
        storeArr(arr2,size);
        choice = display(DOUBLE_MATRIX);

        switch(choice){
        case ADD_MATRIX:
            printf("\nAdding Matrices...");
            arr3 = addMatrices(arr,arr2,size);
            printf("\n New matrix is:");
            printArr(arr3,size);
            break;
        case COMPARE_MATRIX:
            printf("\nComparing Matrices...");
            if(compareArr(arr1,arr2,size)){
                printf("\nMatrices are identical!");
            }else{
                printf("\nMatrices are not-identical!");
            }
            break;
        default:
            printf("\b Unknown error occurred!");
        }
        break;
    default:
        printf("\nOops! We ran into a problem! Please contact developer!");
    }

}

void storeArr(int *arr,int size){
    for(i=0;i<size;i++){
        printf("\nEnter element %d: ",i);
        scanf("%d",&arr[i]);
    }
}

void display(int code){
    int choice;
    switch(code){
    case MAIN_MENU:
        do{
        printf("\n Select type: \n 1. Single Matrix \n 2. Double Matrix \n Enter your choice: ");
        scanf("%d",&choice);
        }while(choice>=1&&choice<=2);
        return choice;
        break;
    case SINGLE_MATRIX:
        printf("\n MAIN-MENU -> Single Matrix");
        printf("\n 1. ")
    default:
        printf("\n An error occurred!");
    }
}

/** Insert element to sorted array**/
/** Call sortArray() before calling this function**/
void insertArr(int *arr,int size){
    int i,j,temp,ele,pos=size;
    printf("\nEnter element to insert:");
    scanf("%d",&ele);
    for(i=0;i<size;i++){
        if(arr[i]<ele && arr[i+1]>=ele){
            pos = i+1;
            printf("position found! %d",pos);
            break;
        }
    }
    for(i=size-1;i>=pos;i--){ //size=13,i=13
       if(debug)
            printf("\nShifting %d from pos %d to pos %d",arr[i],i,i+1);
       arr[i+1] = arr[i];
    }
    arr[pos] = ele;

}

void printArr(int *arr,int size){
    int i;
    printf("\n");
    for(i=0;i<size;i++){
        printf(" arr[%d]:%d  ",i,arr[i]);
    }
    printf("\n");
}

void printReverse(int *arr, int size){
    int i;
    printf("\nPrinting array in reverse (Using Pointers)");
    for(i=size-1;i>=0;i--){
        printf("\nArr[%d] = %d",i,arr[i]);
    }
}

void reverseArr(int *arr, int size){
    int i,j,temp;
    for(i=0,j=size;i<size/2;i++,j--){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/** Sorts in Ascending Order**/

void sortArray(int *arr,int size){
    int temp,i,j,flag=1;
    for(i=0;i<size && flag;i++){
        if(debug)
            printf("\nPass #%d",i+1);
        flag=0;
        for(j=0;j<size-i;j++){
            if(debug)
                printf("\nChecking %d , %d",arr[j],arr[j+1]);
            if(arr[j]>arr[j+1]){
                if(debug)
                    printf(" Swapping %d , %d",arr[j],arr[j+1]);
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
            if(debug){
                printf("\nCurrent Array: ");
                printArr(arr,size);
            }
        }
    }
}
