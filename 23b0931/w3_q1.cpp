#include<bits/stdc++.h>
using namespace std;

// 10 - 

typedef int64_t ll ;

bool customsort(pair<ll,ll> a , pair<ll,ll> b){
    return ( a.first == b.first ?  a.second < b.second : a.first < b.first ) ;
}

ll TandD(vector<pair<ll,ll>> v){
    // deadline - finish
    // finish += duration
    // 6 8 5 
    // 10 15 12
    // 12 - 5 + 
    // reward =  - 6 - 8 - 5 (always)
    // reward =  10-5  + 15-(5+6) + 12-(5+6+8)   
    // reward = 5 + 4 - 7 = 2
    sort(v.begin(),v.end(),customsort) ;
    ll finish = 0 ;
    ll reward = 0 ;
    for ( ll i = 0 ; i < v.size() ; i++) {
        finish += v[i].first ;
        reward += v[i].second - finish ;
    }
    return reward ;
}

int main(){
    vector<pair<ll,ll>> v ;
    ll n , a , b ;
    cin >> n ;
    for( ll i = 0 ; i < n ; i++ ){
        cin >> a >> b ;
        pair<ll,ll> myPair = make_pair(a,b) ;
        v.push_back(myPair) ;
    }
    ll reward = TandD(v) ;
    cout << reward ;
    return 0 ;
}