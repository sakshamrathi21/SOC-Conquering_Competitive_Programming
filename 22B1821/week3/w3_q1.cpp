#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int n;
cin>>n;
vector< pair<int,int> >task(n);
for(int i=0;i<n;i++){
    cin>>task[i].first;
    cin>>task[i].second;
}
sort(task.begin(),task.end());
long long time=0;
long long total_reward=0;

for(int i=0;i<n;i++){
    long reward=0;
    time+=task[i].first;
    reward=(task[i].second)-time;
    total_reward+=reward;
}
cout<<total_reward;
return 0;
}