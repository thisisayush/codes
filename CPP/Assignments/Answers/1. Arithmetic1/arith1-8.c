/* Assignment 8
	Write a program to accept two numbers and interchange the values.
*/

#include<stdio.h>

void main(){
	int a,b,c;
	
	printf("\nEnter a:");
	scanf("%d",&a);
	
	printf("\nEnter b:");
	scanf("%d",&b);
	
	c=a;
	a=b;
	b=c;
	
	printf("\nReversed Values: \n A: %d \n B: %d",a,b);
}
