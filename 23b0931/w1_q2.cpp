#include<bits/stdc++.h>
using namespace std ;

typedef int64_t ll ;
#define REP(n) for(ll i = 0 ; i<n-1 ; i++)  

ll repetations (string s){
    ll bestCount = 1;
    ll currCount = 1;
    REP(s.size()){
        if (s[i] == s[i+1]){
            currCount ++ ;
            bestCount = max(bestCount,currCount); 
        }
        else currCount = 1 ; 
    }
    return bestCount;
}

int main(){
    string s;
    getline(cin,s);
    cout << repetations(s);
    return 0;
}