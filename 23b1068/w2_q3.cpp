#include<bits/stdc++.h>
using namespace std;



  
   vector<int> maxSlidingWindow(vector<int> arr, int k) {
        deque<int> q;
        vector<int> ans;

        for(int i=0; i<k; i++){
            while(!q.empty() && arr[q.back()]<=arr[i] ){
               // cout << "popped " << q.back();
                q.pop_back();

            }
            q.push_back(i);
             
        }
        ans.push_back(arr[q.front()]);
        for(int i=k; i<arr.size(); i++){
            if(!q.empty() && i-k==q.front()){
                //cout << q.front() << "\n";
                q.pop_front();
            }
            while(!q.empty() && arr[q.back()]<=arr[i] ){
                //cout << q.back() << "\n";
                q.pop_back();
            }
             //cout << "ans " << q.front();
            q.push_back(i);
            ans.push_back(arr[q.front()]);
        }
        return ans;
   }

int main(){
    vector<int> ans = maxSlidingWindow({4,3,11},3);
    for(int i=0; i<ans.size(); i++) cout << ans[i] << ' ';
}