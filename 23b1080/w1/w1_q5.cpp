#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // Time complexity would depend on n ig, but
    // when it is a power of 2 or becomes a power of 2
    // time complexity is O(log(n))
    ll n;
    cin >> n;
    cout << n << " ";
    while((n&(n-1))!=0) {
        if (n%2==0) {
            n/=2;
            cout << n << " ";
        }
        else {
            n = 3*n+1;
            cout << n << " ";
        }
    }
    while(n!=1) {
        n/=2;
        cout << n << " ";
    }
}