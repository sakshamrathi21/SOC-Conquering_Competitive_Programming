#include <bits/stdc++.h>
#define ll long long int
using namespace std;
 
ll countDigits(ll number) {
    if (number == 0) {
        return 1; // Special case for zero
    }
    if (number < 0) {
        number = -number; // Make the number positive if it is negative
    }
    return static_cast<ll>(log10(number)) + 1;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int TestCases;
    cin >> TestCases;
    while (TestCases--) {
        ll x;
        cin >> x;
        ll digits=countDigits(x);
            bool flag=false;
            ll temp=x;
         for (int i = digits - 1; i >= 0; i--) {
        ll di = temp % 10;
        if(i==(digits-1)) {
            if(di==9){ flag=true; break; }
        }
        if(i==0) {
            if(di!=1){ flag=true; break; }
        }
        if(i!=0 && i!=(digits-1)) {
            if(di==0){ flag=true; break; }
        }
 
        temp /= 10;
    }
    if(flag) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
 
    }
    return 0;
}