//Assignment 3 Wap that reverse and sum up the integer digits using values
#include<stdio.h>
#include<math.h>
void main(){
	int num,revnum=0,digits,div=1,div2=1,i,j=1;
	printf("\nEnter a number!");
	scanf("%d",&num);
	digits = count(num);
	printf("\nTotal Digits:%d \nReversing process started!",digits);
	div = pow(10,digits-1);
	for(i=0;i<digits;i++){
		revnum += div2*((num/div)%10);
		div2*=10;
		div/=10;
	}
	printf("\nReversing finished!");
	/* Concept 
	for a 4 digit no.
	1234 = 1000*1+100*2+10*3+1*4 = 10^(4-1) * (1234/1000=1%10 = 1) + 10^(4-2) * (1234/100 = 12%10=2) + 10^(4-3)*(1234/10 = 123%10 = 3)
	*/
	printf("\nReverse:%d",revnum);
	
}

int count(int num){
	int div = 1,dig = 0;
	while(num/div!=0){
		div*=10;
		dig++;
	}
	return dig;
}
