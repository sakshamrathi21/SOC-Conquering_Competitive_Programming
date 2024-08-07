#include<bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    int* nums = new int[n];
    for(int i=0;i<n;i++){
        cin >> nums[i];
    }
    sort(nums,nums+n);
    int median;
    if(n %2 ==0){   
        median = (nums[n/2] + nums[(n/2) - 1]) / 2;
    }
    else{
        median = nums[(n-1)/2];
    }
    long price= 0;
    for(int i=0;i<n;i++){
        price += abs(median-nums[i]);
    }
    cout << price << '\n';

    delete[] nums;
    return 0;
}