#include<iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int num;

    long long n, k;
    cin >> num;
    for ( int i = 0; i < num; i++) {
        cin >> n;
        cin >> k;
        if ( n % 2 == 0 ) cout << "YES\n";
        else if ( k % 2 == 0 ) cout << "NO\n";
        else if ( k > n ) cout << "NO\n";
        else cout << "YES\n";
    }
}