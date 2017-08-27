/* Assignment 4
	WAP to read the values of w, x, y, and z and display the value of p, where p=w+x/y-z.
*/

#include<stdio.h>

void main(){
	int w,x,y,z,p;
	
	printf("\nEnter value of w:");
	scanf("%d",&w);
	printf("\nEnter value of x:");
	scanf("%d",&x);
	printf("\nEnter value of y:");
	scanf("%d",&y);
	printf("\nEnter value of z:");
	scanf("%d",&z);
	
	p = (w+x)/(y-z);
	
	printf("\nValue of p = (w+x)/(y-z): %d",p); 
}
