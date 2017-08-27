/*Assignment 4	Wap to check whether the given number is a palindrome? */
#include<stdio.h>
void main(){
	int num,i,j,digits,div,div2=1,div3=10,flag=0;
	printf("\nEnter a number:");
	scanf("%d",&num);
	digits = count(num);
	div = pow(10,digits-1);
	for(i=0,j=digits;i<j;i++,j--){
		if( ((num/div)%10) != ((num%div3)/div2) ){	// first conditon extracts from starting Second onsiton extracts from end!
			flag=1;
			break;
		}
		div/=10;
		div2*=10;
		div3*=10;
		//Numbers from end 
	}
	if(flag){
		printf("\nNot a Palindrome!");
	}else{
		printf("\nIt's a Palindrome!");
	}
	/*
	For extracting from end
	1234 = 1234%10 = 4
				1234%100 = 34/10 = 3
				1234%1000 = 234/100 =2
				1234%10000 = 1234/1000 = 1
	*/
}

int count(int num){
	int div = 1,dig = 0;
	while(num/div!=0){
		div*=10;
		dig++;
	}
	return dig;
}
