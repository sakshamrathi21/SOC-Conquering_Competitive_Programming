#include<iostream>
#include<vector>
#include <unordered_set>
using namespace std;

int max_seq(const vector<int>&songs){
    unordered_set<int> unique_song;
    int left=0;
    int best=0;
    for(int i=0;i<songs.size();i++){
        while (unique_song.count(songs[i]))
        {
            unique_song.erase(songs[left]);
            left++;
        }
        unique_song.insert(songs[i]);
        best=max(best,i-left+1);
        
    }
    return best;

}
int main(){
int n;
cin>>n;
vector<int>arr(n);

for(int i=0;i<n;i++){
    cin>>arr[i];

}
cout<<max_seq(arr);

return 0;
}