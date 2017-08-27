/* Assignment 2 (Looping Constructs)
	Wap to print the series of natural numbers up to the user wish.
*/

#include<stdio.h>

void main(){
	int n,i;
	printf("\nEnter a number:");
	scanf("%d",&n);
	printf("\nPrinting upto %d \n",n);
	for(i=0;i<n;i++){
		printf(" %d",i+1);
	}
}
