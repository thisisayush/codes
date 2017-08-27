/* Assignment 3 Write a program to generate the following :
        1                                                            1
        12                                                          22
        123                                                        333
        1234                                                      4444
        12345                                                    55555
*/
#include<stdio.h>
void main(){
	int i,j,limit=5,k;
	for(i=1;i<=limit;i++){
		for(j=1;j<=i;j++){
			printf("%d",j);
		}
		printf("\n");
	}
	for(i=1;i<=limit;i++){
		for(k=limit;k>i;k--){
			printf(" ");
		}
		for(j=1;j<=i;j++){
			printf("%d",i);
		}
		printf("\n");
	}
}

