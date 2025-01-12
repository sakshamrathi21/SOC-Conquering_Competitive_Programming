/**
 *    Author: Saksham Rathi
 *    Created: Thu Nov 28 12:27:04 IST 2024
**/


#include<iostream>
#include<cmath>
#include<ctime>
#include <iomanip>
#include<numbers>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef long double db;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<db> vdb;
#define MOD 1000000000


int main() {
    int n;
    cin >> n;
    vi vc(n);
    for (int i = 0 ; i < n ; i ++) cin >> vc[i];
    sort(vc.begin(), vc.end());
    cout << vc[0] << " ";
    for (int i = 1 ; i < n ; i ++) if (vc[i] != vc[i-1]) cout << vc[i] << " ";
}
