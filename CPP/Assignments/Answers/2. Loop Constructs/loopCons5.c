/* Assignment 2 Wap to find out the sum of first 20 even and odd numbers in a single program */

#include<stdio.h>

void main(){
	int i=1,sumE=0,sumO=0,numE=0,numO=0,flag=1,debug=0;
	
	while(flag==1){
		if(i%2==0&&numE<=20){
			if(debug==1)
				printf("\nAdding %d to sumE=%d!",i,sumE);
			sumE+=i;
			numE++;
		}else{
			if(numO<=20){
			if(debug==1)
				printf("\nAdding %d to sumO=%d!",i,sumO);
				sumO+=i;
				numO++;
			}
		}
		if(numO==20&&numE==20)
			flag=0;
		i++;
	}
	
	printf("Sum of first 20 odd is %d and first 20 even is %d.",sumO,sumE);
}
