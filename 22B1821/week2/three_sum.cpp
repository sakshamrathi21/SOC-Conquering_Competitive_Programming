#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
int n;
long x;
cin>>n>>x;


vector<pair<long,int> > sequence(n);
for(int i=0;i<n;i++){
    cin>>sequence[i].first;
    sequence[i].second=i+1;
}
sort(sequence.begin(),sequence.end());
for(int i=0;i<n-2;i++){
    int left=i+1,right=n-1;
while(left<right){
    long target=sequence[left].first+sequence[right].first+sequence[i].first;
    if(target==x){
        cout<<sequence[i].second<<" "<<sequence[left].second<<" "<<sequence[right].second;
        return 0;
    }
    else if(target<x){
        left++;
    }
    else{
        right--;
    }
}
}
cout<<"IMPOSSIBLE";
return 0;
}