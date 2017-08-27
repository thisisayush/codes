/*2.	Write a program to accept a no and check whether it is greater than 50 or not.*/
#include<stdio.h>
int main()
{
	int a;
	printf("\nEnter a number:");
	scanf("%d",&a);
	if(a>50)
		printf("%d is greater than 50",a);
	else
		printf("%d is less than or equal to 50",a);
return 0;
}

