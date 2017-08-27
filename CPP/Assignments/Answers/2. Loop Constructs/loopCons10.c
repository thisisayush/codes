/* Assignment 2
Wap which computes a to the power b where a, b are real numbers using looping constructs.
*/

#include<stdio.h>

void main(){
	int a,b,i;
	float res=1;
	
	printf("\nEnter a:");
	scanf("%d",&a);
	fflush(stdin);
	printf("\nEnter b:");
	scanf("%d",&b);
	fflush(stdin);
	for(i=1;i<=b;i++){
		res=res*a;
		
	}
	printf("\n%d to the power %d is %f",a,b,res);
	
}
