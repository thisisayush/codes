/* Write a program to input 2 numbers and prints the smaller of the two.*/
#include<stdio.h>
int main()
{
	int a,b;
	printf("\nEnter a number:");
	scanf("%d",&a);
	printf("\nEnter a number:");
	scanf("%d",&b);
	
	if(a<b){
		printf("\n%d is lesser than %d",a,b);
	}else{
		if(a>b){
			printf("\n%d is greater than %d",a,b);
		}else{
			printf("\n Both are equal!");
		}
	}
	
return 0;
}

