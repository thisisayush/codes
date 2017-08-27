/*Assignment 1
 Write a program to accept marks of student in 5 five subjects and find out their total and average.*/
 
#include<stdio.h>

void main(){
	float marks[5],total=0,avg;
	int i=0;
	
	while(i<5){
		printf("\n Enter marks in Subject %d:",i+1);
		scanf("%f",&marks[i]);
		total = total+marks[i];
		i++;
	}
	avg = total/5.0;
	printf("\n\nTotal: %f\t\t Average: %f",total,avg);
	printf("\n\n\nPress any key to exit...");
}
 
