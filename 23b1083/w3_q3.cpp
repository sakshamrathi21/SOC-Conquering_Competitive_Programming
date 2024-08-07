/**
 *    Author: Jigyasa Chouhan
 *    Created: Tue Jun 18 17:46:05 IST 2024
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
    ll N = pow(10,9) + 7;
    ll n; cin>>n;
    vll count(n+1, 0);
    count[0] = 1;
    vll dice = {1,2,3,4,5,6};
    for(ll i=0; i<=n; i++){
        for(auto x: dice){
            if(i-x>=0){
                count[i] += count[i-x];
                count[i] = count[i] % N;
            }  
        }
    }   
    cout<<count[n]<<"\n";
}

