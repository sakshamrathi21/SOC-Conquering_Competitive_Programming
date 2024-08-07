#include<bits/stdc++.h>
using namespace std;

vector<int> sieve(int n){
    vector<int> v(n+1,0) ;
    v[0] = 1 ;
    for(int i = 2 ; i <=n ; i++){
        if(v[i]) continue ;
        for(int j = 2*i ; j<= n ; j+=i) v[j] = i;
    }
    return v ;
}

vector<vector<int>> twoDivisors(vector<int> arr){
    vector<int> SOE = sieve(10000000) ;
    vector<vector<int>> res ;     
    for(auto x : arr){
        if(SOE[x] == 0) res.push_back({-1,-1}) ;
        else {
            int d1 = 1;
            int temp = x ;
            while (x % SOE[temp] == 0) {
                d1 *= SOE[temp];
                x /= SOE[temp];
            }
            if (x == 1) res.push_back({-1, -1});
            else res.push_back({d1, x});
        } 
    }
    return res ;
}

int main(){
    
    int n ;
    cin >> n ;

    vector<int> arr(n) ;

    for(int i = 0 ; i < n  ; i++) cin >> arr[i] ;

    vector<vector<int>> res = twoDivisors(arr) ;

    for(auto x : res) cout << x[0] << " " ;
    cout << endl ;
    for(auto x : res) cout << x[1] << " " ;

    return 0 ;

}