/*Assignment 2 Wap to find out the sum of first 10 natural numbers.*/

#include<stdio.h>

void main(){
	int sum=0,i;
	
	for(i=1;i<=10;i++)
		sum+=i;
	
	printf("\nThe sum of first 10 natural no. is:%d",sum);
}
