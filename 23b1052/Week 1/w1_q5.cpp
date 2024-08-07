#include<bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n;
    cin >> n;
    cout << n << " ";
    while ( n != 1 ){
        if ( n % 2 == 1 ){
            n = (3*n + 1);
            cout << n << " ";
            n = n / 2;
            cout << n << " ";
        }
        else{
            n = n / 2;
            cout << n << " ";
        }
    }
}