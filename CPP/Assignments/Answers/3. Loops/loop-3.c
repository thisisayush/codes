/*Assignment 3	Wap that reads a number and a digit, it determines whether the numbers contains the digit using while loop?*/
#include<stdio.h>
void main(){
	int num,num2,digits,div=1,div2=1,i,temp,flag=0;
	
	printf("\nEnter a number!");
	scanf("%d",&num);
	
	printf("\nEnter number to be searched: ");
	scanf("%d",&num2);
	
	/* Digits Extraction Code*/
	digits = count(num);
	div = pow(10,digits-1);
	for(i=0;i<digits;i++){
		temp = (num/div)%10;
		if(num2 == temp){
			flag=1;
			break;
		}
		div2*=10;
		div/=10;
	}
	if(flag==1)
		printf("\nNumber found!");
	else
		printf("\nNumber not found!");
	
}

int count(int num){
	int div = 1,dig = 0;
	while(num/div!=0){
		div*=10;
		dig++;
	}
	return dig;
}
