#include<iostream>
#include<cmath>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    db x;
    cin >> x;
    if (x < 10) cout << "  ";
    else if (x < 100) cout << " ";
    cout << fixed << setprecision(3) << x << "\n";
}