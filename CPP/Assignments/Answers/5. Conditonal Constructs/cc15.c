/*
15.	Program to calculate the commission for the sales man: the commission is calculated according to following rates:
	Sales		Commission Rate
	Above 30000 15%
	22000-30000	10%
	12000-22000 7%
	5000-12000	3%
	0-5000	0%
*/
#include<stdio.h>
int main()
{
	float commission,sales;
	
	printf("\nEnter sales amount:");
	scanf("%f",&sales);
	
	if(sales>30000)
		commission = 15*sales/100;
	else if(sales>22000 && sales<=30000)
		commission = 10*sales/100;
	else if(sales>12000 && sales<=22000)
		commission = 7*sales/100;
	else if(sales>5000 && sales<=12000)
		commission = 3*sales/100;
	else if(sales>0 && sales<=5000)
		commission = 0;
		
	printf("\n Your commission is: Rs %.2f",commission);
return 0;
}

