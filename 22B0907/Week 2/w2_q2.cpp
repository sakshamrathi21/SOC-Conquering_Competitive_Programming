#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void myfind(vector<int>& nums, int val1, int val2){
    int i1 = 0, i2 = 0;
    int n = nums.size();
    for(i1 = 0; i1 < n; i1++){
        if(nums[i1] == val1) break;
    }
    for(i2 = 0; i2 < n; i2++){
        if(nums[i2] == val2 && i2 != i1) break;
    }

    cout << (i1 + 1) << " " << (i2 + 1) << endl;
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
    int left = 0, right = n-1;

    while(true){
        if(left == right) break;
        if(nums[left] + nums[right] == x) break;
        if(nums[left] + nums[right] < x){
            left++;
        } else {
            right--;
        }
    }

    if(left == right) cout << "IMPOSSIBLE" << endl;
    else {
        myfind(nums_unsort, nums[left], nums[right]);
    }

    return 0;

}