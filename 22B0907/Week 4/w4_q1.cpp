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

int func(int a, int b, int c){
    int num = mypow(10, 9, INT_MAX) + 7;
    int b_c =  mypow(b, c, num-1);
    return mypow(a, b_c, num);
}

int main(){
    int n;
    cin >> n;
    // vector<int> a(n, 0);
    // vector<int> b(n, 0);
    // vector<int> c(n, 0);
    // for(int i = 0; i < n; i++)
    // cin >> a[i] >> b[i] >> c[i];
    // vector<int> outcomes(n, 0);
    // for(int i = 0; i < n; i++){
    //     outcomes[i] = func(a[i], b[i], c[i]);
    // }
    // for(int i = 0; i < n; i++){
    //     cout << outcomes[i] << endl;
    // }
    int a, b, c;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> c;
        cout << func(a, b, c) << endl;
    }

    return 0;
}