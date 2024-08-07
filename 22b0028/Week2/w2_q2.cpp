#include<bits/stdc++.h>

using namespace std;


bool compare(int* a , int* b){
    return a[0]<b[0];
}

int main(){
    int n,target;
    cin >>n>>target;
    int** nums = new int*[n];
    for(int i=0;i<n;i++){
        nums[i] = new int[2];
    }
    for(int i=0;i<n;i++){
        cin >> nums[i][0];
        nums[i][1] = i;
        
    }
    sort(nums,nums+n,compare);
    bool found = false;
            int ptr1 = 0;
            int ptr2 = n-1;
            while(ptr1<ptr2){
                int sum = nums[ptr1][0] + nums[ptr2][0];
                if(sum == target){
                   cout<< (nums[ptr1][1]+1) <<" "<<(nums[ptr2][1]+1);
                    found = true;
                    break;
                }
                else if(sum>target) ptr2--;
                else ptr1++;
            }
            if(!found) cout<<("IMPOSSIBLE");

    for(int i=0;i<n;i++){
        delete[] nums[i];
    }
    delete[] nums;
    return 0;

}