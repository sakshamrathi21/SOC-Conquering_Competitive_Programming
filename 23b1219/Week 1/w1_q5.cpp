#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll t;
    cin>>t;
    cout<<t<<" ";
    while(t!=1){
        if (t%2==0){
            t/=2;
            cout<<t<<" ";
        }
        else {
            t=3*t+1;
            cout<<t<<" ";
        }
    }
    
}