/**
 *    Author: Saksham Rathi
 *    Created: Fri Nov 29 16:59:22 IST 2024
**/


#include<iostream>
#include<cmath>
#include<ctime>
#include <iomanip>
#include<numbers>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<unordered_map>
#include<unordered_set>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    int t;
    cin >> t;
    for (int i = 1 ; i <= t ; i ++ ) {
        int n;
        cin >> n;
        vll p(n), q(n);
        for (int i = 0 ; i < n ; i ++) {
            cin >> p[i];
        }
        for (int i = 0 ; i < n ; i ++) {
            cin >> q[i];
        }
        vll d(n);
        ll s= 0;
        for (int i = 0 ; i < n ; i ++) {
            d[i] = p[i] - q[i];
            s += d[i];
        }
        if (s < 0) {
            cout << "Case " << i << ": Not possible" << endl;
            continue;
        }
        int start = 0;
        map<int, bool> tried;
        bool OK = true;
        while (1) {
            // cout << " hello " << start << endl;
            if (tried[start]) {
                break;
            }
            tried[start] = true;
            OK = true;
            int fuel = 0;
            for (int i = 0 ; i < n ; i ++) {
                int next = (start + 1) % n;
                fuel += d[start];
                if (fuel < 0) {
                    start = next;
                    OK = false;
                    break;
                }
                else {
                    start = next;
                }
            }
            if (OK) break;
        }
        if (OK) {
            cout << "Case " << i << ": Possible from station " << start + 1 << endl;
        }
        else {
            cout << "Case " << i << ": Not possible" << endl;
        }
    }
}
