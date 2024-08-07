#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


// 8 3
// 3 2 3
// 2 3 3
// 5 + 3 
// 8 + 5  = 13 
// 10 4 
// 1 2 3 4
// 3 + 6 + 10 = 19 
// 3 + 3 + 4 
// 6 + 4 
// 10 
// 10 10 
// 1 1 1 1 1 1 1 1 1 1 , c = 10+ 14 + 10 = 34
// 2 + 1+ .. + 1
// 4 + 6
//  
ll cost(ll l , ll n , vector<ll> pieces){
    multiset<ll> piecesSet(pieces.begin(),pieces.end());
    ll cost = 0 , currLen ;   
    while(currLen != l){
        currLen = 0;
        auto it = piecesSet.begin();
        ll first = *it; 
        it = piecesSet.erase(it); 
        ll second = *it; 
        piecesSet.erase(it);
        cost += (first + second) ;
        currLen = first + second ;
        piecesSet.insert(first+second);
        n-- ;
    }
    return cost ;
}   

int main(){
    ll x , n , temp ;
    cin >> x >> n;
    vector<ll> v;
    while(n--){
        cin>>temp;
        v.push_back(temp);
    }
    cout << cost(x,n,v) ;
    return 0;
}