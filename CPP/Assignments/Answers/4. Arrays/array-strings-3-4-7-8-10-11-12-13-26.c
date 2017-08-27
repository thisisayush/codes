/* Assignment 4 3.  Wap to read a string from user and show the character one by one? (Done)
				4.  Wap to read a character and a string and search whether that characters lies in that string? (Done)
				7.  Wap to count the no of vowels, consonants and spaces in a string. (Done)
				8.  Wap to replace every space in a string with an hyphen (-). (Done+enchnaced)
				10. Wap to calculate the length of the string. (Done)
				11.	Wap to find count the no of words present in an line. (Done)
				12.	Wap to reverse a string
					a.	Using another array. (Done)
					b.	Without using another array. (done)
				13. Wap to concatenate 2 strings. (Done)
				26.	Wap to count the number of occurrences of a given character in a string. (Done)

*/
#include<stdio.h>
const int limit = 50;

void menu();
void userInput(char*);
void traverse(char*);
void search(char*,char);
void replace(char*,char,char);
void reverse(char*,int);	//int is used for type i.e. 0 = without using Another Array 1= Using Another Array
void concatenate(char*,char*);

void main() {

	menu();
}

void menu(){
	char str[limit];
	int choice,choice1;
	char ch,ch1,str1[limit/2];
	printf("\n\t\t\tStrings (Assignment 4)");
	userInput(str);
	do{
		printf("\nMenu \n1. Traverse \n2. Search \n3. Replace \n4. Reverse \n5. Concatenate \nEnter Choice: ");
		scanf("%d",&choice);
		fflush(stdin);
		switch(choice){
			case 1:
				/* Traverse */
				traverse(str);
			break;
			case 2:
				/* Search */
				printf("\nEnter character to be searched: ");
				ch = getchar();
				search(str,ch);
			break;
			case 3:
				/* Replace */
				printf("\nEnter Character to be replaced: ");
				ch = getchar();
				fflush(stdin);
				printf("\n Enter character to be replaced with:");
				ch1 = getchar();
				replace(str,ch,ch1);
			break;
			case 4:
				/*Reverse*/
				printf("\nSelect Method:");
				printf("\n1. Without Array \n 2. With Array \n Enter Choice:");
				fflush(stdin);
				scanf("%d",&choice1);
				fflush(stdin);
				switch(choice1){
					case 1:
						reverse(str,0);
						break;
					case 2:
						reverse(str,1);
						break;
					default:
						printf("\nInvalid! Exiting!");
					}
                printf("\n\nReversed is %s",str);
			break;
			case 5:
				/* Concatenate */
				printf("\nOriginal String: %s",str);
				printf("\nEnter string to be concatenated(max %d chars): ",(limit/2)-1);
				gets(str1);
				concatenate(str,str1);
			break;
			default:
				printf("\nInvalid Choice! Exiting!");
		}
		fflush(stdin);
		printf("\n\n\nRedo? Y/N: ");
		ch = getchar();
		fflush(stdin);
	}while(ch=='Y' || ch=='y');
}

void userInput(char *str) {
	printf("\nEnter a string:");
	gets(str);
}

void traverse(char *str) {
	printf("\n\nProcessing String.. Please Wait!\n");
	int length,noV,noC,noS,noW;
	length = noV = noC = noS = noW =0;
	while(*str!='\0') {
		length++;
		printf("\n %c -> ",*str);
		if((*str>=65&&*str<=91) || (*str>=97 && *str<=123) || (*str == ' ')) {
			switch(*str) {
				case 'a':
				case 'e':
				case 'i':
				case 'o':
				case 'u':
				case 'A':
				case 'E':
				case 'I':
				case 'O':
				case 'U':
					printf("Vowel");
					noV++;
					break;
				case ' ':
					printf("Space");
					noS++;
					break;
				default:
					noC++;
					printf("Consonant");
			}
		} else {
			printf("Not a character!");
		}
		str++;
	}
	noW = noS+1;
	printf("\n\nProcessing Complete!");
	printf("\nLength: %d \nVowels: %d \tConsonants: %d \tSpaces: %d \nWords: %d",length,noV,noC,noS,noW);
}

void search(char *str,char ch) {
	printf("\n\n\t\t\tSearching...");
	int totalOccurence = 0;
	int index = 0;
	while(*str!='\0') {
		if(*str == ch) {
			printf("\nCharacter found at index %d",index);
			totalOccurence++;
		}
		index++;
		str++;
	}
	printf("\n\nTotal Occurrences: %d",totalOccurence);
}

void replace(char *str, char replaceWhat, char replaceWith) {
	char *startAddr;
	startAddr = str;
	while(*str!='\0') {
		if(*str == replaceWhat)
			*str = replaceWith;
		str++;
	}
	printf("\nAll Replacements Done! \nNew string: %s",startAddr);
}

void reverse(char *str, int method) {
	int length,i,j;
	char *startAddr,temp,*endP,str2[limit];
	startAddr = endP = str;
	switch(method) {
		case 0:
			/* Without Array */
            length = 0;
            printf("\n Reversing without using array!");
			while(*str!='\0') {
				length++;
				str++;
				endP++;
			}
			*endP--;
			str = startAddr;
			for(i=0;i<length/2;i++){
				temp = *str;
				*str = *endP;
				*endP = temp ;
				str++;
				endP--;
			}
			str = startAddr;
			break;
		case 1:
			/* With Array*/
			length=0;
            printf("\n\nReversing using an array!");
			while(*str!='\0') {
				length++;
				str++;
			}
			str--;
			for(i=0;i<length;i++,str--)
				str2[i] = *str;
            str2[i] = '\0';

            /** Feeding into main array **/
            str = startAddr;
            for(i=0;i<length;i++,str++)
                *str = str2[i];
			break;
		default:
			printf("\n Invalid Argument!");
	}
}

void concatenate(char *str1, char *str2){
	char *startAddr;
	startAddr = str1;
	while(*str1!='\0')
		str1++;

	while(*str2!='\0'){
		*str1 = *str2;
		str1++;
		str2++;
	}
	printf("\nConcatenated String is %s",startAddr);
}
