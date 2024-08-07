#include<bits/stdc++.h>

using namespace std;

int main(){
    int t;
    cin >> t;

    int* nums = new int[2001];
        nums[0] = nums[1] = nums[2] = 0;
        unordered_set<int> set;
        for(int i = 3; i < 2001; i++){
            
            for(int j = 1; i-j > j; j++){
                set.insert(nums[i-j]^nums[j]);
            }
            int k = 0;
            while(set.find(k) != set.end()){
                k++;
            }

            nums[i] = k;
            set.clear();
        }
        
    while(t-- > 0){
        int n;
        cin >> n;
        if(n > 2000){
            cout << "first" << "\n";
        } else{
            if(nums[n] == 0){
                cout <<"second" << "\n";
            }
            else{
                cout << "first" << "\n";
            }
        }
        
    }
}