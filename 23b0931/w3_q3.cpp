#include<bits/stdc++.h>
using namespace std;

#define mod 1000000007 ;

typedef int64_t ll ;

void ways(ll & count , vector<ll> dice , ll target , ll & sum ){
    if(sum == target) {
        count ++ ;
        return ;
    }
 
    for(ll i = 0 ; i<dice.size() ; i++){
        sum += dice[i] ;
        if(sum <= target ) ways(count , dice , target , sum) ;
        sum -= dice[i] ;
    }
}

ll counted(ll target){
    vector<ll> dice = {1,2,3,4,5,6};
    ll sum = 0 , count = 0 ;
    ways(count,dice,target,sum);
    return count ;
}

ll recCounted(ll target , vector<ll> & std){
    for(ll i = 7 ; i<= target  ; i++){
        ll temp = 0;
        for(ll j = 0 ; j <6 ; j++){
            temp += std[i-(j+2)]%mod ;  
        }
        std.push_back(temp);
    }
    return std[target-1] ;
}


int main(){
    ll target ; 
    cin >> target ;
    vector<ll> std ;
    for( ll i = 1 ; i <= 6 ; i++) std.push_back(counted(i));
    if(target <= 6 && target > 0 ) cout << std[target-1];
    else if(target <= 0 ) cout << 0;
    else{
        ll ans = recCounted(target,std)%mod ;
        cout << ans ;
    }
    return 0;
}
