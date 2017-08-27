/* Assignment 2 (Loop Constructs)
	Wap to display the series of even numbers up to user wish.
*/

#include<stdio.h>

void main(){
	int n,i;
	printf("\nEnter a number:");
	scanf("%d",&n);
	printf("\nPrinting even no. upto %d \n",n);
	for(i=0;i<n;i++){
		if((i+1)%2==0)
			printf(" %d",i+1);
	}
}

