#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    int totalW;
    cin >> n >> totalW;
    
    long* values = new long[n];
    long long* weights = new long long[n];
    int valuesSum = 0;
    for(int i = 0; i < n; i++){
        cin >> weights[i] >> values[i];
        valuesSum += values[i];
    }

    vector<long long> prevRow(valuesSum + 1, 1e15);

    prevRow[0] = 0;

    for(int i = 1; i <= n; i++){
        vector<long long> currRow(valuesSum + 1);
        currRow[0] = 0;
        for(int j = 1; j <= valuesSum; j++){
            if(values[i-1] > j){
                currRow[j] = prevRow[j];
            } else{
                currRow[j] = min(prevRow[j] , prevRow[j-values[i-1]] + weights[i-1]);
            }
        }
        prevRow = currRow;
    }

    int maxVal;
    for(int i = 0; i <= valuesSum;i++){
        if(prevRow[i] <= totalW){
            maxVal = i;
        }
    }

    cout << maxVal;


    return 0;


}