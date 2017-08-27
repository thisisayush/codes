/* Assignment 5
	Wap to convert a given no of days into years, weeks and days.
*/

#include<stdio.h>

void main(){
	int years, days, weeks;
	
	printf("\n Enter no. of days: ");
	scanf("%d",&days);
	
	years = days/365;
	weeks = days/7;
	
	printf("\n\t\t = %d weeks or %d years",weeks,years);		
}
