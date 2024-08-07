#include<bits/stdc++.h>
using namespace std ;

typedef int64_t ll ;

ll MissingNumber(ll * arr , ll n){
    ll sum = 0;
    for(ll i =  0 ; i<n-1 ; i++){
        sum+=arr[i];
    }
    return n*(n+1)/2 - sum ;
}

int main(){
    ll n ;
    cin >> n ;
    ll arr[n] ;
    for(ll i  = 0; i <n-1 ; i++) cin >>arr[i];
    cout << MissingNumber(arr,n);
    return 0;
}