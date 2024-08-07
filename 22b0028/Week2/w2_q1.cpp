#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n == 0){
        cout<<0;
        return 0;
    }
    int* arr = new int[n];
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    set<int> nums;
    int maxLength = 1;

    int ptr1 = 0;
    int ptr2 = 1;
    nums.insert(arr[0]);
    while(ptr2<n){
        while(nums.count(arr[ptr2])==1){
            nums.erase(arr[ptr1]);
            ptr1++;
        }
        nums.insert(arr[ptr2]);
        ptr2++;
        maxLength = max(maxLength,(int)nums.size());
    }
    maxLength = max(maxLength, (int)nums.size());
    cout << maxLength;


    delete[] arr;
    return 0;
}
