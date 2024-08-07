#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <map>
using namespace std;

int main(){

    int n;
    cin >> n;
    int left = 0;
    int right = 0;
    int maxim = 0;
    vector<int> ids(n, 0);
    map<int, int> pre_ids;

    for(int i = 0; i < n; i++){
        cin >> ids[i];
    }

    while(true){
        if(left == n || right == n) break;
        if(pre_ids.find(ids[left]) != pre_ids.end() && pre_ids.find(ids[right]) != pre_ids.end()){
            pre_ids.erase(ids[left]);
            left++;
        } else {
            pre_ids[ids[right]] = 1;
            right++;
            if((right - left) > maxim) maxim = (right - left);
        }
    }

    if((right - left) > maxim) maxim = (right - left);
    cout << maxim << endl;

    return 0;
}