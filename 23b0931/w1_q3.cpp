#include<bits/stdc++.h>
using namespace std ;

typedef int64_t ll ;

bool coins(ll n , ll k){
    if (n%2 == 0) return 1 ;
    else if (k%2==0) return 0;
    else return 1;
}

int main() {
    int numTestCases ;
    cin >> numTestCases ;
    bool v[numTestCases] ;
    for(int i = 0  ; i<numTestCases ; i++){
        ll n , k ;
        cin >> n >> k;
        v[i] = coins(n,k) ;
    }
    
    for(int i = 0 ; i< numTestCases ; i++) v[i] == 1 ? cout << "YES\n" : cout << "NO\n";
    
    return 0;
}
