#include<bits/stdc++.h>
using namespace std;

typedef int64_t ll ;
vector<ll> threesum(vector<ll> v , ll target){
    sort(v.begin(),v.end());
    for(ll p2 = 1 ; p2 < v.size() -1 ; p2 ++){
        ll p1 = 0 , p3 = v.size()-1;
        while(p1<p3){
            if(p1 == p2) p1 ++ ;
            if(p2 == p3) p3 -- ;
            ll sum = v[p1] + v[p3] + v[p2];
            if (sum == target) return {v[p1],v[p2],v[p3]};
            else if (sum < target) p1 ++ ;
            else p3 -- ;
        }
    }
    return {-1};
}

int main(){
    ll n , x ,t ;
    cin >> n >> x ;
    vector<ll> v ;
    while(n--){
        cin >> t ; 
        v.push_back(t);
    }
    vector<ll> res = threesum(v,x);
    vector<bool> use (v.size(),0) ;
    if(res.size() == 1){
        cout << "IMPOSSIBLE" << endl ;
        return 0;
    }
    for(auto x : res) {
        for(ll k = 0 ; k < v.size() ; k++) if (v[k] == x && !use[k]) {
            cout << k+1 << " " ;
            use[k] = 1 ;
            break;
        }
    }
    cout << endl ;
    return 0;
}

