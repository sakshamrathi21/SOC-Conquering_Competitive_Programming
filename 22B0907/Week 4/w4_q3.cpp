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

void fact(int& num, int size, vector<int>& factvect, vector<int>& invvect){
    long long temp = 1;
    factvect[0] = 1;
    for(int i = 1; i < size; i++){
        temp *= i;
        temp %= num;
        factvect[i] = temp;
    }
    
    invvect[size-1] = mypow(factvect[size-1], num-2, num);
    temp = invvect[size-1];
    for(long long i = size-2; i >= 0; i--){
        temp *= (i+1);
        temp %= num; 
        invvect[i] = temp;
    }
}

// void inv(int& num, int size, vector<int>& fact_vect, vector<int>& invvect){
//     for(int i = 1; i < invvect.size(); i++){
//         invvect[i] =  mypow(fact_vect[i], num-2, num);
//     }
// }

int main(){
    int n;
    cin >> n;
    int num = mypow(10, 9, INT32_MAX) + 7;
    long long temp;
    vector<int> a(n, 0);
    vector<int> b(n, 0);
    int max_fact = 0, max_inv = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        if(a[i] > max_fact) max_fact = a[i];
    }
    vector<int> factvect(max_fact+1, 0);
    vector<int> invvect(max_fact+1, 0);
    fact(num, max_fact+1, factvect, invvect);
    for(int i = 0; i < n; i++){
        temp = factvect[a[i]];
        temp = temp * invvect[b[i]];
        temp = temp % num;
        temp = temp * invvect[a[i] - b[i]];
        temp = temp % num;
        // cout << factvect[a[i]] << " - " << invvect[b[i]] << " - " << invvect[a[i] - b[i]] << endl;
        cout << temp << endl;
    }

    return 0;
}