#include<bits/stdc++.h>
using namespace std;

#define REP(n) for(ll g = 0 ; g<n ; g++) 
typedef int64_t ll ;

vector<ll> ClimbTheTree(vector<vector<ll>> events){
    vector<ll> res ;
    ll hLower = 0 , hUpper = 0 ;
    bool FirstTime = 1 ;
    for(auto x : events){
        if(x[0] == 1) {
            ll heightMin , heightMax ;
            if (x[1]>x[2]) {
                ll diff = x[1]-x[2] ,
                daysProvided = x[3] ;
                if(x[3] == 1 ) {
                    heightMin = 1 ; 
                    heightMax = x[1] ;
                }
                else {
                heightMin = (x[3]-1)*(diff) + x[2] + 1 ;
                heightMax = (x[3]-1)*(diff) + x[1] ;
                }
            }
            else{
                ll heightMin = 0 , heightMax = 0 ;
            }

            if(FirstTime) {
                hLower = heightMin ;
                hUpper = heightMax ;
                FirstTime = 0 ;
                res.push_back(1) ;
            }
            else{
                if (heightMax < hLower || hUpper < heightMin ) res.push_back(0) ;
                else { 
                    hUpper = min(hUpper,heightMax) ;
                    hLower = max(hLower,heightMin) ;
                    res.push_back(1) ;
                }
            }
        }
        else {
            if(x[2]>x[1] || (hUpper == 0 && hLower == 0)) res.push_back(-1)  ;
            else {
                if(x[1]>=hUpper) res.push_back(1);
                else if (hLower<=x[1] && hUpper > x[1]) res.push_back(-1) ; 
                else if (hLower > x[1] &&  hUpper > x[1]){
                    ll diff = x[1] - x[2] ,
                    n1 = ((hLower-x[1])/(diff)) + 1 , 
                    n2  = ((hUpper-x[1])/(diff)) + 1 ; 
                    if((hLower-x[1])%diff != 0) n1++ ; 
                    if((hUpper-x[1])%diff != 0) n2 ++ ;
                    if(n2 == n1) res.push_back(n1) ;
                    else res.push_back(-1) ;
                }
            }
        }
    } 
    return res;
}


int main(){
    ll t ;
    cin >> t ;
    vector<vector<ll>> results ;
    while(t--){
        ll q ;
        cin >> q ;
        vector<vector<ll>> events ;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear the input buffer
        while(q--){
            vector<ll> numbers ;
            ll temp ; 
            cin >> temp ;
            if(temp == 1) {
                numbers.push_back(1);
                REP(3) {
                    ll tempo ;
                    cin >> tempo ; 
                    numbers.push_back(tempo) ;
                }
            }
            else {
                numbers.push_back(2);
                REP(2){
                    ll tempo ;
                    cin >> tempo ;
                    numbers.push_back(tempo) ;
                }
            }
            events.push_back(numbers) ;
        }
        vector<ll> answer = ClimbTheTree(events) ;
        results.push_back(answer);
    }
    for(auto x : results) {
        for(auto y : x) cout << y << " " ;
        cout << endl ;
    }
    return 0 ;
}
