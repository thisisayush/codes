/* Assignment 4 1. Wap to accept the values in array and display their values?
				2. Wap the program to search an accepted number in an array?
				9. Wap to find put the largest and the smallest element in the array.
*/

#include<stdio.h>

const int limit = 25;

void main(){
	int arr[limit],i;
	int val,flag=0;
	int small,large;
	/** Part one **/
	printf("\nEnter array values:");
	
	for(i=0;i<limit;i++){
		printf("\nArr[%d] : ",i);
		scanf("%d",&arr[i]);
		fflush(stdin);
	}
	printf("\n\t\t\tStored values are:");
	for(i=0;i<limit;i++){
		printf("\nArr[%d] = %d",i,arr[i]);
	}
	/** Part 1 ends **/
	
	
	/** Part 9 starts **/
	small=large=arr[0];
	for(i=0;i<limit;i++){
		small = (small > arr[i]) ? arr[i] : small;
		large = (large < arr[i]) ? arr[i] : large;
	}
	
	printf("\n\nLargest : %d \t\t Smallest: %d",large,small);
	/** Part 9  ends**/
	
	
	/** Part 2 starts **/
	printf("\n\nEnter value top be searched in array:");
	scanf("%d",&val);
	
	for(i=0;i<limit;i++){
		if(val == arr[i]){
			printf("\nValue found at index '%d'",i);
			flag=1;
		}
	}
	if(flag==0)
		printf("\nNo matching records!");
	
	/** Part 2 ends **/
}


