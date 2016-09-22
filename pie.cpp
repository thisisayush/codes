#include<iostream>

using namespace std;
void divide(int num,int den);

int main(){
    divide(22,7);
}

void divide(int num, int den){

    int flag=0,flag2=0,i=0;
   do{
        i++;
        cout<<"\n\n\n\nPass "<<i;
        if((num<den&&num!=0) || flag==1){
            cout<<"\n Decimal Part Operating...";
            flag2=0;
            cout<<"\n\t\tFlag is "<<flag;
            if(flag==0){
                cout<<"\n\t\tThis means point need to be inserted..."<<endl;
                cout<<".";
            }else{
                cout<<"\n\t\t Num/div = "<<num<<"/"<<den<<" = ";
                cout<<num/den;
            }
            flag=1;
            cout<<"\n Num is "<<num;
            num %= den;
            cout<<"\n\t\t Den is : "<<den<<" Num now is: "<<num;

            while(num<den){
                cout<<"\n\t\tNumber needs to be incremented! curr: "<<num;
                num*=10;
                cout<<"Updated : "<<num;
                if(num==0)
                    break;
                if(flag2==1){
                    cout<<0;
                }
                flag2=1;
            }
        }else{
            cout<<"\n Point not found yet..";
            cout<<num/den;
            num = num%den;
        }

   }while(num!=0);
}
