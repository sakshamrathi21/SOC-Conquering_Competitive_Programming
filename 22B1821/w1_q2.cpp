#include<iostream>
#include<string>
using namespace std;

int main(){
    string input;
   getline(cin, input);
   int n=input.length();
   int Max_streak=1;
   int streak=1;
   for(int i=0;i<n;i++){
    

        if(input[i]==input[i+1]){
             streak+=1;

        }
        else{
            streak=1;
        }
        Max_streak=max(Max_streak,streak);
    
   }
   cout<<Max_streak<<endl;
    


return 0;
}