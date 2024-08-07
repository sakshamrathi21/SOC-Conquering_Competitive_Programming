#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define endl '\n'

int main()
{

    ll n = 4;

    pair<ll, ll> vertices[n]
        = { { 1, 3 }, { 5, 6 }, { 2, 5 }, { 1, 4 } };

    ll area = 0;

    for (ll i = 0; i < n; i++) {
        area += (vertices[i].first
                    * vertices[(i + 1) % n].second
                - vertices[(i + 1) % n].first
                    * vertices[i].second);
    }

    cout << abs(area);

    return 0;
}