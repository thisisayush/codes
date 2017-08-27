/* Assignment 2 Wap to find out the Fibonacci series of first n numbers (0, 1, 1, 2, 3, 5, 8….) */

#include<stdio.h>

void main(){
	int n,i,last=1,sum,slast=0;;
	
	printf("\nEnter n:");
	scanf("%d",&n);
	printf("%d %d",slast,last);
	for(i=0;i<(n-2);i++){
		sum = slast + sum;
		slast = last;
		last = sum;
		printf(" %d",sum); 
	}
}
