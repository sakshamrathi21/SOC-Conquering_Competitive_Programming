#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll ;

ll sticks(vector<ll> v){
    sort(v.begin(),v.end());
    if (v.size()%2 != 0) {
        ll median = v[(v.size()-1)/2] ;
        ll sum = 0 ;
        for(ll i = 0 ; i < v.size() ; i++) sum += abs(v[i]- median) ;
        return sum ;
    } 
    else {
        ll currstick1 = 0 , currstick2 = 0 ;
        for(ll i = 0 ; i < v.size() ; i++) currstick1 += abs(v[i]- v[(v.size()-1)/2]) ;
        for(ll i = 0 ; i < v.size() ; i++) currstick2 += abs(v[i]- v[1+((v.size()-1)/2)]) ;
        return max(currstick1,currstick2);
    }
}
 
int main(){
    ll n , temp ;
    cin >> n ;
    vector<ll> v ;
    while(n--) {
        cin >> temp ;
        v.push_back(temp);
    }
    cout << sticks(v);
    return 0; 
}