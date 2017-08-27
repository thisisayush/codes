/** Code by Ayush Agarwal (thisisayushaa@gmail.com).
This Program Converts Any Number to Words
e.g. 101: One Hundred One
**/

#include<iostream>

using namespace std;
//char *words[8],*digits;
//1234567890
char *tens[]={"","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
char *ones[]={"one","two","three","four","five","six","seven","eight","nine"};
char *eens[]={"ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
int breakPoints[]={2,5,7,9};

void numToWord(long);
int totalDigits(long);
bool isBreakpoint(int);
void printSuffix(int,int);
void printTwoDigitWord(int);

int main(){
    long number;
    int digits;

    cout<<"\n Enter Number: ";
    cin>>number;
    digits=totalDigits(number);
    if(digits<=10){
        cout<<"\nTotal Digits: "<<totalDigits(number);
        cout<<endl;
        numToWord(number);
    }else{
        cout<<"\nUpto Million Supported";
    }
}

/** Takes Number as Input (long)**/
void numToWord(long num){
    int totalDig,rem_dig,curr_dig,curr_multiplier=1;
    totalDig = totalDigits(num);
    rem_dig = 5;
    for(int i=1;i<totalDig;i++)
        curr_multiplier *=10;
    while(rem_dig!=1){
        rem_dig = totalDigits(num);
        /** For debugging cout<<"\nRemaining: "<<rem_dig<<endl<<"Current Multiplier: "<<curr_multiplier; **/
        if(isBreakpoint(rem_dig)){
            curr_dig = num/(curr_multiplier/10);
            num=num%(curr_multiplier/10);
             curr_multiplier /=100;
        }else{
            curr_dig = num/curr_multiplier;
            num%=curr_multiplier;
            curr_multiplier /=10;
        }
        /** for debugging
        cout<<"\nCurrent Digit: "<<curr_dig;
        cout<<"\nNum = "<<num<<endl;
        **/
        cout<<" ";
        printSuffix(curr_dig,rem_dig);
    }
}

bool isBreakpoint(int rem_dig){
    for(int i=0;i<4;i++){
        if(rem_dig==breakPoints[i])
            return true;
    }
    return false;
}

int totalDigits(long num){
    int count=0;
    while(1){
        if(num/10==0)
            break;
        else
            num = num/10;
        count++;
    }
    count++;    //increase count because of the break statement
    return count;
}

void printSuffix(int dig,int rem_dig){
    rem_dig--;
    printTwoDigitWord(dig);
    switch(rem_dig){
        case 9:
        case 10:
            cout<<" Million";
            break;
        case 8:
        case 7:
            cout<<" Crore";
            break;
        case 6:
        case 5:
            cout<<" Lakh";
            break;
        case 4:
        case 3:
            cout<<" Thousand";
            break;
        case 2:
            cout<<" Hundred";
            break;
        case 1:
            break;
        default:
            cout<<"\n Max Limit Reached!";
            break;
    }
}


void printTwoDigitWord(int num){
    // Only for two Digits
    // cout<<"["<<num<<"]"; //debugging
    if(num>9&&num<20)
        cout<<eens[num%10];
    else{
        if(num/10!=0)
            cout<<" "<<tens[(num/10)-1]; //<<"("<<num/10<<")";
        if(num%10!=0)
            cout<<" "<<ones[(num%10)-1]; //<<"("<<num%10<<")";
    }
}
