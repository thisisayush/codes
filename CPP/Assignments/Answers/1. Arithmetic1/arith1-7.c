/* Assignment 7
	Write a program to accept a two digit number and display its reverse.
*/

#include<stdio.h>

void main(){
	int no,revno;
	
	printf("\nEnter a two digit no:");
	scanf("%d",&no);
	
	revno = (10*(no%10)) + (no/10);
	
	printf("\nReverse:%d",revno);
}
