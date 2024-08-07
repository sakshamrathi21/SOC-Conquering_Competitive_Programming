/**
 *    Author: Jigyasa Chouhan
 *    Created: Mon Jul  1 01:39:36 IST 2024
**/


#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define vll vector<ll>
#define pb push_back

ll N = pow(10,9) + 7;
ll powmod(ll x, ll n, ll m){
    if(n==0) return 1;
    ll half = n/2;
    ll u = powmod(x, half, m);
    u = (u*u)%m;
    if(n%2) u = (u*x)%m;
    return u; 
}

ll sigma(ll n){
    if(n==1) return 1;
    vll div;
    for(ll i=2; i*i<=n; i++){
        while(n%i==0){
            div.push_back(i);
            n = n/i;
        }
    }
    if(n>1) div.push_back(n);
    map<ll, ll> mp;
    for(auto x: div){
        if(mp.find(x)==mp.end()){
            mp.insert({x, 1});
        }
        else{
            mp[x]++;
        }
    }
    ll ans = 1;
    for(auto x: mp){
        ll p = x.first;
        ll alpha = x.second;
        // cout<<p<<" "<<alpha<<endl;
        ll sum = 0;
        for(ll i=0; i<=alpha; i++){
            sum = sum + powmod(p, i, N);
            sum = sum%N;
        }
        // cout<<sum<<endl;
        ans = (ans*sum)%N;
    }
    return ans;
}

const int MOD = 1e9 + 7;
const int TWO_MOD_INV = 500000004;

/** @return The sum of all numbers in [start, end] mod MOD. */
long long total_sum(long long start, long long end) {
	return ((((end - start + 1) % MOD) * ((start + end) % MOD) % MOD) *
	        TWO_MOD_INV % MOD);
}

int main() {
	long long n;
	std::cin >> n;

	long long total = 0;
	long long at = 1;
	while (at <= n) {
		long long add_amt = n / at;  // Our divisor to process
		// The largest number that still has the same value of q
		long long last_same = n / add_amt;

		total = (total + add_amt * total_sum(at, last_same)) % MOD;
		at = last_same + 1;
	}

	cout << total << endl;
}

