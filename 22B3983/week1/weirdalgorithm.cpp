#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

int main() {

    ll n;
    cin>>n;
    cout<<n<<" ";

    while(n!=1){
        
        if(n%2==1){
            n=(n*3)+1;
            cout<<n<<" ";
        }
        else{
            n=n/2;
            cout<<n<<" ";
        }
    }
}