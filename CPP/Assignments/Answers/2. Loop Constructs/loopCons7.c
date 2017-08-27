/* Assignemt 2Wap to find out the factorial of any number.*/

#include<stdio.h>

void main(){
	int n,i;
	double fact=1;
	
	printf("\nEnter a no:");
	scanf("%d",&n);
	
	for(i=n;i>0;i--)
		fact = fact*i;
	
	printf("\n Factorial is:%f",fact);
}
