#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int mypow(int a, int b, int mod){
    if(b == 0) return 1;
    if(b == 1) return a;
    long long temp =  mypow(a, b/2, mod);
    temp = temp * temp;
    temp = temp % mod;
    if(b%2 != 0){
        temp = temp * a;
        temp = temp % mod;
    }
    int ret = temp % mod;
    return temp;
}

void precompute(int n, int num, vector<int>& fact, vector<int>& invfact){
    fact[0] = 1;
    long long temp = 1;
    for(int i = 1; i <= n; i++){
        temp = fact[i-1];
        temp = temp * (i);
        fact[i] = temp % num;
    }

    temp = mypow(fact[n], num-2, num);
    invfact[n] = temp % num;
    // cout << invfact[n] << endl;
    long long temp2;
    for(int i = n-1; i >= 0; i--){
        temp2 = (i+1);
        temp = (invfact[i+1] * temp2);
        invfact[i] = temp % num;
        // cout << invfact[i] << endl;
    }
}

int nCr(int n, int r){
    int num = mypow(10, 9, INT32_MAX) + 7;

    vector<int> fact(n+1, 0);
    vector<int> invfact(n+1, 0);
    precompute(n, num, fact, invfact);
    long long temp = (fact[n]);
    temp = temp *(invfact[n-r]);
    // cout << fact[n] << endl;
    // cout << invfact[n-r] << endl;
    // cout << invfact[r] << endl;
    temp = temp % num;
    temp = temp * invfact[r];
    int ret = temp % num;
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;

    cout << nCr(n+m-1, m) << endl;

    return 0;
}