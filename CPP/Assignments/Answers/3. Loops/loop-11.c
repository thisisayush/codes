/*Assignmet 3 WAP to generate
	*
   * *
  * * *	
 * * * *   
	and its reverse.
*/
#include<stdio.h>
void main(){
	int i,j,k,limit=5;
	for(i=1;i<=limit;i++){
		for(j=limit;j>i;j--)
			printf(" ");
		for(k=1;k<=(2*i)-1;k++)
			printf("*");
		printf("\n");
	}
	
	for(i=limit-1;i>=1;i--){
		
		for(j=limit-1;j>=i;j--)
			printf(" ");
		for(k=0;k<(2*i)-1;k++)
			printf("*");
		printf("\n");
	}
}

