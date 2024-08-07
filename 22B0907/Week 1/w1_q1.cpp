#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

    int n = 0;
    cin >> n;
    vector<int> temp;
    int i, k;
    for(i = 0; i < n-1; i++){
        cin >> k;
        temp.push_back(k);
    }
    sort(temp.begin(), temp.end());
    for(i = 1; i < n; i++){
        if(temp[i-1] != i) break;
    }

    cout << i << endl;

    return 0;
}