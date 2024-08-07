#include<bits/stdc++.h>
using namespace std ;

typedef int64_t ll ;

// This code is correct but time limit exceed 
ll luckyNumber(ll n){
    ll maxDigit = n%10 , minDigit = n%10;
    if (n/10 == 0) return 0;
    while(n>0){
        if (n%10 > maxDigit) maxDigit = n%10;
        if (n%10 < minDigit) minDigit = n%10;
        n/=10;
        if (maxDigit-minDigit == 9) return 9;
    }
    return maxDigit - minDigit;
}

ll luckynumbermax(ll r, ll l){
    ll LuckiestNum ;  
    int maxLUCK = 0 , currLuck  = 0 ;
    for(ll i =  r ; i<= l ; i++) {
        currLuck = luckyNumber(i);
        if (currLuck >= maxLUCK){
            LuckiestNum = i ;
            maxLUCK = currLuck;
            if(maxLUCK == 9) return i;
        }
    }
    return LuckiestNum ;
}
 

int main(){
    int n;
    cin >> n;
    ll r , l;
    ll arr[n] ;
    for(int i = 0 ; i<n ; i++){
        cin >> r >> l;
        arr[i] = luckynumbermax(r,l);
    }
    for(int i = 0 ; i<n ; i++){
        cout << arr[i] << "\n" ;
    }
    return 0;
}