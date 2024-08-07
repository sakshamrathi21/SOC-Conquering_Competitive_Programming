#include <bits/stdc++.h>
#define ll long long
using namespace std;

// function to solve all the static range queries
vector<ll> solve(vector<ll>& arr,
                 vector<vector<ll> >& queries, ll n, ll q)
{
    // Creating a prefix Sum Array
    vector<ll> prefixSum(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        prefixSum[i] = prefixSum[i - 1] + arr[i - 1];
    }

    // Creating Result array to store the result of each
    // query
    vector<ll> result;
    for (auto& query : queries) {
        ll l = query[0], r = query[1];
        ll sum = prefixSum[r] - prefixSum[l - 1];
        result.push_back(sum);
    }
    return result;
}

int main()
{
    // Sample Input
    ll n = 8, q = 4;
    vector<ll> arr = { 3, 2, 4, 5, 1, 1, 5, 3 };
    vector<vector<ll> > queries
        = { { 2, 4 }, { 5, 6 }, { 1, 8 }, { 3, 3 } };
  
    // Function Call
    vector<ll> result = solve(arr, queries, n, q);
    for (ll sum : result) {
        cout << sum << " ";
    }
    cout << endl;
    return 0;
}