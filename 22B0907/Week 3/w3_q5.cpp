#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

void func1(int n, vector<long long>& hl, vector<long long>& dhl){
    hl[0] = 1;
    dhl[0] = 1;
    int num = pow(10, 9) + 7;
    for(int i = 1; i < n; i++){
        hl[i] = (4*hl[i-1] + dhl[i-1])%num;
        dhl[i] = (2*dhl[i-1] + hl[i-1])%num;
    }
}

void func2(vector<int> inp, vector<long long>& hl, vector<long long>& dhl){
    for(int i : inp){
        int num = pow(10, 9) + 7;
        cout << (hl[i-1] + dhl[i-1])%num << endl;
    }
}

int main(){
    int t;
    cin >> t;
    vector<int> inp(t, 0);
    for(int i = 0; i < t; i++) cin >> inp[i];
    int mymax = *max_element(inp.begin(), inp.end());
    vector<long long> hl(mymax, 0);
    vector<long long> dhl(mymax, 0);

    func1(mymax, hl, dhl);
    func2(inp, hl, dhl);

    return 0;
}