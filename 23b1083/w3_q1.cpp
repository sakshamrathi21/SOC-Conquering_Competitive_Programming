/**
 *    Author: Jigyasa Chouhan
 *    Created: Sun Jun 16 19:17:57 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back

int main(){
    ios_base::sync_with_stdio(false);					
    cin.tie(NULL);
    cout.tie(NULL);
    ll n; cin>>n;
    multimap<ll, ll> tasks;
    for(ll i=0; i<n; i++){
        ll a,d;
        cin>>a>>d;
        tasks.insert({a,d});
    }
    
    ll time = 0;
    ll score = 0;
    for(auto x: tasks){
        // cout<<x.first<<" "<<x.second<<"\n";
        time = time + x.first;
        score = score + x.second - time;
    }
    cout<<score;

}

