#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void sol(){
    ll n;
    cin >> n;
    cout << n << ' ';
    while(n!=1){
        if(n%2==1) n = n*3+1;
        else n /= 2;
        cout << n << " ";
    }
}
 
    
 
int main(){
    sol();
    return 0;
}