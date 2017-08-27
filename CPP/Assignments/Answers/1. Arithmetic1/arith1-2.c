/* Assigment 2
	Wap to convert the temperature from Fahrenheit to Celsius:- 
					Celsius= (f-32)*5/9
*/

#include<stdio.h>

void main(){
	float cel,fah;
	printf("\nEnter temp. in fahrenheit: ");
	scanf("%f",&fah);
	
	cel = (fah-32)*5/9;
	
	printf("\n = %f degree celsius.",cel);
}
