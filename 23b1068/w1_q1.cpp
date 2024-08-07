#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
void sol(){
    ll n;
    cin >> n;
    ll a[n-1];
    for(int i = 0; i < n-1; i++) {
        cin >> a[i];
    }
    sort(a,a+n);
    for(int i = 0; i < n-1; i++) {
        if(a[i]!=i+1){ cout << i+1; break;}
        if(i==n-2) cout << n;
    }
}
 
    
 
int main(){
    sol();
    return 0;
}