/* 4.	Write a program to accept the age of an user and check if he is a valid voter or not. */
#include<stdio.h>
int main()
{
	int a;
	printf("\nEnter your age:");
	scanf("%d",&a);
	if(a>18)
		printf("You are not eligible for voting!");
	else
		printf("You are eligible for voting!");
return 0;
}

