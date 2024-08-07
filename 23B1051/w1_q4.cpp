#include<iostream>
using namespace std;

int luckiness(long long int x){
   long long int maximum=0,minimum=9;
   while(x>0){
    maximum = max(maximum,x%10);
    minimum = min(minimum,x%10);
    x=x/10;
   }
   return maximum - minimum ;
}
int main(){
    long long int t;
    cin>>t;
    while(t--){
        long long int l,r;
        cin>>l>>r;
        long long int luckiest = l;
        int luck = 0;
        for(int i=l;i<=r;i++){
            if(luck<luckiness(i)){
                luck=luckiness(i);
                luckiest = i;
            }
        }
        cout<<luckiest<<"\n";
    }
}