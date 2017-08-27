/*Assignment 2 Wap to print table of given number.*/

#include<stdio.h>

void main(){
	int n,i;
	printf("\nEnter a number:");
	scanf("%d",&n);
	printf("\nPrinting Table of given no:\n");
	for(i=1;i<=10;i++)
		printf("\n%d * %d = %d",n,i,n*i);
}
