#include<iostream>
using namespace std;

int main(){
int t;//number of test cases
int n,k;
cin>>t;
for(int i=0;i<t;i++){
    cin>>n>>k;
    if(n%2==0){
        cout<<"YES";
    }
    else{
        if(k%2!=0){
            cout<<"YES";
        }
        else{
            cout<<"NO";
        }
    }

}
}
