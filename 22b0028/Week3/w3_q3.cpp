#include<bits/stdc++.h>

using namespace std;

int main(){

    int n;
    cin >> n;
    long arr[n+1] = {0};
    

    arr[0] = 1;
    for(int i = 0; i <= n; i++){
    }
    long MOD = 1e9 + 7;
    for(int i = 1; i <= n; i++){
            
        for(int j = 1; j <= 6; j++){
            if(i - j >= 0 ){
                arr[i] += arr[i - j];
                arr[i] %= MOD;
                
            }
        }
    }
    cout << arr[n];

}