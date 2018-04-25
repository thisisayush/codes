#include<stdio.h>
#include<string.h>

#define MAX 30
#define MAX_SUB 5
//declaring structure

//user defined data-type

struct performance{
	int sub[MAX_SUB],total;
 	float avg;
 	char grade[5];
};

struct student{
	char name[20],address[50];
	char dob[15];
	int age,rollno;
	struct performance p;
};
void acceptDetails(struct student*,int);
void displayDetails(struct student obj[],int type,int type2);
void inputByIndex(struct student*, int,int,int);
int rollNumberExists(struct student*,int);
void initializeArray(struct student*);
void assignGrade(struct student*, int);
void main(){
	int choice;
	struct student stu[MAX];
	char ch;

	do{
		choice = showMenu(0);
		switch(choice){
			case 1:
				acceptDetails(&stu,1);
			break;
			case 2:
				acceptDetails(&stu,2);
			break;
			case 3:
				displayDetails(&stu,0,0);
			break;
			case 4:
				displayDetails(&stu,0,1);
			break;
			case 5:
				break;
			case 6:
				initializeArray(&stu);
			break;
			default:
				printf("\nInvalid!");
		}
	}while(choice!=5);
}




int showMenu(int para){
	int choice;
	switch(para){
		case 0: //Main Menu
			do{
				printf("\n\n\t\t\tMain Menu");
				printf("\n1. Enter Student(s) Details");
				printf("\n2. Enter Marks Details");
				printf("\n3. Display Student List");
				printf("\n4. Display Student Info");
				printf("\n5. Exit");
				printf("\n6. Initialize Array (only for testing)");
				printf("\nEnter your choice:");
				scanf("%d",&choice);
				if(!(choice>=1&&choice<=6))
					printf("\nInvalid Choice! Renter!");
				else
					return choice;
			}while(!(choice>=1&&choice<=5));
		break;
		case 1: //accaepDetails_Basic
			do{
				printf("\n\tMain Menu -> Add/Edit Details");
				printf("\n1. Enter by roll no");
				printf("\n2. Enter into All Student Mode!");
				printf("\nEnter your choice: ");
				scanf("%d",&choice);
				if(!(choice>=1&&choice<=2))
					printf("\nInvalid Choice! Renter!");
				else
					return choice;
			}while(!(choice>=1&&choice<=2));
		break;
	}
}

void acceptDetails(struct student *obj,int type){
	int i,flag=0,j;
	int choice;
	int roll,temp;
	switch(type){
		case 1: //Basic Details
			choice=showMenu(1);
			switch(choice){
				case 1:
					// Enter by Roll Number
					do{
						printf("\nEnter roll no:");
						scanf("%d",&roll);
						temp = rollNumberExists(obj,roll);
						if(temp!=-1){
							inputByIndex(obj,temp,0,1);
							flag=1;
						}else{
							printf("\nRoll number not found! Renter!");
						}
					}while(flag!=1);
				break;
				case 2:
					// Enter into All Student Mode
					printf("\nAll Student Mode!");
					for(i=0;i<MAX;i++){
						inputByIndex(obj,i,0,0);
					}
			}
		break;
		case 2: //Marks details
			choice=showMenu(1);
			switch(choice){
				case 1:
					// Enter by Roll Number
					do{
						printf("\nEnter roll no:");
						scanf("%d",&roll);
						temp = rollNumberExists(obj,roll);
						if(temp!=-1){
							inputByIndex(obj,temp,1,1);
							flag=1;
						}else{
							printf("\nRoll number not found! Renter!");
						}
					}while(flag!=1);
				break;
				case 2:
					// Enter into All Student Mode
					printf("\nAll Student Mode!");
					for(i=0;i<MAX;i++){
						fflush(stdin);
						inputByIndex(obj,i,1,0);
					}
			}
		break;
		default:
			printf("\nInvalid!");
	}
}

void inputByIndex(struct student *obj, int index, int type, int isExisting){
	//This function does not validate roll no! and will directly input the values into passed index!
	int i,j;
	switch(type){
		case 0:
			//Basic Details
			printf("\nEnter Roll No:");
			(isExisting)? printf(" Existing(%d) ",obj[index].rollno): printf(" ");
			scanf("%d",&obj[index].rollno);
			fflush(stdin);
			printf("\nEnter Name:");
			(isExisting)? printf(" Existing(%s) ",obj[index].name) : printf(" ");
			gets(obj[index].name);
			fflush(stdin);
			printf("\nEnter Address:");
			(isExisting)? printf(" Existing(%s) ",obj[index].address) : printf(" ");
			gets(obj[index].address);
			fflush(stdin);
			printf("\nEnter DOB:");
			(isExisting)? printf(" Existing(%s) ",obj[index].dob) : printf(" ");
			gets(obj[index].dob);
			fflush(stdin);
			printf("\nEnter age:");
			(isExisting)? printf(" Existing(%d) ",obj[index].age): printf(" ");
			scanf("%d",&obj[index].age);

		break;
		case 1:
			//Marks Details
			printf("\nRoll Number: %d",obj[index].rollno);
			obj[index].p.total = (isExisting)? obj[index].p.total : 0;
			for(i=0;i<MAX_SUB;i++){
				printf("\nEnter marks in subject %d: ",i+1);
				(isExisting)? printf(" Existing(%s) ",obj[index].p.sub[i]) : printf(" ");
				scanf("%d",&obj[index].p.sub[i]);
				obj[index].p.total += obj[index].p.sub[i];
			}
			obj[index].p.avg = obj[index].p.total*100/MAX_SUB;
			assignGrade(obj,index);
		break;
		default:
			printf("\nError: Invalid Parameter Value!");
	}
}

int rollNumberExists(struct student *obj,int roll){
	int i;
	for(i=0;i<MAX;i++){
		if(roll == obj[i].rollno)
			return i;
	}
	return -1;
}

void displayDetails(struct student obj[],int type, int type2){
	int i,res,roll;
	switch(type){
		case 0:
			//Student Info
			switch(type2){
				case 0:
					//List
					printf("\nList Mode!");
				//	printf("\nName\t\tRoll\tAge\tDOB\tTotal\tAvg\tAddress");
					for(i=0;i<MAX;i++){
						printf("\n");
						printf("Name: %s",obj[i].name);
						printf("\n\tRoll Number: \t%d",obj[i].rollno);
						printf("\n\tAge: \t%d",obj[i].age);
						printf("\n\tDOB: \t%s",obj[i].dob);
						printf("\n\tTotal: \t%d",obj[i].p.total);
						printf("\n\tAverage: \t%f",obj[i].p.avg);
						printf("\n\tAddress: \t%s",obj[i].address);
					}
					break;
				case 1:
					//Single
						do{
							printf("\nEnter Roll number:");
							scanf("%d",&roll);
							res = rollNumberExists(obj,roll);
							if(res==-1)
								printf("\nInvalid! Renter!");
						}while(res==-1);
						printf("\n");
						printf("Name: %s",obj[res].name);
						printf("\n\tRoll Number: \t%d",obj[res].rollno);
						printf("\n\tAge: \t%d",obj[res].age);
						printf("\n\tDOB: \t%s",obj[res].dob);
						printf("\n\tTotal: \t%d",obj[res].p.total);
						printf("\n\tAverage: \t%f",obj[res].p.avg);
						printf("\n\tAddress: \t%s",obj[res].address);
					break;
			}

	}
}

void initializeArray(struct student *obj){
	int i,j;
	printf("\n\nInitializing Array!");
	FILE *fptr;
    fptr = fopen("file.dat","w");
    if(fptr!=NULL){
       for(i=0;i<MAX;i++){
            obj[i].rollno = i+1;
            strcpy(obj[i].name,"Student");
            obj[i].age = i+18;
            strcpy(obj[i].dob,"15/10/1997");
            strcpy(obj[i].address , "Default Address");
            for(j=0;j<MAX_SUB;j++){
                obj[i].p.sub[j] = 65+j;
                obj[i].p.total+=obj[i].p.sub[j];
            }
            obj[i].p.avg = obj[i].p.total / MAX_SUB;
            assignGrade(obj,i);
            printf("\n %d Initialized",i+1);
        }
        printf("\nWriting to file!");
        writeFile(fptr,obj);
        fclose(fptr);
        fptr = fopen("file.dat","r");
        if(fptr == NULL){
            printf("\nUnable to open file!");
        }
        printf("%d",readFile(fptr));
    }else{
            printf("\nUnable to open file!");
       }
    printf("\nInitialization Complete!\n\n\n");
}

void assignGrade(struct student *obj,int index){

	if(obj[index].p.avg>=90 && obj[index].p.avg<100)
		strcpy(obj[index].p.grade, "A+");
	else if(obj[index].p.avg>=80 && obj[index].p.avg<90)
		strcpy(obj[index].p.grade , "A");
 	else if(obj[index].p.avg>=70 && obj[index].p.avg<80)
		strcpy(obj[index].p.grade , "B+");
	else if(obj[index].p.avg>=60 && obj[index].p.avg<70)
		strcpy(obj[index].p.grade , "B");
	else if(obj[index].p.avg>=50 && obj[index].p.avg<60)
		strcpy(obj[index].p.grade , "C");
	else if(obj[index].p.avg>=40 && obj[index].p.avg<50)
		strcpy(obj[index].p.grade , "D");
	else if(obj[index].p.avg>0 && obj[index].p.avg<40)
		strcpy(obj[index].p.grade , "FAIL");
}

int writeFile(FILE *fptr, struct student *stu){
    int i;

    for(i=0;i<MAX;i++){
        printf("\nWriting...");
        printf("%d",stu[i].rollno);
        fwrite(&stu[i],sizeof(struct student),1,fptr);
    }
    printf("\nWritten!");
    return 1;
}

int readFile(FILE *fptr){
    int i;
    printf("\nReading...");
    struct student stu[MAX];
    fread(stu,sizeof(struct student),MAX,fptr);
    for(i=0;i<MAX;i++)
        printf("\n%d %s",i,stu[i].name);
    return 0;
}
