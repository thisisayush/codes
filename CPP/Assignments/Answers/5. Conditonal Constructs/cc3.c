/*3.	Write a program to accept two no and check whether no1 is divisible by no2 or not.*/
#include<stdio.h>
int main()
{
	int a,b;
	printf("\nEnter a number:");
	scanf("%d",&a);
	printf("\nEnter a number:");
	scanf("%d",&b);
	if(a%b==0){
		printf("\n %d is divisble by %d",a,b);
	}else{
		printf("\n %d is not divisble by %d",a,b);
	}

return 0;
}

