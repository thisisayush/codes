/*Assignment 3 WAP to generate
	  *
    ***
  *****
*******
  *****
    ***
      *
*/
#include<stdio.h>
void main(){
	int i, limit=20,k,j;
	for(i=1;i<=limit/2;i++){
		for(k=limit/2;k>i;k--){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf(" *");
		}
		printf("\n");
	}
	for(i=1;i<limit/2;i++){
		for(k=0;k<i;k++){
			printf(" ");
		}
		for(j=limit/2;j>i;j--){
			printf(" *");
		}
		printf("\n");
	}
}

