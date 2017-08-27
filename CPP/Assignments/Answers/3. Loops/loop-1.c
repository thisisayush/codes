//Assignment 3 Loops Wap to count the number of digits in a number entered by user?
// done with pointers as practice
#include<stdio.h>
void main(){
	char num[20],*ptr,count=0;
	printf("\nEnter a number:");
	scanf("%s",num);
	fflush(stdin);
	for(ptr=num;*ptr!='\0';ptr++)
		count++;
	printf("\nTotal digits = %d",count);
}

