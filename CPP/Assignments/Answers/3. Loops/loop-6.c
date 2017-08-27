/*Assignment 3 Write a program to generate the following :
*
**
***
****
***** 
*/
#include<stdio.h>
void main(){
	int i,j,limit=20;
	for(i=1;i<=limit;i++){
		for(j=1;j<=i;j++){
			printf("*");
		}
		printf("\n");
	}
}

