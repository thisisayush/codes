/* Assignment 10
	Wap to accept your height in centimeters and then convert then to feet and inches.
      (1 foot= 12 inches, 1 inch= 2.5 cm)
*/

#include<stdio.h>

void main(){
	int cm,foot,inch;
	
	printf("\nEnter height in cm:");
	scanf("%d",&cm);
	
	inch = cm/2.5;
	foot = inch/12;
	
	printf("\n Foot = %d \n Inches = %d",foot,inch);
}
