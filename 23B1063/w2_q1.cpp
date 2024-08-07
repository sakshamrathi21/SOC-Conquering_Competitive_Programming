#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll solve(ll N, ll* arr)
{
    ll start = 0, result = 0;
    map<ll, ll> mp;

    for (ll end = 0; end < N; end++) {
        if (mp.find(arr[end]) == mp.end())
            mp.insert({ arr[end], end });
        else {
            if (mp[arr[end]] >= start)
                start = mp[arr[end]] + 1;
            mp[arr[end]] = end;
        }
        result = max(result, end - start + 1);
    }
    return result;
}

int main()
{
    ll N;
    cin>>N;
    ll arr[N];
    for(ll i=0;i<N;i++){
	    cin>>arr[i];
    }

    cout << solve(N, arr) << "\n";
}

