/* Assignment 9
	Wap to that accepts a character between a to j and prints next four characters
*/

#include<stdio.h>

void main(){
	char ch;
	
	do{
		printf("\nEnter a character (a-j):");
		ch=getchar();
		fflush(stdin);
		if(!(ch>='a'&&ch<='j')){
			printf("\nInvalid! Renter!");
		}
	}while(!(ch>='a'&&ch<='j'));
	
	printf("\nNext 4 chars: %c, %c, %c, %c",ch+1,ch+2,ch+3,ch+4);
}
