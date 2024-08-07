#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n;
    vll given_numbers;

    // Tried to solve it in O(n) time complexity

    // Taking Input
    cin >> n;
    for (ll i = 0; i < n; i++) {
        ll temp;
        cin >> temp;
        given_numbers.push_back(temp);
    }

    // Vector containing numbers from 1 to n (0 to n-1)
    // 1 at i-1 means i is in input, 0 means i is missing
    vector<bool> numbers(n, 0);
    for (ll i = 0; i < n; i++) {
        numbers[given_numbers[i] - 1] = 1;
    }

    // Output missing number
    for (ll i = 0; i < n; i++) {
        if (numbers[i] == 0) {
            cout << i + 1 << endl;
            break;
        }
    }
}