#include <iostream>
// #include <bits/stdc++.h>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

void func(int n, vector<int>& inp){
    vector<string> binaryform(n, "");
    int max_size = -1;
    int temp;
    for(int i = 0; i < n; i++){
        binaryform[i] = bitset<8>(inp[i]).to_string();
        temp = binaryform[i].size();
        if(temp > max_size) max_size = temp;
    }
    vector<int> noofones(max_size, 0); 
    for(int i = 0; i < n; i++){
        temp = binaryform[i].size();
        for(int j = 0; j < max_size; j++){
            if(temp > j){
                if(binaryform[i][j] == '1'){
                    noofones[j]++;
                }
            } else {
                break;
            }
        }
    }
    for(int i = 0; i < max_size; i++){
        if(noofones[i] % 2){
            cout << "first" << endl;
            return;
        }
    }
    cout << "second" << endl;
}

int main(){
    int t; cin >> t;
    int n;
    for(int i = 0; i < t; i++){
        cin >> n;
        vector<int> inp(n, 0);
        for(int j = 0; j < n; j++) cin >> inp[j];
        func(n ,inp);
    }

    return 0;
}