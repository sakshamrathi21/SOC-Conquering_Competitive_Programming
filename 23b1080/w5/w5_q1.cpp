#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

pair<ll, ll> answer(string s) {
    ll n = s.size(), l=0, r=0, lb=0, rb=0, ans=0, count=1;
    while(r<n) {
        if (l==r) {
            if (s[l] == ')') {
                l++; r++; lb = 0; rb = 0;
            }
            else {
                lb = 1; rb = 0;
                r++;
            }
        }

        else {
            if (s[r] == ')') rb++;
            else lb++;

            if (lb > rb) r++;
            else if (lb == rb) {
                ll new_ans = r-l+1;
                if (new_ans > ans) {
                    count = 1;
                    ans = new_ans;
                }
                else if (new_ans == ans) count++;
                r++;
            }
            else if (lb < rb) {
                l = r+1; r = l;
                lb = 0; rb = 0;
            }
        }
    }
    return {ans, count};
}

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s, srev;
    cin >> s;
    ll n = s.size();

    for (ll i=n-1; i>=0; --i) {
        if (s[i] == '(') srev.push_back(')');
        else srev.push_back('(');
    }

    pair<ll, ll> ans = answer(s);
    pair<ll, ll> ansrev = answer(srev);

    auto better = (ans.first > ansrev.first ||
                     (ans.first == ansrev.first && ans.second > ansrev.second))
                      ? ans : ansrev;
    cout << better.first << " " << better.second << "\n";
}