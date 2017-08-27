/*Assignment 7 Wap to check the Armstrong number? (for e.g. 153 =1^3+5^3+3^3)*/ 
#include<stdio.h>
#include<math.h>
void main(){
	int num,sum=0,div,digits,i,cube;
	
	printf("\nEnter a number:");
	scanf("%d",&num);	
	
	/**Digits extraction*/
	digits = count(num);
	div = pow(10,digits-1);
	for(i=0;i<digits;i++){
		cube = (num/div)%10;
		cube = cube*cube*cube;
		printf("%d+",cube);
		sum+=cube;
		div/=10;
	}
	printf("\nNum = %d \t Sum = %d",num,sum);
	if(sum==num){
		printf("\nIt's an Armstrong Number!'");
	}else{
		printf("\nIt's not an Armstrong Number :(");
	}
}

int count(int num){
	int div = 1,dig = 0;
	while(num/div!=0){
		div*=10;
		dig++;
	}
	return dig;
}

