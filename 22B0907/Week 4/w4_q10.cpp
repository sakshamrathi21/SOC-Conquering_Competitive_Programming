#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void func(int n, vector<int>& prime){
    prime[0] = 0;
    prime[1] = 0;
    int i = 2, temp;
    while(i < n){
        if(prime[i] == 1){
            temp = (n-1)/i;
            for(int j = 2; j <= temp; j++){
                if(prime[i * j] == 1) prime[i * j] = i;
                else{
                    if(i < prime[i * j]) prime[i * j] = i;
                }
            }
        }
        i++;
    }
}

void func2(vector<int>& prime, vector<int>& res1, vector<int>& res2, vector<int>& inp, int i){
    if(prime[inp[i]] == 1) return;
    int temp = prime[inp[i]];
    int temp2 = inp[i]/temp;
    while(temp2%temp == 0) temp2 /= temp;
    if(temp2 == 1) return;
    res1[i] = temp;
    res2[i] = temp2;
}

int main(){
    int n;
    cin >> n;
    vector<int> inp(n, 0);
    for(int i = 0; i < n; i++) cin >> inp[i];
    int maxval = *max_element(inp.begin(), inp.end());

    vector<int> prime(maxval+1, 1);

    func(maxval+1, prime);

    vector<int> res1(n, 0);
    vector<int> res2(n, 0);

    for(int i = 0; i < n; i++){
        res1[i] = -1;
        res2[i] = -1;
        func2(prime, res1, res2, inp, i);
    }

    for(int i = 0; i < n; i++){
        cout << res1[i] << " ";
    }
    cout << endl;

    for(int i = 0; i < n; i++){
        cout << res2[i] << " ";
    }
    cout << endl;

    return 0;
}