/* Assignment 6
	A computer program contest requires teams of 5 members each.
	Write a program that asks for the no. of players, and then gives the number of teams and the no of players left out.
*/

#include<stdio.h>

void main(){
	int teams, rem, players;
	
	printf("\n Enter no. of players:");
	scanf("%d",&players);
	
	teams=players/5;
	rem=players%5;
	
	printf("\n\nTotal teams: %d \n Left Players: %d",teams,rem);
}
