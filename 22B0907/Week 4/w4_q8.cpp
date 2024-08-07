#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int mypow(int x, int y, int mod){
    int ret;
    long long temp = 1;
    if(y == 0) return 1;
    if(y == 1) return x;
    temp = mypow(x, y/2, mod);
    if(y % 2 == 0){
        temp = temp * temp;
        ret = temp % mod;
    } else {
        temp = temp * temp;
        temp = temp % mod;
        temp = temp * x;
        ret = temp % mod;
    }
    return ret;
}

int numb(int n, vector<int>& num, vector<int>& pow){
    int mod = mypow(10, 9, INT_MAX) + 7;
    long long temp = 1;
    for(int i = 0; i < n; i++){
        temp = temp * (pow[i] + 1);
        temp = temp % mod;
    }
    return temp;
}

int sumd(int n, vector<int>& num, vector<int>& pow){
    int mod = mypow(10, 9, INT_MAX) + 7;
    long long temp = 1, temp2;
    for(int i = 0; i < n; i++){
        temp2 = mypow(num[i], pow[i]+1, mod) - 1;
        if(temp2 == -1) temp2 = mod-1;
        temp = temp * temp2;
        temp = temp %  mod;
        temp2 = mypow(num[i]-1, mod-2, mod);
        temp = temp * temp2;
        temp = temp % mod;
    }
    return temp;
}

int prodd(int n, vector<int>& num, vector<int>& pow, int numd){
    int mod = mypow(10, 9, INT_MAX) + 7;
    long long temp = 1, temp2 = 1, bigprod = 1;
    bool flag = 1;  // to remember if we have to divide exponent by 2 or not. If flag is 1 ...
       // ... then all exponents are even
    for(int i = 0; i < n; i++){
        if(flag && pow[i] % 2){
            bigprod = bigprod * ((pow[i] + 1)/2);
            flag = 0;
        }
        else bigprod = bigprod * (pow[i] + 1);
        bigprod = bigprod % (mod-1); // mod-1 because it is exponent
    }

    for(int i = 0; i < n; i++){
        if(flag){
            temp2 = temp2 * mypow(num[i], pow[i]/2, mod);
        } else {
            temp2 = temp2 * mypow(num[i], pow[i], mod);
        }
        temp2 = temp2 % mod;
    }

    temp = mypow(temp2, bigprod, mod);
    temp = temp % mod;

    return temp;
}

int main(){
    int n; cin >> n;
    vector<int> num(n, 0), pow(n, 0);
    for(int i = 0; i < n; i++)
    cin >> num[i] >> pow[i];

    int a = numb(n, num, pow);
    int b = sumd(n, num, pow);

    cout << a << " " << b << " " << prodd(n, num, pow, a) << endl;

    return 0;
}