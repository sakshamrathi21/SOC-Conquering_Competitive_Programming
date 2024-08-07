#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<long long> vll;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    // Taking Input string
    string s;
    cin >> s;
    ll n = s.length();
    // Stores maximum repeated characters till there
    vll longest_substr(n,1);
    for (ll i = 1; i < n; i++) {
        if (s[i] == s[i-1]) {
            longest_substr[i] = longest_substr[i-1] + 1;
        }
    }

    // Output maximum repeated characters
    // using max_element function of standard C++
    cout << *max_element(longest_substr.begin(), longest_substr.end()) << endl;
}