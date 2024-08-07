#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int n;
long x;
cin>>n>>x;
int left=0,right=n-1;

vector<pair<long,int> > sequence(n);
for(int i=0;i<n;i++){
    cin>>sequence[i].first;
    sequence[i].second=i+1;
}
sort(sequence.begin(),sequence.end());
while(left<right){
    long target=sequence[left].first+sequence[right].first;
    if(target==x){
        cout<<sequence[left].second<<" "<<sequence[right].second;
        return 0;
    }
    else if(target<x){
        left++;
    }
    else{
        right--;
    }
}
cout<<"IMPOSSIBLE";
return 0;
}