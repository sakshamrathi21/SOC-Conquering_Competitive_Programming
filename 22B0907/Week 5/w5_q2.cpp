#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
#define ll long long
#define max_n 400001

vector<int> two_pow(max_n, 0);

ll func(int n, vector<int>& inp, int mod){
    vector<ll> prefixsum(n+1, 0);
    for(int i = 0; i < n; i++){
        prefixsum[i+1] = prefixsum[i] + inp[i];
    }
    ll max = -1, temp;
    int max_index = -1; // after adding n th element
    for(int i = 0; i <= n; i++){
        temp = prefixsum[n] - prefixsum[i] + abs(prefixsum[i]);
        if(temp > max){
            max = temp;
            max_index = i;
        }
    }
    if(prefixsum[n] == max) return two_pow[n];
    ll result = 0;
    int memory = 0;
    for(int i = 1; i <= n; i++){
        temp = prefixsum[n] - prefixsum[i] + abs(prefixsum[i]);
        if(temp == max){
            result += two_pow[n-i+memory];
            result %= mod;
        }
        if(prefixsum[i] >= 0) memory++;
    }
    result %= mod;
    return result;
}

int main(){
    int t;
    cin >> t;
    int n;
    two_pow[0] = 1;
    int mod = 998244353;
    for(int i = 1; i < max_n; i++){
        two_pow[i] = two_pow[i-1] * 2;
        two_pow[i] %= mod;
    }
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> inp(n, 0);
        for(int j = 0; j < n; j++){
            cin >> inp[j];
        }
        cout << func(n, inp, mod) << endl;
    }

    return 0;
}