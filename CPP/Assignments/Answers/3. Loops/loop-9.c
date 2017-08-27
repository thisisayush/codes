/*Assignment 3 WAP that generated the following series
1 + 1/2! + 1/3! + 1/4! ....... 1/n!
*/
#include<stdio.h>
void main(){
	int i,limit=8;
	for(i=1;i<=limit;i++){
		printf(" 1/%d! ",i);
		if(i!=limit)
			printf("+");
	}
}

