#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool sumtwo(vector<int>& positions, vector<int>& nums, vector<int>& nums_unsort, int n, int x, int i){
    int left = 0, right = n-1;
    while(true){
        if(left == right) break;
        if(nums[left] + nums[right] == x){
            if(left == i) left++;
            else if(right == i) right--;
            else break;
        } else if(nums[left] + nums[right] < x){
            left++;
        } else {
            right--;
        }
    }

    if(left == right) return false;
    else {
        int val1 = nums[left];
        int val2 = nums[right];

        int i1 = 0, i2 = 0, i3 = 0;
        for(i1 = 0; i1 < n; i1++){
            if(nums_unsort[i1] == val1) break;
        }
        for(i2 = 0; i2 < n; i2++){
            if(nums_unsort[i2] == val2 && i2 != i1) break;
        }
        for(i3 = 0; i3 < n; i3++){
            if(nums_unsort[i3] == nums[i] && i3 != i1 && i3 != i2) break;
        }

        positions.push_back(i1 + 1);
        positions.push_back(i2 + 1);
        positions.push_back(i3 + 1);
        sort(positions.begin(), positions.end());

        return true;
    }
}

int main(){
    int n, x;
    cin >> n >> x;
    vector<int> nums(n, 0);
    vector<int> nums_unsort(n, 0);
    for(int i = 0; i < n; i++) {
        cin >> nums[i];
        nums_unsort[i] = nums[i];
    }
    sort(nums.begin(), nums.end());

    vector<int> positions;
    int i = 0;
    for(i = 0; i < n; i++){
        if(sumtwo(positions, nums, nums_unsort, n, x - nums[i], i)) break;
    }
    if(i == n) cout << "IMPOSSIBLE" << endl;
    else cout << positions[0] << " " << positions[1] << " " << positions[2] << endl;
}