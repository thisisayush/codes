/* Assignment 3
	Write the program to calculate the cube of a number entered by the user at run time.
*/

#include<stdio.h>

void main(){
	int n,cube;
	
	printf("\nEnter a number:");
	scanf("%d",&n);
	
	cube=n*n*n;
	
	printf("\n Cube= %d",cube);
}
