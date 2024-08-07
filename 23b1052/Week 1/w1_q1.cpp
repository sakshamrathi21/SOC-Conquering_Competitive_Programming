#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    long long sum = ( n * ( n+1 ) / 2), x;
    for ( long long i = 1; i < n; i++){
        cin >> x;
        sum = sum - x;
    }
    cout << sum;
}