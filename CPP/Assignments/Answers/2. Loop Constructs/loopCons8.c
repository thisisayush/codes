/*Assignment 2 
Wap to display a menu regarding rectangle operations and perform according to users response
*/

#include<stdio.h>

void main(){
	int l,b,c;
	do{
		printf("\nRectangle Operations:");
		printf("\n1. Area \n2. Perimeter");
		printf("\nEnter your choice:");
		scanf("%d",&c);
		if(!(c==1||c==2)){
			printf("\nInvalid Choice! Reneter!");
		}
	}while(!(c==1||c==2));
	
	printf("\nEnter Length:");
	scanf("%d",&l);
	printf("\nEnter Width:");
	scanf("%d",&b);
	
	switch(c){
		case 1:
			printf("\n\n Area = %d",l*b);
			break;
		case 2:
			printf("\n\n Perimeter = %d",2*(l+b));
			break;
		default:
			printf("\n Unexpected Error occured! Contact Developer!");
	}
	
}
