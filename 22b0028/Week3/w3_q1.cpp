#include<bits/stdc++.h>

using namespace std;

bool compare(int* a , int* b){
    return a[0] < b[0];
}

int main(){
    int n;
    cin >> n;

    int** nums = new int*[n];
    for(int i = 0; i < n; i++){
        nums[i] = new int[2];
    }

    for(int i = 0; i < n;i++){
        cin >> nums[i][0] >> nums[i][1];     
    }

    sort(nums,nums+n,compare);
    long long reward = 0;
    long tasktime = 0;

    for(int i = 0; i < n; i++){
        tasktime += nums[i][0];
        reward += nums[i][1] - tasktime;
    }
    cout << reward;



}